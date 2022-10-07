#include <bits/stdc++.h>

const long long INF = 0x3f3f3f3f3f3f3f3fll;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::string s;
	std::cin >> s;
	std::vector<long long> a(n + 1);
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j < i; ++j) {
			a[i] = std::max(a[i], a[j] + a[i - j]);
		}
	}

	std::vector<std::vector<long long>> f(n, std::vector<long long>(n, -INF));
	for (int l = n - 1; l >= 0; --l) {
		std::vector<std::vector<long long>> g(n, std::vector<long long>(n + 1, -INF));
		for (int r = l; r < n; ++r) {
			g[r][1] = l < r ? f[l][r - 1] : 0;
			for (int i = 2; i <= r - l + 1; ++i) {
				for (int k = l; k < r; ++k) {
					if (s[k] == s[r]) {
						g[r][i] = std::max(g[r][i], g[k][i - 1] + (k + 1 < r ? f[k + 1][r - 1] : 0));
					}
				}
			}
			for (int i = 1; i <= r - l + 1; ++i) {
				f[l][r] = std::max(f[l][r], g[r][i] + a[i]);
			}
			for (int k = l; k < r; ++k) {
				f[l][r] = std::max(f[l][r], f[l][k] + f[k + 1][r]);
			}
		}
	}
	std::cout << f[0][n - 1] << "\n";
}