#include <bits/stdc++.h>

void solve() {
	int n, m;
	std::cin >> n >> m;
	std::vector<int> sum(n + m - 1);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int x;
			std::cin >> x;
			sum[i + j] ^= x;
		}
	}
	for (int i = 0; i < n + m - 1; ++i) {
		if (sum[i]) {
			std::cout << "Ashish\n";
			return;
		}
	}
	std::cout << "Jeel\n";
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