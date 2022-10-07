#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
int read(){
	register int x = 0;
	register char f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = 0;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
#define N 500005
int n, m, a[N], b[N];
long long sum, c[N], ans = 0x3f3f3f3f3f3f3f3fll;
int main(){
	n = read(), m = read();
	for (register int i = 1; i <= n; ++i) sum += a[i] = read();
	for (register int i = 1; i <= n; ++i) b[i] = read();
	for (register int i = 1; i <= n; ++i) c[i] = b[i] - a[i] + 1ll * m * (n - i);
	std :: sort(c + 1, c + 1 + n), ans = sum;
	for (register int i = 1; i <= n; ++i)
		sum = sum + c[i] - 1ll * (i - 1) * m, ans = std :: min(ans, sum);
	printf("%lld", ans);
}