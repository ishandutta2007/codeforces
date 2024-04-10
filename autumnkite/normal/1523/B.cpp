#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	std::vector<std::tuple<int, int, int>> ans;
	for (int i = 0; i < n; i += 2) {
		ans.emplace_back(2, i, i + 1);
		ans.emplace_back(1, i, i + 1);
		ans.emplace_back(2, i, i + 1);
		ans.emplace_back(2, i, i + 1);
		ans.emplace_back(1, i, i + 1);
		ans.emplace_back(2, i, i + 1);
	}
	std::cout << ans.size() << "\n";
	for (auto [op, x, y] : ans) {
		std::cout << op << " " << x + 1 << " " << y + 1 << "\n";
	}
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