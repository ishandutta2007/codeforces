#include <bits/stdc++.h>
typedef long long LL;
const int N = 100005;
int T, n, x, a[N];
int main() {
	for (scanf("%d", &T); T; T--) {
		scanf("%d%d", &n, &x);
		LL ans = 0, mn = 0, mx = 0;
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]), mn += a[i], ans += a[i] / x, a[i] %= x, mx += (bool)a[i];
		mx += ans;
		printf("%lld %lld\n", (mn+x-1)/x, mx);
	}
	return 0;
}