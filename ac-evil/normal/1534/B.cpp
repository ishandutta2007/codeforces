#include <bits/stdc++.h>
typedef long long ll;
const int N = 4e5 + 5;
int T, n, a[N];
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		a[0] = a[n + 1] = 0;
		ll ans = 0;
		for (int i = 1; i <= n; i++)
			if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
				int t = std::max(a[i - 1], a[i + 1]); 
				ans += a[i] - t; a[i] = t;
			}
		for (int i = 1; i <= n + 1; i++)
			ans += abs(a[i] - a[i - 1]);
		printf("%lld\n", ans);
	}
}