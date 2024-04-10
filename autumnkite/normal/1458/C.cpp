#include <bits/stdc++.h>

void solve() {
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> a(n, std::vector<int>(n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			std::cin >> a[i][j];
			--a[i][j];
		}
	}
	std::string op;
	std::cin >> op;
	std::vector<int> p({0, 1, 2});
	std::vector<int> c({0, 0, 0});
	for (int i = 0; i < m; ++i) {
		if (op[i] == 'L') {
			--c[1];
		} else if (op[i] == 'R') {
			++c[1];
		} else if (op[i] == 'U') {
			--c[0];
		} else if (op[i] == 'D') {
			++c[0];
		} else if (op[i] == 'I') {
			std::swap(c[1], c[2]);
			std::swap(p[1], p[2]);
		} else if (op[i] == 'C') {
			std::swap(c[0], c[2]);
			std::swap(p[0], p[2]);
		}
	}
	std::vector<std::vector<int>> ans(n, std::vector<int>(n));
	for (int &x : c) {
		x = (x % n + n) % n;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			std::vector<int> x({i, j, a[i][j]});
			std::vector<int> nx({x[p[0]], x[p[1]], x[p[2]]});
			for (int k = 0; k < 3; ++k) {
				nx[k] = (nx[k] + c[k]) % n;
			}
			ans[nx[0]][nx[1]] = nx[2];
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			std::cout << ans[i][j] + 1 << " ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
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