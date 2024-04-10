#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n + 2);
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
	}
	long long ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
			int v = a[i] - std::max(a[i - 1], a[i + 1]);
			a[i] -= v;
			ans += v;
		}
	}
	for (int i = 0; i <= n; ++i) {
		ans += abs(a[i] - a[i + 1]);
	}
	std::cout << ans << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int T;
	std::cin >> T;
	while (T--) {
		solve();
	}
}