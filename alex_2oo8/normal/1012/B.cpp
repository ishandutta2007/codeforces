#include <bits/stdc++.h>

using namespace std;

const int MX = 400000;

namespace dsu {
	int p[MX], sz[MX];
	
	void init(int n) {
		iota(p, p + n, 0);
		fill(sz, sz + n, 1);
	}
	
	int get(int v) {
		if (p[v] != v) p[v] = get(p[v]);
		return p[v];
	}
	
	bool merge(int u, int v) {
		u = get(u);
		v = get(v);
		if (u == v) return false;
		p[u] = v;
		sz[v] += sz[u];
		return true;
	}
}

int main() {
	int n, m, q;
	ignore = scanf("%d %d %d", &n, &m, &q);
	
	dsu::init(n + m);
	
	while (q--) {
		int x, y;
		ignore = scanf("%d %d", &x, &y);
		dsu::merge(x - 1, n + y - 1);
	}
	
	int r = 0, c = 0, f = 0;
	for (int i = 0; i < n; i++)
		if (dsu::get(i) == i) {
			if (dsu::sz[i] == 1) r++;
			else f++;
		}
	
	for (int i = n; i < n + m; i++)
		if (dsu::get(i) == i) {
			if (dsu::sz[i] == 1) c++;
			else f++;
		}
	
	int ans = r + c + f - 1;
	
	printf("%d\n", ans);
	
	return 0;
}