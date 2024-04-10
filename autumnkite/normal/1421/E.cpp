#include <bits/stdc++.h>

const long long INF = 0x3f3f3f3f3f3f3f3fll;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}

	if (n == 1) {
		std::cout << a[0] << "\n";
		return 0;
	}

	auto upd = [&](long long &a, long long b) {
		a = std::max(a, b);
	};

	std::array<std::array<std::array<long long, 2>, 2>, 3> f;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 2; ++j) {
			for (int k = 0; k < 2; ++k) {
				f[i][j][k] = -INF;
			}
		}
	}
	f[0][0][0] = 0;
	for (int t = 0; t < n; ++t) {
		std::array<std::array<std::array<long long, 2>, 2>, 3> g;
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 2; ++j) {
				for (int k = 0; k < 2; ++k) {
					g[i][j][k] = -INF;
				}
			}
		}
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 2; ++j) {
				for (int k = 0; k < 2; ++k) {
					upd(g[(i + 1) % 3][0][k | (t > 0 && j == 0)], f[i][j][k] + a[t]);
					upd(g[(i + 2) % 3][1][k | (t > 0 && j == 1)], f[i][j][k] - a[t]);
				}
			}
		}
		f.swap(g);
	}
	std::cout << std::max(f[1][0][1], f[1][1][1]) << "\n";
}