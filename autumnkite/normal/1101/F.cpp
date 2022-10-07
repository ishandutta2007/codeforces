#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	std::vector<std::vector<std::tuple<int, int, int>>> Q(n);
	for (int i = 0; i < m; ++i) {
		int s, t, c, r;
		std::cin >> s >> t >> c >> r;
		--s, --t;
		r = std::min(r, n - 2);
		Q[r + 1].emplace_back(s, t, c);
	}
	std::vector<std::vector<int>> f(n, std::vector<int>(n, a[n - 1]));
	for (int i = 0; i < n; ++i) {
		f[i][i] = 0;
	}
	long long ans = 0;
	for (int k = 1; k < n; ++k) {
		std::vector<std::vector<int>> g(n, std::vector<int>(n, a[n - 1]));
		for (int i = 0; i < n; ++i) {
			int l = i;
			for (int j = i; j < n; ++j) {
				while (l <= j && f[i][l] < a[j] - a[l]) {
					++l;
				}
				if (l <= j) {
					g[i][j] = std::min(g[i][j], std::max(f[i][l], a[j] - a[l]));
				}
				if (l - 1 >= i) {
					g[i][j] = std::min(g[i][j], std::max(f[i][l - 1], a[j] - a[l - 1]));
				}
			}
		}
		f.swap(g);
		for (auto [s, t, c] : Q[k]) {
			ans = std::max(ans, 1ll * f[s][t] * c);
		}
	}
	std::cout << ans << "\n";
}