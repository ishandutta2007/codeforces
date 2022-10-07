#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::map<long long, int> bel;
	std::vector<long long> sum(n);
	long long all = 0;
	for (int i = 0; i < n; ++i) {
		int m;
		std::cin >> m;
		std::vector<long long> a(m);
		for (auto &x : a) {
			std::cin >> x;
			bel[x] = i;
			sum[i] += x;
			all += x;
		}
	}
	if (all % n != 0) {
		std::cout << "No\n";
		return 0;
	}
	all /= n;

	std::map<long long, long long> vis_time;
	std::vector<bool> cyc(1 << n);
	std::vector<long long> st(1 << n);
	for (auto [x, b] : bel) {
		if (!vis_time.count(x)) {
			long long p = x;
			while (bel.count(p) && !vis_time.count(p)) {
				vis_time[p] = x;
				p = all - sum[bel[p]] + p;
			}
			if (!bel.count(p) || vis_time[p] != x) {
				continue;
			}
			bool flag = true;
			int mask = 0;
			long long q = p;
			do {
				if (mask >> bel[q] & 1) {
					flag = false;
				} else {
					mask |= 1 << bel[q];
				}
				q = all - sum[bel[q]] + q;
			} while (q != p);
			if (flag) {
				cyc[mask] = true;
				st[mask] = p;
			}
		}
	}

	std::vector<bool> f(1 << n);
	std::vector<int> g(1 << n);
	f[0] = true;
	for (int S = 1; S < (1 << n); ++S) {
		for (int T = S; T; T = (T - 1) & S) {
			if (cyc[T] && f[S ^ T]) {
				f[S] = true;
				g[S] = T;
				break;
			}
		}
	}

	int now = (1 << n) - 1;
	if (!f[now]) {
		std::cout << "No\n";
		return 0;
	}
	std::vector<long long> c(n);
	std::vector<int> p(n);
	while (now != 0) {
		int S = g[now];
		long long x = st[S];
		do {
			c[bel[x]] = x;
			long long nx = all - sum[bel[x]] + x;
			p[bel[nx]] = bel[x];
			x = nx;
		} while (x != st[S]);
		now ^= S;
	}
	std::cout << "Yes\n";
	for (int i = 0; i < n; ++i) {
		std::cout << c[i] << " " << p[i] + 1 << "\n";
	}
}