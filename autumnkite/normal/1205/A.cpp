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
#define N 200005
int n, a[N];
int main(){
	n = read();
	if (!(n & 1)) return printf("NO\n"), 0;
	printf("YES\n");
	for (register int i = 1; i <= n; ++i) a[i] = 2 * i - 1;
	for (register int i = 1; i <= n; ++i) a[n + i] = 2 * i;
	for (register int i = 2; i <= n; i += 2) std :: swap(a[i], a[n + i]);
	for (register int i = 1; i <= (n << 1); ++i) printf("%d ", a[i]);
}