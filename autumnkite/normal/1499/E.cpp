#include <bits/stdc++.h>

const int P = 998244353;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::string a, b;
	std::cin >> a >> b;
	int n = a.size(), m = b.size();
	int ans = 0;
	std::vector<std::vector<int>> f(n, std::vector<int>(m)), g(f);
	std::vector<int> ft(n), gt(m);
	for (int i = 0; i < n; ++i) {
		ft[i] = 1;
		if (i > 0 && a[i - 1] != a[i]) {
			ft[i] = (ft[i] + ft[i - 1]) % P;
		}
	}
	for (int i = 0; i < m; ++i) {
		gt[i] = 1;
		if (i > 0 && b[i - 1] != b[i]) {
			gt[i] = (gt[i] + gt[i - 1]) % P;
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (b[j] != a[i]) {
				f[i][j] = gt[j];
				g[i][j] = ft[i];
			}
			if (i > 0 && a[i - 1] != a[i]) {
				f[i][j] = (f[i][j] + f[i - 1][j]) % P;
			}
			if (i > 0 && b[j] != a[i]) {
				f[i][j] = (f[i][j] + g[i - 1][j]) % P;
			}
			if (j > 0 && b[j - 1] != b[j]) {
				g[i][j] = (g[i][j] + g[i][j - 1]) % P;
			}
			if (j > 0 && a[i] != b[j]) {
				g[i][j] = (g[i][j] + f[i][j - 1]) % P;
			}
			ans = (ans + f[i][j]) % P;
			ans = (ans + g[i][j]) % P;
		}
	}
	std::cout << ans << "\n";
}