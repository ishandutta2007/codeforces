#include <bits/stdc++.h>

const int INF = 0x3f3f3f3f;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;
	std::vector<bool> a(1 << n);
	for (int i = 0; i < m; ++i) {
		int x;
		std::cin >> x;
		--x;
		a[x] = true;
	}
	std::vector<std::array<std::array<int, 2>, 2>> f(1 << (n - 1));
	auto upd = [&](int &a, int b) {
		a = std::max(a, b);
	};
	for (int i = 0; i < (1 << (n - 1)); ++i) {
		for (int x = 0; x < 2; ++x) {
			for (int y = 0; y < 2; ++y) {
				f[i][x][y] = -INF;
			}
		}
		f[i][a[i << 1]][a[i << 1 | 1]] = a[i << 1] | a[i << 1 | 1];
		f[i][a[i << 1 | 1]][a[i << 1]] = a[i << 1] | a[i << 1 | 1];
	}
	for (int k = 2; k <= n; ++k) {
		std::vector<std::array<std::array<int, 2>, 2>> g(1 << (n - k));
		for (int i = 0; i < (1 << (n - k)); ++i) {
			for (int x = 0; x < 2; ++x) {
				for (int y = 0; y < 2; ++y) {
					g[i][x][y] = -INF;
				}
			}
			for (int x0 = 0; x0 < 2; ++x0) {
				for (int y0 = 0; y0 < 2; ++y0) {
					for (int x1 = 0; x1 < 2; ++x1) {
						for (int y1 = 0; y1 < 2; ++y1) {
							int s = f[i << 1][x0][y0] + f[i << 1 | 1][x1][y1] + (x0 | x1) + (y0 | y1);
							upd(g[i][x0][x1 | y0 | y1], s + (x1 | y0 | y1));
							upd(g[i][x1][x0 | y0 | y1], s + (x0 | y0 | y1));
						}
					}
				}
			}
		}
		f.swap(g);
	}
	std::cout << std::max({f[0][0][0], f[0][0][1] + 1, f[0][1][0] + 1, f[0][1][1] + 1}) << "\n";
}