#include <bits/stdc++.h>

const int N = 1000005;

int n, m;
int d[N], deg[N];

int c;

struct DSU {
	int fa[N];

	void init(int n) {
		for (int i = 1; i <= n; ++i) {
			fa[i] = i;
		}
	}

	int find(int x) {
		return fa[x] == x ? x : (fa[x] = find(fa[x]));
	}

	bool merge(int x, int y) {
		x = find(x), y = find(y);
		if (x == y) {
			return false;
		}
		fa[y] = x;
		return true;
	}
} D;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n >> m;
	D.init(n);
	for (int i = 1; i <= m; ++i) {
		int u, v;
		std::cin >> u >> v;
		++deg[u], ++deg[v];
		if (u == v) {
			++c;
		} else {
			++d[u];
			++d[v];
			D.merge(u, v);
		}
	}
	int bdc = 0;
	for (int i = 1; i <= n; ++i) {
		if (deg[i]) {
			bdc = i;
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (deg[i] && D.find(bdc) != D.find(i)) {
			std::cout << 0 << "\n";
			return 0;
		}
	}
	long long ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans += 1ll * d[i] * (d[i] - 1) / 2;
	}
	ans += 1ll * c * (c - 1) / 2;
	ans += 1ll * c * (m - c);
	std::cout << ans << "\n";
}