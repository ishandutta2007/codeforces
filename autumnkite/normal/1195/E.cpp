#include <bits/stdc++.h>

const int N = 3005, INF = 0x3f3f3f3f;

int n, m, r, c;
int a[N][N];

namespace rnd {
	int g, x, y, z;

	void init() {
		std::cin >> g >> x >> y >> z;
	}

	int nxt() {
		int res = g;
		g = (1ll * g * x + y) % z;
		return res;
	}
}

struct Queue {
	int h, t;
	std::pair<int, int> Q[N];

	void clear() {
		h = 1, t = 0;
	}

	void push(std::pair<int, int> v) {
		while (h <= t && v.second <= Q[t].second) {
			--t;
		}
		Q[++t] = v;
	}

	int top(int p) {
		while (h <= t && Q[h].first <= p) {
			++h;
		}
		if (h <= t) {
			return Q[h].second;
		} else {
			return INF;
		}
	}
} qr[N], qc;

int main() {
	std::cin >> n >> m >> r >> c;
	rnd::init();
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			a[i][j] = rnd::nxt();
		}
	}
	for (int i = 1; i <= m; ++i) {
		qr[i].clear();
	}
	long long ans = 0;
	for (int i = 1; i <= n; ++i) {
		qc.clear();
		for (int j = 1; j <= m; ++j) {
			qc.push({j, a[i][j]});
			qr[j].push({i, qc.top(j - c)});
			if (i >= r && j >= c) {
				ans += qr[j].top(i - r);
			}
		}
	}
	std::cout << ans << "\n";
}