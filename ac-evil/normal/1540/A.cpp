#include <bits/stdc++.h>
typedef long long ll;
const int N = 1e5 + 5;
int T, n, a[N];
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		ll ans = 0;
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		std::sort(a + 1, a + n + 1);
		for (int i = 1; i <= n; i++)
			ans += (ll)(n - i) * a[i] + (ll)(i - 1) * (-a[i]);
		printf("%lld\n", ans + a[n]);
	}
	return 0;
}