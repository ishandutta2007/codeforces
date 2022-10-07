#include <bits/stdc++.h>

const int N = 100005;

int n, a[N];

struct Node {
	int x, y, z;
};

void solve() {
	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
	}
	std::vector<Node> ans;
	if (n & 1) {
		for (int i = 2; i <= n; i += 2) {
			ans.push_back({1, i, i + 1});
		}
		for (int i = 2; i <= n - 2; i += 2) {
			ans.push_back({i, i + 1, n});
		}
	} else {
		int sum = 0;
		for (int i = 1; i <= n; ++i) {
			sum ^= a[i];
		}
		if (sum) {
			std::cout << "NO\n";
			return;
		}
		for (int i = 1; i <= n - 2; i += 2) {
			ans.push_back({i, i + 1, n});
		}
		for (int i = 1; i <= n - 2; i += 2) {
			ans.push_back({i, i + 1, n});
		}
	}
	std::cout << "YES\n";
	std::cout << ans.size() << "\n";
	for (auto v : ans) {
		std::cout << v.x << " " << v.y << " " << v.z << "\n";
	}
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