#include <bits/stdc++.h>

const int N = 300005, M = 10;
const long long INF = 0x3f3f3f3f3f3f3f3fll;

int n, m, k;
long long a[N], b[N], mn[M];

void solve() {
	std::cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
		a[i] += a[i - 1];
	}
	for (int i = 1; i <= n; ++i) {
		b[i] = *std::min_element(a + std::max(i - m, 0), a + i);
	}
	for (int i = 0; i < m; ++i) {
		mn[i] = INF;
	}
	long long ans = 0;
	for (int i = 1; i <= n; ++i) {
		mn[i % m] = std::min(mn[i % m], b[i] - 1ll * (i / m - 1) * k);
		ans = std::max(ans, a[i] - 1ll * (i / m) * k - mn[i % m]);
	}
	std::cout << ans << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int T = 1;
	// std::cin >> T;
	while (T--) {
		solve();
	}
}