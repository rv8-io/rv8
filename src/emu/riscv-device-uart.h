//
//  riscv-device-uart.h
//

#ifndef riscv_device_uart_h
#define riscv_device_uart_h

namespace riscv {

	/* UART MMIO device */

	template <typename P>
	struct uart_mmio_device : memory_segment<typename P::ux>
	{
		typedef typename P::ux UX;

		P &proc;

		/* TODO - implement UART state */

		uart_mmio_device(P &proc, UX mpa) :
			memory_segment<UX>(mpa, /*uva*/0, /*size*/0x1000,
				pma_type_io | pma_prot_read | pma_prot_write), proc(proc) {}

		void load_8 (UX va, u8  &val) { printf("uart_mmio:0x%04llx -> 0\n", addr_t(va)); val = 0; }
		void load_16(UX va, u16 &val) { printf("uart_mmio:0x%04llx -> 0\n", addr_t(va)); val = 0; }
		void load_32(UX va, u32 &val) { printf("uart_mmio:0x%04llx -> 0\n", addr_t(va)); val = 0; }
		void load_64(UX va, u64 &val) { printf("uart_mmio:0x%04llx -> 0\n", addr_t(va)); val = 0; }

		void store_8 (UX va, u8  val) { printf("uart_mmio:0x%04llx <- 0x%02hhx\n", addr_t(va), val); }
		void store_16(UX va, u16 val) { printf("uart_mmio:0x%04llx <- 0x%04hx\n", addr_t(va), val); }
		void store_32(UX va, u32 val) { printf("uart_mmio:0x%04llx <- 0x%04x\n", addr_t(va), val); }
		void store_64(UX va, u64 val) { printf("uart_mmio:0x%04llx <- 0x%016llx\n", addr_t(va), val); }
	};

}

#endif