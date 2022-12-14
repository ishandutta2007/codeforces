#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e5 + 10;

struct Edge {
	int v;
	int u;
	int w;

	bool operator < (const Edge &other) const {
		return w < other.w;
	}
} e[maxn];

struct Node {
	int mxst; 	// maximum starting time
	int mxm; 	// maximum starting time among active stores
	int mnst; 	// minimum starting time
	int mnm;	// minimum starting time among active stores
	int lazy = -1;
	int pff;
} seg[4 * maxn];

int n, par[maxn], r[maxn], st[maxn], W[maxn];
vector<pair<int,int>> g[maxn];

int get(int id, int L, int R, int l, int r) {
	if (r <= L or R <= l)
		return -1;
	if (l <= L and R <= r)
		return seg[id].pff;
	int mid = (L + R) >> 1;
	return max(get(2 * id + 0, L, mid, l, r), get(2 * id + 1, mid, R, l, r));
}

void shift(int, int, int, int);

void change(int id, int L, int R, int l, int r, bool w) {
	if (r <= L or R <= l)
		return;
	if (l <= L and R <= r) {
		if (w == 0)
			seg[id].mxm = -1, seg[id].mnm = maxn;
		else
			seg[id].mxm = seg[id].mxst, seg[id].mnm = seg[id].mnst;
		seg[id].lazy = w;
		return;
	}
	int mid = (L + R) >> 1;
	shift(id, L, R, mid);
	change(2 * id + 0, L, mid, l, r, w);
	change(2 * id + 1, mid, R, l, r, w);
	seg[id].mxm = max(seg[2 * id + 0].mxm, seg[2 * id + 1].mxm);
	seg[id].mnm = min(seg[2 * id + 0].mnm, seg[2 * id + 1].mnm);
}

void shift(int id, int L, int R, int mid) {
	if (seg[id].lazy == -1)
		return;
	change(2 * id + 0, L, mid, L, mid, seg[id].lazy);
	change(2 * id + 1, mid, R, mid, R, seg[id].lazy);
	seg[id].lazy = -1;
}

int dis(int l, int r) {
	if (l > r)
		swap(l, r);
	return get(1, 1, n + 1, l + 1, r + 1);
}

void build(int id, int L, int R) {
	seg[id].mxm = seg[id].lazy = -1;
	seg[id].mnm = maxn;
	if (L + 1 == R) {
		seg[id].mxst = seg[id].mnst = st[L];
		seg[id].pff = W[L];
		return;
	}
	int mid = (L + R) >> 1;
	build(2 * id + 0, L, mid);
	build(2 * id + 1, mid, R);
	seg[id].mxst = max(seg[2 * id + 0].mxst, seg[2 * id + 1].mxst);
	seg[id].mnst = min(seg[2 * id + 0].mnst, seg[2 * id + 1].mnst);
	seg[id].pff = max(seg[2 * id + 0].pff, seg[2 * id + 1].pff);
}

int find(int v) { 
	return par[v] < 0 ? v : par[v] = find(par[v]); 
}

void dfs(int v, int p = -1) {
	static int Time = 1;
	st[v] = Time++;
	for (auto [u, w] : g[v])
		if (u != p) {
			W[Time] = w;
			dfs(u, v);
		}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int q;
	cin >> n >> q;
	for (int i = 0; i < n - 1; i++) {
		int v, u, w;
		cin >> v >> u >> w;
		e[i] = {v,u,w};
	}
	for (int i = 1; i <= n; i++)
		r[i] = i;
	sort(e, e + n - 1);
	memset(par, -1, sizeof par);
	for (int i = 0; i < n - 1; i++) {
		int v = find(e[i].v), u = find(e[i].u);
		int w = e[i].w;
		g[r[v]].push_back({u,w});
		g[u].push_back({r[v],w});
		r[v] = r[u];
		par[u] = v;
	}
	int src = find(1);
	for (int i = 1; i <= n; i++)
		assert(g[i].size() <= 2);
	dfs(src);
	build(1, 1, n + 1);
	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int l, r;
			cin >> l >> r;
			change(1, 1, n + 1, l, r + 1, 1);
		}
		else if (t == 2) {
			int l, r;
			cin >> l >> r;
			change(1, 1, n + 1, l, r + 1, 0);
		}
		else {
			int x;
			cin >> x;
			if (seg[1].mxm == -1)
				cout << -1 << '\n';
			else
				cout << max(dis(st[x], seg[1].mnm), dis(st[x], seg[1].mxm)) << '\n';
		}
	}
}