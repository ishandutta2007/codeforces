#include <bits/stdc++.h>
const int N = 100005;
int T, n, m, a[N], cnt[N];
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i <= m; i++) cnt[i] = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			cnt[a[i] % m]++;
		}
		int ans = 0;
		for (int i = 0; i <= m / 2; i++) {
			if (i * 2 == m || i == 0) ans += (bool)cnt[i];
			else if (cnt[i] || cnt[m - i]) {
				ans += std::max(1, abs(cnt[i] - cnt[m - i]));
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}