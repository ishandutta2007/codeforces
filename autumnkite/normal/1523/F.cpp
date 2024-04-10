#include <bits/stdc++.h>

const int INF = 0x3f3f3f3f;

struct point {
	int x, y;
};

int dist(const point &a, const point &b) {
	return abs(a.x - b.x) + abs(a.y - b.y);
}

struct task {
	int t;
	point p;

	bool operator<(const task &rhs) const {
		return t < rhs.t;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;
	std::vector<point> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i].x >> a[i].y;
	}
	std::vector<task> b(m);
	for (int i = 0; i < m; ++i) {
		std::cin >> b[i].p.x >> b[i].p.y >> b[i].t;
	}
	std::sort(b.begin(), b.end());

	std::vector<std::vector<int>> f(1 << n, std::vector<int>(m, -m));
	std::vector<std::vector<int>> g(1 << n, std::vector<int>(m + 1, INF));
	for (int i = 0; i < m; ++i) {
		f[0][i] = 1;
	}
	for (int i = 0; i < n; ++i) {
		g[1 << i][0] = 0;
	}
	int ans = 0;
	for (int S = 0; S < (1 << n); ++S) {
		for (int i = 0; i < n; ++i) {
			if (S >> i & 1) {
				int mn = INF;
				for (int j = 0; j < n; ++j) {
					if (i != j && S >> j & 1) {
						mn = std::min(mn, dist(a[i], a[j]));
					}
				}
				for (int j = 0; j <= m; ++j) {
					g[S][j] = std::min(g[S][j], g[S ^ (1 << i)][j] + mn);
				}
			}
		}
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < i; ++j) {
				if (b[j].t + dist(b[j].p, b[i].p) <= b[i].t) {
					f[S][i] = std::max(f[S][i], f[S][j] + 1);
				}
			}
			int mn = INF;
			for (int j = 0; j < n; ++j) {
				if (S >> j & 1) {
					mn = std::min(mn, dist(b[i].p, a[j]));
				}
			}
			for (int j = 0; j <= i; ++j) {
				if (g[S][j] + mn <= b[i].t) {
					f[S][i] = std::max(f[S][i], j + 1);
				}
			}
			if (f[S][i] >= 0) {
				g[S][f[S][i]] = std::min(g[S][f[S][i]], b[i].t);
			}
			for (int j = 0; j < n; ++j) {
				if (S >> j & 1 && f[S ^ (1 << j)][i] >= 0) {
					g[S][f[S ^ (1 << j)][i]] = std::min(g[S][f[S ^ (1 << j)][i]], b[i].t + dist(b[i].p, a[j]));
				}
			}
			ans = std::max(ans, f[S][i]);
		}
	}
	std::cout << ans << "\n";
}