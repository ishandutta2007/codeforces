#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> c;
	int mid = (n + 1) / 2;
	c.push_back(0);
	for (int i = mid; i < n; ++i) {
		c.push_back(i);
	}
	for (int i = 1; i < mid; ++i) {
		c.push_back(i);
	}
	std::vector<int> p(n);
	for (int i = 0; i < n; ++i) {
		p[c[i]] = c[(i + 1) % n];
	}
	
	std::vector<std::pair<int, int>> ans;
	for (int i = mid; i < n - 1; ++i) {
		ans.emplace_back(i, 0);
	}
	for (int i = 1; i < mid; ++i) {
		ans.emplace_back(i, n - 1);
	}
	ans.emplace_back(n - 1, 0);

	long long sum = 0;
	for (auto p : ans) {
		sum += 1ll * (p.first - p.second) * (p.first - p.second);
	}
	std::cout << sum << "\n";
	for (int i = 0; i < n; ++i) {
		std::cout << p[i] + 1 << " ";
	}
	std::cout << "\n";
	std::cout << ans.size() << "\n";
	for (auto p : ans) {
		std::cout << p.first + 1 << " " << p.second + 1 << "\n";
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