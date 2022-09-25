#include<bits/stdc++.h>

using namespace std;

const int MX = 200000;

vector< pair<int, int> > G[MX];
int dsu[MX], par[20][MX], mx[20][MX], dep[MX];

int dsu_get(int v) {
	if (dsu[v] != v) dsu[v] = dsu_get(dsu[v]);
	
	return dsu[v];
}

bool dsu_merge(int u, int v) {
	u = dsu_get(u);
	v = dsu_get(v);
	
	if (u == v) return false;
	
	dsu[u] = v;
	
	return true;
}

void dfs(int v, int p = -1, int w = -1, int d = 0) {
	dep[v] = d;
	par[0][v] = p;
	mx[0][v] = w;
	for (int i = 1; i < 20; i++) {
		par[i][v] = par[i - 1][par[i - 1][v]];
		mx[i][v] = max(mx[i - 1][v], mx[i - 1][par[i - 1][v]]);
	}
	
	for (auto e : G[v]) if (e.first != p) dfs(e.first, v, e.second, d + 1);
}

int f(int u, int v) {
	if (dep[u] < dep[v]) {
		u ^= v;
		v ^= u;
		u ^= v;
	}
	
	int res = 0;
	for (int i = 19; i >= 0; i--)
		if (dep[u] - (1 << i) >= dep[v]) {
			res = max(mx[i][u], res);
			u = par[i][u];
		}
	
	for (int i = 19; i >= 0; i--)
		if (par[i][u] != par[i][v]) {
			res = max(max(mx[i][u], mx[i][v]), res);
			
			u = par[i][u];
			v = par[i][v];
		}
	
	if (u != v) res = max(max(mx[0][u], mx[0][v]), res);
	
	return res;
}

struct edge_t {
	int u, v, w, id;
	
	bool operator < (const edge_t &RHS) const {
		return w < RHS.w;
	}
} E[MX];
long long ans[MX];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &E[i].u, &E[i].v, &E[i].w);
		E[i].u--;
		E[i].v--;
		E[i].id = i;
	}
	
	sort(E, E + m);
	
	for (int i = 0; i < n; i++) dsu[i] = i;
	
	long long sum = 0;
	for (auto e : E)
		if (dsu_merge(e.u, e.v)) {
			G[e.u].push_back(make_pair(e.v, e.w));
			G[e.v].push_back(make_pair(e.u, e.w));
			
			sum += e.w;
		}
	
	dfs(0);
	
	for (auto e : E) if (e.u != e.v) ans[e.id] = sum + e.w - f(e.u, e.v);
	
	for (int i = 0; i < m; i++) printf("%I64d\n", ans[i]);
	
	return 0;
}