#include <bits/stdc++.h>
typedef long long LL;
const int N = 300005;
int T, n, m, k[N], c[N];
LL d[N], e[N];
int main() {
	for (scanf("%d", &T); T; T--) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) scanf("%d", &k[i]);
		std::sort(k+1, k+n+1);
		d[0] = e[0] = 0;
		for (int i = 1; i <= m; i++) scanf("%d", &c[i]), d[i] = d[i-1] + c[i];
		for (int i = 1; i <= n; i++) e[i] = e[i-1] + c[k[i]];
		LL ans = 1LL<<60;
		for (int i = k[n]; ~i; i--) {
			ans = std::min(ans, d[i] + e[n-i]);
		}
		printf("%lld\n", ans);
	}
	return 0;
}