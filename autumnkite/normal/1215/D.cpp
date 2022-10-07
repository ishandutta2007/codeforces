#include <cstdio>
int n, sl, sr, nl, nr;
char a[200005];
int main(){
	scanf("%d%s", &n, a + 1);
	for (register int i = 1; i <= (n >> 1); ++i)
		if (a[i] == '?') ++nl; else sl += a[i] ^ '0';
	for (register int i = (n >> 1) + 1; i <= n; ++i)
		if (a[i] == '?') ++nr; else sr += a[i] ^ '0';
	if ((nl - nr) / 2 * 9 == sr - sl) puts("Bicarp");
	else puts("Monocarp");
}