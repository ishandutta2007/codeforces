#include <bits/stdc++.h>

const int INF = 0x3f3f3f3f;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	std::vector<int> b(m);
	std::vector<int> p(m + 1);
	p[0] = 1;
	for (int i = 0; i < m; ++i) {
		std::cin >> b[i];
		p[i + 1] = p[i] * (b[i] + 1);
	}
	std::vector<std::vector<int>> c(n, std::vector<int>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			std::cin >> c[i][j];
		}
	}

	std::vector<int> f(p[m], INF);
	f[0] = 0;
	for (int k = 0; k < n; ++k) {
		std::vector<std::vector<int>> g(a[k] + 1, std::vector<int>(p[m], INF));
		g[0] = f;
		for (int i = 1; i <= a[k]; ++i) {
			for (int S = 0; S < p[m]; ++S) {
				for (int t = 0; t < m; ++t) {
					int w = (S / p[t]) % (b[t] + 1);
					for (int j = 1; j <= i && j <= w; ++j) {
						g[i][S] = std::min(g[i][S], g[i - j][S - j * p[t]] + c[k][t]);
					}
				}
			}
		}
		f = g[a[k]];
	}
	int ans = *std::min_element(f.begin(), f.end());
	if (ans == INF) {
		std::cout << -1 << "\n";
	} else {
		std::cout << ans << "\n";
	}
}