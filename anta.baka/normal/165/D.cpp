#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;

struct node {
	int sum;
	node *l, *r;
};

typedef node *pnode;

pnode build(int l, int r) {
	pnode v = new node;
	if(l == r) {
		v->sum = 1;
		v->l = v->r = NULL;
	} else {
		int m = (l + r) >> 1;
		v->l = build(l, m);
		v->r = build(m + 1, r);
		v->sum = v->l->sum + v->r->sum;
	}
	return v;
}

void upd(pnode v, int l, int r, int pos, int val) {
	if(l == r) v->sum = val;
	else {
		int m = (l + r) >> 1;
		if(pos <= m) upd(v->l, l, m, pos, val);
		else upd(v->r, m + 1, r, pos, val);
		v->sum = v->l->sum + v->r->sum;
	}
}

int get(pnode v, int l, int r, int l1, int r1) {
	if(r < l1 || r1 < l) return 0;
	if(l1 <= l && r <= r1) return v->sum;
	int m = (l + r) >> 1;
	return get(v->l, l, m, l1, r1) + get(v->r, m + 1, r, l1, r1);
}

int n, q, U[maxn], V[maxn];
vector<int> g[maxn];
int sz[maxn], par[maxn], dep[maxn], up[maxn][18], tin[maxn], tout[maxn], tik_tak, len[maxn];
pnode rt[maxn];

void dfs(int v, int p) {
	tin[v] = tik_tak++;
	up[v][0] = p;
	for(int i = 1; i < 18; i++) up[v][i] = up[up[v][i - 1]][i - 1];
	par[v] = v;
	len[v] = 1;
	sz[v] = 1;
	int kid = -1;
	for(int to : g[v]) {
		if(to == p) continue;
		dep[to] = dep[v] + 1;
		dfs(to, v);
		sz[v] += sz[to];
		if(kid == -1 || sz[kid] < sz[to]) kid = to;
	}
	tout[v] = tik_tak++;
	if(kid == -1 || 2 * sz[kid] < sz[v]) return;
	par[v] = par[kid];
	len[par[v]]++;
}

bool upper(int u, int v) {
	return tin[u] < tin[v] && tout[u] > tout[v];
}

int lca(int u, int v) {
	if(upper(u, v)) return u;
	for(int i = 17; i >= 0; i--)
		if(!upper(up[u][i], v))
			u = up[u][i];
	return up[u][0];
}

int getpos(int v) {
	return dep[par[v]] - dep[v];
}

int sum(int u, int v) {
	int ret = 0;
	while(par[u] != par[v]) {
		ret += get(rt[par[v]], 0, len[par[v]] - 1, getpos(v), len[par[v]] - 1);
		int d = len[par[v]] - getpos(v);
		for(int i = 17; i >= 0; i--)
			if((1 << i) <= d) {
				v = up[v][i];
				d -= (1 << i);
			}
	}
	return ret + get(rt[par[u]], 0, len[par[u]] - 1, getpos(v), getpos(u) - 1);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v; u--; v--;
		g[u].push_back(v); g[v].push_back(u);
		U[i] = u; V[i] = v;
	}
	dfs(0, 0);
	for(int i = 0; i < n - 1; i++)
		if(tin[U[i]] > tin[V[i]])
			swap(U[i], V[i]);
	for(int i = 0; i < n; i++)
		if(par[i] == i)
			rt[i] = build(0, len[i] - 1);
	cin >> q;
	while(q--) {
		int type; cin >> type;
		if(type == 1) {
			int id; cin >> id; id--;
			int hed = par[V[id]];
			upd(rt[hed], 0, len[hed] - 1, getpos(V[id]), 1);
		} else if(type == 2) {
			int id; cin >> id; id--;
			int hed = par[V[id]];
			upd(rt[hed], 0, len[hed] - 1, getpos(V[id]), 0);
		} else {
			int u, v; cin >> u >> v; u--; v--;
			if(u == v) { cout << 0 << '\n'; continue; }
			if(tin[u] > tin[v]) swap(u, v);
			int anc = lca(u, v);
			if(u == anc) {
				if(sum(u, v) == dep[v] - dep[u]) cout << dep[v] - dep[u] << '\n';
				else cout << -1 << '\n';
			} else {
				if(sum(anc, u) + sum(anc, v) == dep[v] - dep[anc] + dep[u] - dep[anc]) cout << dep[v] - dep[anc] + dep[u] - dep[anc] << '\n';
				else cout << -1 << '\n';
			}
		}
	}
}