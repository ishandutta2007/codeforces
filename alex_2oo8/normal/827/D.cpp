#include <bits/stdc++.h>

using namespace std;

const int MX = 200000, INF = 1e9 + 42;

int p[MX];

int dsu_get(int v) {
	if (p[v] != v) p[v] = dsu_get(p[v]);
	return p[v];
}

bool dsu_merge(int u, int v) {
	u = dsu_get(u);
	v = dsu_get(v);
	p[u] = v;
	return u != v;
}

vector<pair<int, int>> G[MX];
int sz[MX], nxt[MX], par[MX], in[MX], pos[MX], cost[MX], a[MX], dep[MX];

void dfs_sz(int v, int p = -1, int d = 0) {
	sz[v] = 1;
	par[v] = p;
	dep[v] = d;
	for (auto& e : G[v]) {
		int u = e.first;
		if (u == p) continue;
		dfs_sz(u, v, d + 1);
		sz[v] += sz[u];
		if(sz[u] > sz[G[v][0].first]) swap(e, G[v][0]);
	}
}

void dfs_hld(int v) {
	static int t = 0;
	in[v] = t++;
	for (auto& e : G[v]) {
		int u = e.first;
		if (par[v] == u) continue;
		nxt[u] = (u == G[v][0].first ? nxt[v] : u);
		pos[e.second] = t;
		a[t] = cost[e.second];
		dfs_hld(u);
	}
}

struct {
	int l, r, lSon, rSon, val, mx;
} t[2 * MX];

int build_tree(int l, int r) {
	static int tw = 0;
	int v = ++tw;
	t[v].l = l;
	t[v].r = r;
	t[v].val = INF;
	if (l < r) {
		t[v].lSon = build_tree(l, (l + r) / 2);
		t[v].rSon = build_tree((l + r) / 2 + 1, r);
		t[v].mx = max(t[t[v].lSon].mx, t[t[v].rSon].mx);
	}
	else {
		t[v].mx = a[l];
	}
	
	return v;
}

void tree_query(int v, int l, int r, int c, int& res) {
	if (l <= t[v].l && t[v].r <= r) {
		res = max(t[v].mx, res);
		t[v].val = min(t[v].val, c);
		
		return;
	}
	
	if (t[t[v].lSon].r >= l) tree_query(t[v].lSon, l, r, c, res);
	if (t[t[v].rSon].l <= r) tree_query(t[v].rSon, l, r, c, res);
}

int tree_get(int v, int x) {
	if (t[v].l == t[v].r) return t[v].val;
	
	return min(t[v].val, tree_get(x <= t[t[v].lSon].r ? t[v].lSon : t[v].rSon, x));
}

int solve(int u, int v, int c) {
	int res = 0;
	while (nxt[u] != nxt[v]) {
		if (dep[nxt[u]] > dep[nxt[v]]) swap(u, v);
		
		tree_query(1, in[nxt[v]], in[v], c, res);
		
		v = par[nxt[v]];
	}
	
	if (u != v) tree_query(1, min(in[u], in[v]) + 1, max(in[u], in[v]), c, res);
	
	return res;
}

int ans[MX];

int main() {
	int n, m;
	ignore = scanf("%d %d", &n, &m);
	
	if (m == n - 1) {
		for (int i = 0; i < m; i++) printf("-1 ");
		printf("\n");
	
		return 0;
	}
	
	vector<tuple<int, int, int, int>> edges;
	for (int i = 0; i < m; i++) {
		int u, v, c;
		ignore = scanf("%d %d %d", &u, &v, &c);
		edges.emplace_back(c, u - 1, v - 1, i);
		
		cost[i] = c;
	}
	
	sort(edges.begin(), edges.end());
	
	for (int i = 0; i < n; i++) p[i] = i;
	
	for (auto& e : edges) {
		int u, v, c, i;
		tie(c, u, v, i) = e;
		
		if (dsu_merge(u, v)) {
			G[u].emplace_back(v, i);
			G[v].emplace_back(u, i);
		}
		else {
			get<0>(e) *= -1;
		}
	}
	
	dfs_sz(0);
	dfs_hld(0);
	
	build_tree(1, n - 1);
	
	for (auto& e : edges) {
		int u, v, c, i;
		tie(c, u, v, i) = e;
		if (c > 0) continue;
		
		ans[i] = solve(u, v, -c);
	}
	
	for (auto& e : edges) {
		int u, v, c, i;
		tie(c, u, v, i) = e;
		if (c < 0) continue;
		
		ans[i] = tree_get(1, pos[i]);
		if (ans[i] == INF) ans[i] = 0;
	}
	
	for (int i = 0; i < m; i++) printf("%d ", ans[i] - 1);
	printf("\n");
	
	return 0;
}