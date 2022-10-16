__asm__(R"(
	.section	.text$_Z6printfPKcz,"x"
	.linkonce discard
	.globl	_Z6printfPKcz
	.def	_Z6printfPKcz;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z6printfPKcz
_Z6printfPKcz:
.LFB11:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rdx, 24(%rbp)
	leaq	24(%rbp), %rdx
	movq	%r8, 32(%rbp)
	movq	%r9, 40(%rbp)
	movq	%rdx, -8(%rbp)
	call	__mingw_vprintf
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
.lcomm _ZStL8__ioinit,1,1
	.text
	.globl	_Z4readv
	.def	_Z4readv;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z4readv
_Z4readv:
.LFB3630:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$40, %rsp
	.seh_stackalloc	40
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.seh_endprologue
	xorl	%esi, %esi
	call	getchar
	movsbl	%al, %edx
	movsbl	%al, %eax
	subl	$48, %eax
	cmpl	$9, %eax
	jbe	.L6
.L4:
	xorl	%eax, %eax
	cmpb	$45, %dl
	sete	%al
	orl	%eax, %esi
	call	getchar
	movsbl	%al, %edx
	movsbl	%al, %eax
	subl	$48, %eax
	cmpl	$9, %eax
	ja	.L4
	movl	%esi, %edi
	negl	%edi
.L3:
	xorl	%ebx, %ebx
.L5:
	leal	(%rbx,%rbx,4), %eax
	leal	-48(%rdx,%rax,2), %ebx
	call	getchar
	movsbl	%al, %edx
	movsbl	%al, %eax
	subl	$48, %eax
	cmpl	$9, %eax
	jbe	.L5
	xorl	%edi, %ebx
	leal	(%rbx,%rsi), %eax
	addq	$40, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	ret
.L6:
	xorl	%edi, %edi
	jmp	.L3
	.seh_endproc
	.globl	ANS
	.bss
	.align 64
ANS:
	.space 800020
	.globl	fre
	.align 64
fre:
	.space 800020
	.globl	a
	.align 64
a:
	.space 800020
	.globl	b
	.align 64
b:
	.space 800020
	.globl	fuck
	.align 64
fuck:
	.space 800020
	.globl	n
	.align 4
n:
	.space 4
	.globl	m
	.align 4
m:
	.space 4
	.section .rdata,"dr"
.LC0:
	.ascii "%d %d\12\0"
	.text
	.globl	_Z5solvev
	.def	_Z5solvev;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z5solvev
_Z5solvev:
.LFB3633:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%r15
	.seh_pushreg	%r15
	pushq	%r14
	.seh_pushreg	%r14
	pushq	%r13
	.seh_pushreg	%r13
	pushq	%r12
	.seh_pushreg	%r12
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$88, %rsp
	.seh_stackalloc	88
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.seh_endprologue
	call	_Z4readv
	movl	%eax, n(%rip)
	call	_Z4readv
	movl	n(%rip), %edx
	movl	%eax, m(%rip)
	testl	%edx, %edx
	jle	.L22
	leaq	-56(%rbp), %rax
	leaq	4+a(%rip), %rsi
	leaq	4+ANS(%rip), %rdi
	xorl	%r15d, %r15d
	movq	$0, -88(%rbp)
	movq	$0, -96(%rbp)
	movq	%rax, -72(%rbp)
	leaq	-64(%rbp), %rax
	movq	%rax, -80(%rbp)
.L15:
	call	_Z4readv
	movl	%eax, (%rsi)
	call	_Z4readv
	movl	%eax, %ebx
	leaq	4+b(%rip), %rax
	movl	(%rsi), %r13d
	movl	m(%rip), %r12d
	movq	-72(%rbp), %rdx
	movl	%ebx, (%rax,%r15,4)
	leaq	4+fuck(%rip), %rax
	movq	-80(%rbp), %rcx
	movl	$0, -64(%rbp)
	movl	%r12d, (%rax,%r15,4)
	leal	(%rbx,%r13), %eax
	subl	%r12d, %ebx
	subl	%r12d, %eax
	cltq
	addq	%rax, -96(%rbp)
	movl	%r13d, %eax
	subl	%r12d, %eax
	movl	%eax, -56(%rbp)
	call	_ZSt3maxIiERKT_S2_S2_
	movq	-72(%rbp), %rdx
	leal	0(%r13,%rbx), %r11d
	movq	%rsi, %rcx
	movl	(%rax), %r14d
	addq	$4, %rsi
	movl	%r11d, -56(%rbp)
	call	_ZSt3minIiERKT_S2_S2_
	movl	(%rax), %eax
	leaq	4+fre(%rip), %rcx
	movl	n(%rip), %r9d
	movslq	%r14d, %rdx
	movl	%r14d, (%rdi,%r15,4)
	addq	%rdx, -88(%rbp)
	subl	%r14d, %eax
	movl	%eax, (%rcx,%r15,4)
	leal	2(%r15), %eax
	addq	$1, %r15
	cmpl	%eax, %r9d
	jge	.L15
	movq	-88(%rbp), %rbx
	testl	%r9d, %r9d
	movq	%rbx, %r14
	jle	.L29
	movq	-96(%rbp), %rsi
	movq	%rsi, %rax
	shrq	$63, %rax
	addq	%rsi, %rax
	xorl	%esi, %esi
	sarq	%rax
	cmpq	%rax, -88(%rbp)
	movq	%rax, %r12
	jle	.L24
	jmp	.L30
.L19:
	addq	$1, %rsi
	cmpq	%r12, %rbx
	jg	.L28
.L24:
	leaq	4+fre(%rip), %rax
	movq	-72(%rbp), %rdx
	movq	-80(%rbp), %rcx
	movl	%r9d, -88(%rbp)
	movslq	(%rax,%rsi,4), %rax
	movq	%rax, %r14
	movq	%rax, -56(%rbp)
	movq	%r12, %rax
	subq	%rbx, %rax
	movq	%rax, -64(%rbp)
	call	_ZSt3minIxERKT_S2_S2_
	movq	(%rax), %rax
	movl	-88(%rbp), %r9d
	leaq	4+fre(%rip), %rdx
	addl	%eax, (%rdi,%rsi,4)
	subl	%eax, %r14d
	addq	%rax, %rbx
	leal	2(%rsi), %eax
	movl	%r14d, (%rdx,%rsi,4)
	cmpl	%r9d, %eax
	jle	.L19
.L28:
	movq	-96(%rbp), %rax
	negq	%rbx
	leaq	(%rax,%rbx,2), %rcx
	movq	%rcx, %rax
	sarq	$63, %rax
	xorq	%rax, %rcx
	subq	%rax, %rcx
.L14:
	movl	$10, %edx
	call	_Z5printIxEvT_c
	movl	n(%rip), %eax
	testl	%eax, %eax
	jle	.L13
	leaq	4+a(%rip), %rsi
	leaq	4+ANS(%rip), %rdi
	xorl	%ebx, %ebx
.L20:
	movl	(%rdi,%rbx,4), %eax
	movl	(%rsi,%rbx,4), %edx
	leaq	.LC0(%rip), %rcx
	movl	%eax, %r8d
	subl	%edx, %r8d
	addl	m(%rip), %r8d
	subl	%eax, %edx
	call	_Z6printfPKcz
	leal	2(%rbx), %eax
	addq	$1, %rbx
	cmpl	n(%rip), %eax
	jle	.L20
.L13:
	addq	$88, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	ret
.L30:
	movq	-88(%rbp), %r14
.L29:
	movq	-96(%rbp), %rax
	negq	%r14
	leaq	(%rax,%r14,2), %rcx
	movq	%rcx, %rax
	sarq	$63, %rax
	xorq	%rax, %rcx
	subq	%rax, %rcx
	jmp	.L14
.L22:
	xorl	%ecx, %ecx
	jmp	.L14
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section	.text.startup,"x"
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB3634:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$40, %rsp
	.seh_stackalloc	40
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.seh_endprologue
	call	__main
	call	_Z4readv
	testl	%eax, %eax
	movl	%eax, %ebx
	je	.L37
.L35:
	call	_Z5solvev
	subl	$1, %ebx
	jne	.L35
.L37:
	xorl	%eax, %eax
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZSt3maxIiERKT_S2_S2_,"x"
	.linkonce discard
	.globl	_ZSt3maxIiERKT_S2_S2_
	.def	_ZSt3maxIiERKT_S2_S2_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt3maxIiERKT_S2_S2_
_ZSt3maxIiERKT_S2_S2_:
.LFB3645:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movl	(%rdx), %eax
	cmpl	%eax, (%rcx)
	movq	%rcx, %rax
	cmovl	%rdx, %rax
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZSt3minIiERKT_S2_S2_,"x"
	.linkonce discard
	.globl	_ZSt3minIiERKT_S2_S2_
	.def	_ZSt3minIiERKT_S2_S2_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt3minIiERKT_S2_S2_
_ZSt3minIiERKT_S2_S2_:
.LFB3646:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movl	(%rcx), %eax
	cmpl	%eax, (%rdx)
	movq	%rcx, %rax
	cmovl	%rdx, %rax
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZSt3minIxERKT_S2_S2_,"x"
	.linkonce discard
	.globl	_ZSt3minIxERKT_S2_S2_
	.def	_ZSt3minIxERKT_S2_S2_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt3minIxERKT_S2_S2_
_ZSt3minIxERKT_S2_S2_:
.LFB3647:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	(%rcx), %rax
	cmpq	%rax, (%rdx)
	movq	%rcx, %rax
	cmovl	%rdx, %rax
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_Z5printIxEvT_c,"x"
	.linkonce discard
	.globl	_Z5printIxEvT_c
	.def	_Z5printIxEvT_c;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z5printIxEvT_c
_Z5printIxEvT_c:
.LFB3648:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$40, %rsp
	.seh_stackalloc	40
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.seh_endprologue
	movl	%edx, %ebx
	call	_Z5printIxEvT_
	movsbl	%bl, %ecx
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	jmp	putchar
	.seh_endproc
	.section	.text$_Z5printIxEvT_,"x"
	.linkonce discard
	.globl	_Z5printIxEvT_
	.def	_Z5printIxEvT_;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z5printIxEvT_
_Z5printIxEvT_:
.LFB3654:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$40, %rsp
	.seh_stackalloc	40
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.seh_endprologue
	testq	%rcx, %rcx
	movq	%rcx, %rbx
	js	.L51
.L49:
	cmpq	$9, %rbx
	jle	.L50
	movq	%rbx, %rax
	movabsq	$7378697629483820647, %rdx
	imulq	%rdx
	movq	%rbx, %rax
	sarq	$63, %rax
	sarq	$2, %rdx
	movq	%rdx, %rcx
	subq	%rax, %rcx
	call	_Z5printIxEvT_
.L50:
	movq	%rbx, %rax
	movabsq	$7378697629483820647, %rdx
	imulq	%rdx
	movq	%rbx, %rax
	sarq	$63, %rax
	sarq	$2, %rdx
	subq	%rax, %rdx
	leaq	(%rdx,%rdx,4), %rax
	addq	%rax, %rax
	subq	%rax, %rbx
	leal	48(%rbx), %ecx
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	jmp	putchar
.L51:
	movl	$45, %ecx
	negq	%rbx
	call	putchar
	jmp	.L49
	.seh_endproc
	.text
	.def	__tcf_0;	.scl	3;	.type	32;	.endef
	.seh_proc	__tcf_0
__tcf_0:
.LFB3658:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	leaq	_ZStL8__ioinit(%rip), %rcx
	call	_ZNSt8ios_base4InitD1Ev
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	_Z41__static_initialization_and_destruction_0ii;	.scl	3;	.type	32;	.endef
	.seh_proc	_Z41__static_initialization_and_destruction_0ii
_Z41__static_initialization_and_destruction_0ii:
.LFB3657:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	%edx, 24(%rbp)
	cmpl	$1, 16(%rbp)
	jne	.L53
	cmpl	$65535, 24(%rbp)
	jne	.L53
	leaq	_ZStL8__ioinit(%rip), %rcx
	call	_ZNSt8ios_base4InitC1Ev
	leaq	__tcf_0(%rip), %rcx
	call	atexit
	nop
.L53:
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
	.align 4
_ZL1N:
	.long	200005
	.text
	.def	_GLOBAL__sub_I__Z4readv;	.scl	3;	.type	32;	.endef
	.seh_proc	_GLOBAL__sub_I__Z4readv
_GLOBAL__sub_I__Z4readv:
.LFB3659:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movl	$65535, %edx
	movl	$1, %ecx
	call	_Z41__static_initialization_and_destruction_0ii
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.ctors,"w"
	.align 8
	.quad	_GLOBAL__sub_I__Z4readv
	.ident	"GCC: (tdm64-1) 4.9.2"
	.def	__mingw_vprintf;	.scl	2;	.type	32;	.endef
	.def	getchar;	.scl	2;	.type	32;	.endef
	.def	putchar;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	atexit;	.scl	2;	.type	32;	.endef
)");