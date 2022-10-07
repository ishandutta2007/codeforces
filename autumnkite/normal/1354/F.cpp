#include <bits/stdc++.h>

const int INF = 0x3f3f3f3f;

void solve() {
	int n, m;
	std::cin >> n >> m;
	std::vector<int> a(n), b(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i] >> b[i];
	}
	std::vector<int> p(n);
	for (int i = 0; i < n; ++i) {
		p[i] = i;
	}
	std::sort(p.begin(), p.end(), [&](int i, int j) {
		return b[i] < b[j];
	});
	std::vector<std::vector<int>> f(n + 1, std::vector<int>(m + 1, -INF));
	std::vector<std::vector<int>> g(n + 1, std::vector<int>(m + 1, 0));
	auto upd = [&](int &a, int b) {
		if (b > a) {
			a = b;
			return true;
		} else {
			return false;
		}
	};
	f[0][0] = 0;
	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < m; ++i) {
			if (upd(f[k + 1][i + 1], f[k][i] + a[p[k]] + b[p[k]] * i)) {
				g[k + 1][i + 1] = 1;
			}
		}
		for (int i = 0; i <= m; ++i) {
			if (upd(f[k + 1][i], f[k][i] + b[p[k]] * (m - 1))) {
				g[k + 1][i] = 0;
			}
		}
	}
	std::vector<int> c[2];
	int now = m;
	for (int i = n - 1; i >= 0; --i) {
		int t = g[i + 1][now];
		c[t].push_back(p[i]);
		now -= t;
	}
	std::cout << 2 * c[0].size() + c[1].size() << "\n";
	for (int i = (int)c[1].size() - 1; i > 0; --i) {
		std::cout << c[1][i] + 1 << " ";
	}
	for (int x : c[0]) {
		std::cout << x + 1 << " " << -(x + 1) << " ";
	}
	std::cout << c[1][0] + 1 << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int T;
	std::cin >> T;
	while (T--) {
		solve();
	}
}