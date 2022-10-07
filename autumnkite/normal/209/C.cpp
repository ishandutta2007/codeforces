#include <bits/stdc++.h>

const int N = 1000005;

int n, m;
int d[N];

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

int sz[N], odd[N];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n >> m;
	D.init(n);
	for (int i = 1; i <= m; ++i) {
		int u, v;
		std::cin >> u >> v;
		D.merge(u, v);
		++d[u], ++d[v];
	}

	int a = 0;
	for (int i = 1; i <= n; ++i) {
		sz[D.find(i)] += d[i];
		if (d[i] & 1) {
			++odd[D.find(i)];
			++a;
		}
	}
	int b = 0;
	int c = 0;
	for (int i = 1; i <= n; ++i) {
		if (D.find(i) == i && (i == 1 || sz[i])) {
			++c;
			b += !odd[i];
		}
	}
	std::cout << a / 2 + (c == 1 ? 0 : b) << "\n";
}