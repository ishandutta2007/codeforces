#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, P;
	std::cin >> n >> P;
	std::vector<std::vector<std::pair<int, int>>> f(2);
	std::vector<int> ft(1);
	f[1].emplace_back(0, 1);
	for (int i = 1; i < n; ++i) {
		std::vector<std::vector<std::pair<int, int>>> g(i + 2);
		std::vector<int> gt(i + 1);
		for (int j = 1; j <= i + 1; ++j) {
			g[j].resize(j);
			int sum = 0;
			for (int k = 0; k < j; ++k) {
				g[j][k].first = sum;
				if (k < j - 1) {
					sum = (sum + f[j - 1][k].first) % P;
					sum = (sum + f[j - 1][k].second) % P;
				}
			}
			gt[j - 1] = sum;
			sum = 0;
			for (int k = j - 1; k >= 0; --k) {
				if (k < j - 1) {
					sum = (sum + f[j - 1][k].second) % P;
				}
				g[j][k].second = (sum + (j <= i ? ft[j - 1] : 0)) % P;
			}
		}
		f.swap(g);
		ft.swap(gt);
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < i; ++j) {
			ans = (ans + f[i][j].first) % P;
			ans = (ans + f[i][j].second) % P;
		}
	}
	std::cout << ans << "\n";
}