#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m, q;
	std::cin >> n >> m >> q;
	std::vector<std::vector<int>> s[2] = {
		std::vector<std::vector<int>>(n + 1, std::vector<int>(m + 1)),
		std::vector<std::vector<int>>(n + 1, std::vector<int>(m + 1))
	};
	for (int i = 0; i < n; ++i) {
		std::string tmp;
		std::cin >> tmp;
		for (int j = 0; j < m; ++j) {
			s[0][i + 1][j + 1] = s[0][i][j + 1] + s[0][i + 1][j] - s[0][i][j] + (tmp[j] == '1');
			s[1][i + 1][j + 1] = s[1][i][j + 1] + s[1][i + 1][j] - s[1][i][j] + (tmp[j] == '0');
		}
	}

	auto solve = [&](int x, int y) -> long long {
		int cx = x / n, cy = y / m;
		long long ans = 0;
		if (cx && cy) {
			ans += 2ll * (cx / 2) * (cy / 2) * n * m;
		    ans += 1ll * (cx & 1) * (cy / 2) * n * m;
			ans += 1ll * (cx / 2) * (cy & 1) * n * m;
			ans += 1ll * (cx & 1) * (cy & 1) * s[__builtin_parity((cx - 1) ^ (cy - 1))][n][m];
		}
		if (cy) {
			ans += 1ll * (cy / 2) * (x % n) * m;
			ans += 1ll * (cy & 1) * s[__builtin_parity(cx ^ (cy - 1))][x % n][m];
		}
		if (cx) {
			ans += 1ll * (cx / 2) * n * (y % m);
			ans += 1ll * (cx & 1) * s[__builtin_parity((cx - 1) ^ cy)][n][y % m];
		}
		ans += s[__builtin_parity(cx ^ cy)][x % n][y % m];
		return ans;
	};

	while (q--) {
		int sx, sy, tx, ty;
		std::cin >> sx >> sy >> tx >> ty;
		--sx, --sy;
		std::cout << solve(tx, ty) - solve(sx, ty) - solve(tx, sy) + solve(sx, sy) << "\n";
	}
}