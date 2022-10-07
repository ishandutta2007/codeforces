#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
int read(){
	register int x = 0;
	register char ch = getchar(), f = 1;
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = !f;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
#define N 1005
int n, l, r, a[N], sum;
int main(){
	n = read(), l = read(), r = read();
	a[1] = 1 << (l - 1);
	for (register int i = 2; i <= n; ++i)
		if (a[i - 1] == 1) a[i] = 1; else a[i] = a[i - 1] >> 1;
	for (register int i = 1; i <= n; ++i) sum += a[i];
	printf("%d ", sum);
	sum = 0, a[1] = 1;
	for (register int i = 2; i <= n; ++i)
		if (a[i - 1] == (1 << (r - 1))) a[i] = a[i - 1]; else a[i] = a[i - 1] << 1;
	for (register int i = 1; i <= n; ++i) sum += a[i];
	printf("%d\n", sum);
}