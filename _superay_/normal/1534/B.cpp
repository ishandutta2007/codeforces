#include <bits/stdc++.h>
using namespace std;
int n;
long long a[400005];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
		a[0] = a[n + 1] = 0;
		long long ans = 0;
		for (int i = 0; i <= n; i++) a[i] = a[i + 1] - a[i], ans += abs(a[i]);
		for (int i = 0; i < n; i++) if (a[i] > 0 && a[i + 1] < 0) ans -= min(a[i], -a[i + 1]);
		printf("%lld\n", ans);
	}
	return 0;
}