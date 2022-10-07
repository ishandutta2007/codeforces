#include <bits/stdc++.h>

const int P = 1000000007;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;
	if (m > n + 1) {
		std::cout << 0 << "\n";
		return 0;
	}
	std::vector<std::vector<int>> f(n + 1, std::vector<int>(n + 2));
	std::vector<std::vector<int>> g(n + 1, std::vector<int>(n + 2));
	std::vector<int> inv(n + 1);
	inv[1] = 1;
	for (int i = 2; i <= n; ++i) {
		inv[i] = 1ll * (P - P / i) * inv[P % i] % P;
	}
	for (int i = 2; i <= n; ++i) {
		inv[i] = 1ll * inv[i - 1] * inv[i] % P;
	}
	f[0][1] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < i; ++j) {
			for (int a = 0; a <= j + 1; ++a) {
				for (int b = 0; b <= i - j; ++b) {
					g[i][std::min(a, b)] = (g[i][std::min(a, b)] + 1ll * f[j][a] * f[i - j - 1][b]) % P;
				}
			}
		}
		for (int a = 0; a <= i; ++a) {
			for (int j = n; j >= i; --j) {
				for (int b = j + 1; b >= a; --b) {
					int s = g[i][a];
					for (int k = 1; i * k <= j && a * k <= b; ++k) {
						f[j][b] = (f[j][b] + 1ll * f[j - i * k][b - a * k] * s % P * inv[k]) % P;
						s = 1ll * s * (g[i][a] + k) % P;
					}
				}
			}
		}
	}
	std::cout << f[n][m] << "\n";
}