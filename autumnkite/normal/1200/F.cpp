#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	std::vector<std::vector<int>> E(n);
	int m = 1;
	for (int i = 0; i < n; ++i) {
		int k;
		std::cin >> k;
		E[i].resize(k);
		for (int &x : E[i]) {
			std::cin >> x;
			--x;
		}
		m = m / std::__gcd(m, k) * k;
	}
	for (int &x : a) {
		x = (x % m + m) % m;
	}

	std::vector<int> p(n * m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int nj = (j + a[i]) % m;
			p[i * m + j] = E[i][nj % E[i].size()] * m + nj;
		}
	}
	std::vector<int> vis_time(n * m, -1);
	std::vector<int> f(n * m, -1);
	for (int i = 0; i < n * m; ++i) {
		if (vis_time[i] == -1) {
			int now = i;
			while (vis_time[now] == -1) {
				vis_time[now] = i;
				now = p[now];
			}
			if (vis_time[now] != i) {
				for (int j = i; vis_time[j] == i; j = p[j]) {
					f[j] = f[now];
				}
			} else {
				int u = now;
				std::set<int> S;
				do {
					S.insert(u / m);
					u = p[u];
				} while (u != now);
				do {
					f[u] = S.size();
					u = p[u];
				} while (u != now);
				for (int j = i; j != now; j = p[j]) {
					f[j] = S.size();
				}
			}
		}
	}

	int q;
	std::cin >> q;
	while (q--) {
		int u, c;
		std::cin >> u >> c;
		--u;
		c = (c % m + m) % m;
		std::cout << f[u * m + c] << "\n";
	}
}