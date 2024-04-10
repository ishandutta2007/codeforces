///
///   Oh? You're approaching me?
///

#pragma GCC optimize("O0")
#include <stdio.h>

char s[] = "YES\n\0NO\n";
asm("code: .ascii \"\\211\\3021\\300\\366\\302\\001u\\006\\200\\372\\002t\\001\\303\\004\\005\\303\"");

int main()
{
	int x;
	scanf("%d", &x);
	asm("call code" : "=a"(x) : "a"(x));
	printf(s+x);
}