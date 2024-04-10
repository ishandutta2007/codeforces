#include <cstdio>
#include <cstring>
int n, s0, s1;
char a[100005];
int main(){
	scanf("%d%s", &n, a + 1);
	for (register int i = 1; i <= n; ++i)
		s0 += a[i] == 'z', s1 += a[i] == 'n';
	for (register int i = 1; i <= s1; ++i) putchar('1'), putchar(' ');
	for (register int i = 1; i <= s0; ++i) putchar('0'), putchar(' ');
}