#include <bits/stdc++.h>

const int P = 998244353;

int qpow(int a, int b) {
	int s = 1;
	for (; b; b >>= 1) {
		if (b & 1) {
			s = 1ll * s * a % P;
		}
		a = 1ll * a * a % P;
	}
	return s;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	std::vector<int> w(n);
	int wa = 0, wb = 0;
	for (int i = 0; i < n; ++i) {
		std::cin >> w[i];
		if (a[i]) {
			wa += w[i];
		} else {
			wb += w[i];
		}
	}

	std::vector<std::vector<int>> f(m + 1, std::vector<int>(m + 1));
	std::vector<std::vector<int>> g(m + 1, std::vector<int>(m + 1));
	for (int i = m; i >= 0; --i) {
		for (int j = m - i; j >= 0; --j) {
			if (j > wb) {
				continue;
			}
			if (i + j == m) {
				f[i][j] = g[i][j] = 1;
				continue;
			}
			int Wa = wa + i, Wb = wb - j, invw = qpow(Wa + Wb, P - 2);
			f[i][j] = (1ll * (Wa + 1) * f[i + 1][j] + 1ll * Wb * f[i][j + 1]) % P * invw % P;
			g[i][j] = (1ll * (Wb - 1) * g[i][j + 1] + 1ll * Wa * g[i + 1][j]) % P * invw % P;
		}
	}
	for (int i = 0; i < n; ++i) {
		if (a[i]) {
			std::cout << 1ll * w[i] * f[0][0] % P << "\n";
		} else {
			std::cout << 1ll * w[i] * g[0][0] % P << "\n";
		}
	}
}