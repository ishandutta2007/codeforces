#include <bits/stdc++.h>

void solve() {
	int n, m;
	std::cin >> n >> m;
	std::vector<std::pair<int, int>> a;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int v;
			std::cin >> v;
			a.emplace_back(v, i);
		}
	}
	std::sort(a.begin(), a.end());
	std::vector<std::vector<int>> ans(n, std::vector<int>(m, -1));
	std::vector<int> p(n, 0);
	for (int i = 0; i < n * m; ++i) {
		int x = a[i].second;
		if (i < m) {
			ans[x][i] = a[i].first;
		} else {
			while (ans[x][p[x]] != -1) {
				++p[x];
			}
			ans[x][p[x]] = a[i].first;
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			std::cout << ans[i][j] << " ";
		}
		std::cout << "\n";
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