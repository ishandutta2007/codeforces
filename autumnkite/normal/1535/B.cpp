#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int &x : a) {
		std::cin >> x;
	}
	std::sort(a.begin(), a.end(), [&](int x, int y) {
		return (x & 1) < (y & 1);
	});
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			ans += std::__gcd(a[i], 2 * a[j]) > 1;
		}
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