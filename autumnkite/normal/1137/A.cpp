#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> a(n, std::vector<int>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			std::cin >> a[i][j];
		}
	}

	std::vector<std::vector<int>> r(n), c(m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			r[i].push_back(a[i][j]);
		}
		std::sort(r[i].begin(), r[i].end());
		r[i].erase(std::unique(r[i].begin(), r[i].end()), r[i].end());
	}
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			c[i].push_back(a[j][i]);
		}
		std::sort(c[i].begin(), c[i].end());
		c[i].erase(std::unique(c[i].begin(), c[i].end()), c[i].end());
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int r0 = std::lower_bound(r[i].begin(), r[i].end(), a[i][j]) - r[i].begin();
			int c0 = std::lower_bound(c[j].begin(), c[j].end(), a[i][j]) - c[j].begin();
			std::cout << std::max(r0, c0) + std::max((int)r[i].size() - r0 - 1, (int)c[j].size() - c0 - 1) + 1 << " ";
		}
		std::cout << "\n";
	}
}