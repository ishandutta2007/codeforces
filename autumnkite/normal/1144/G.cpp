#include <bits/stdc++.h>

const int INF = 0x3f3f3f3f;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	std::vector<int> f(n), g(n);
	f[0] = INF, g[0] = -INF;
	for (int i = 1; i < n; ++i) {
		f[i] = -INF;
		if (a[i - 1] < a[i]) {
			f[i] = std::max(f[i], f[i - 1]);
		}
		if (g[i - 1] < a[i]) {
			f[i] = std::max(f[i], a[i - 1]);
		}
		g[i] = INF;
		if (a[i - 1] > a[i]) {
			g[i] = std::min(g[i], g[i - 1]);
		}
		if (f[i - 1] > a[i]) {
			g[i] = std::min(g[i], a[i - 1]);
		}
	}

	auto solve = [&](int st) {
		std::vector<int> ans(n);
		int i = n - 1;
		while (i >= 0) {
			ans[i] = st;
			if (i == 0) {
				break;
			}
			if (st == 0) {
				if (a[i - 1] < a[i] && f[i - 1] == f[i]) {
					--i;
				} else {
					--i, st ^= 1;
				}
			} else {
				if (a[i - 1] > a[i] && g[i - 1] == g[i]) {
					--i;
				} else {
					--i, st ^= 1;
				}
			}
		}
		for (int i = 0; i < n; ++i) {
			std::cout << ans[i] << " ";
		}
		std::cout << "\n";
	};

	if (f[n - 1] != -INF) {
		std::cout << "YES\n";
		solve(0);
	} else if (g[n - 1] != INF) {
		std::cout << "YES\n";
		solve(1);
	} else {
		std::cout << "NO\n";
	}
}