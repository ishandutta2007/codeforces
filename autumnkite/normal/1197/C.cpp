#include <bits/stdc++.h>

const int N = 300005;

int n, k, a[N], b[N];

void solve() {
	std::cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
	}
	for (int i = 1; i < n; ++i) {
		b[i] = a[i + 1] - a[i];
	}
	std::sort(b + 1, b + n);
	int ans = 0;
	for (int i = 1; i <= n - k; ++i) {
		ans += b[i];
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