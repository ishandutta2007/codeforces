#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int &v : a) {
		std::cin >> v;
		++v;
	}
	std::vector<std::vector<int>> f(n, std::vector<int>(n + 1, n));
	std::fill(f[0].begin() + 1, f[0].end(), 0);
	for (int i = 1; i < n; ++i) {
		int cnt = 0;
		for (int j = i - 1; j >= 0; --j) {
			if (j + a[j] > i) {
				f[i][j + a[j]] = std::min(f[i][j + a[j]], f[j][i] + cnt);
				++cnt;
			}
		}
		for (int j = i + 1; j < n; ++j) {
			f[i][j + 1] = std::min(f[i][j + 1], f[i][j]);
		}
	}
	std::cout << f[n - 1][n] << "\n";
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