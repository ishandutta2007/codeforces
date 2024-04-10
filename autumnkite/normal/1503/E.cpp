#include <bits/stdc++.h>

const int P = 998244353;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;

	std::vector<std::vector<int>> C(n + m + 1, std::vector<int>(n + m + 1));
	for (int i = 0; i <= n + m; ++i) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; ++j) {
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % P;
		}
	}

	auto calc = [&](int n, int m) {
		int ans = 0;
		for (int j = 1; j < m; ++j) {
			int sum = 0;
			for (int i = 1; i < n; ++i) {
				int t = 1ll * C[i + j - 1][j] * C[n - i + j - 1][n - i] % P;
				ans = (ans + (2ll * sum + t) * C[i + m - j - 1][i] % P * C[n - i + m - j - 1][m - j]) % P;
				sum = (sum + t) % P;
			}
		}
		return ans;
	};

	std::cout << (calc(n, m) + calc(m, n)) % P << "\n";
}