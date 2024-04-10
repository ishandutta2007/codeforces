#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
int read(){
	register int x = 0;
	register char f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f ^= 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
#define N 200005
int n, m, k;
long long ta, tb, a[N], b[N], ans;
int main(){
	n = read(), m = read(), ta = read(), tb = read(), k = read();
	if (k >= n || k >= m) return printf("-1"), 0;
	for (register int i = 1; i <= n; ++i) a[i] = read() + ta;
	for (register int i = 1; i <= m; ++i) b[i] = read();
	for (register int i = 1; i <= k + 1; ++i){
		int x = std :: lower_bound(b + 1, b + 1 + m, a[i]) - b;
		if (x + k - i + 1 > m) return printf("-1"), 0;
		ans = std :: max(ans, b[x + k - i + 1] + tb);
	}
	printf("%lld", ans);
}