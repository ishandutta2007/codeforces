/**
 *    author:  Atreus
 *    created: 09.02.2019 00:31
**/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 1e5 + 10;
const int maxl = 21;
int par[maxn][20], sz[maxn], h[maxn];
vector<int> t[maxn];
int up[maxn], st[maxn], ft[maxn], pos[maxn], attack_time[maxn];
int n, root, r[maxn];
int newint = 2, lc[maxn * maxl], rc[maxn * maxl], seg[maxn * maxl];

int get(int id, int L, int R, int l, int r){
	if (L == l and R == r)
		return seg[id];
	int mid = (L + R) >> 1, ret = 0;
	if (l < mid)
		ret += get(lc[id], L, mid, l, min(mid, r));
	if (mid < r)
		ret += get(rc[id], mid, R, max(l, mid), r);
	return ret;
}

int add(int id, int L, int R, int idx){
	int newid = newint ++;
	seg[newid] = seg[id] - 1;
	lc[newid] = lc[id];
	rc[newid] = rc[id];
	if (L + 1 == R)
		return newid;
	int mid = (L + R) >> 1;
	if (idx < mid)
		lc[newid] = add(lc[id], L, mid, idx);
	else
		rc[newid] = add(rc[id], mid, R, idx);
	return newid;
}

void build(int id, int L, int R){
	seg[id] = R - L;
	if (L + 1 == R)
		return;
	int mid = (L + R) >> 1;
	lc[id] = newint, rc[id] = newint + 1;
	newint += 2;
	build(lc[id], L, mid);
	build(rc[id], mid, R);
}

int lastroot = 1;
int get(int root, int L, int R){
	return R - L - (get(root, 1, n + 1, L, R) - get(lastroot, 1, n + 1, L, R));
}


int find(int root, int v, int k){
	while (v != -1){
		int u = up[v];
		int x = get(root, st[u], st[v] + 1);
		if (x < k){
			k -= x;
			v = par[u][0];
			continue;
		}
		k -= get(root, st[v], st[v] + 1);
		if (k == 0)
			return v;
		for (int i = 18; i >= 0; i--){
			if (h[v] - (1 << i) >= h[u]){
				int x = get(root, st[par[v][i]], st[v]);
				if (x < k){
					k -= x;
					v = par[v][i];
				}
			}
		}
		return par[v][0];
	}
	return -1; // never 
}

int cnt(int root, int v){
	int ret = 0;
	while (v != -1){
		int u = up[v];
		ret += get(root, st[u], st[v] + 1);
		v = par[u][0];
	}
	return ret;
}

int lca(int v, int u){
	if (h[v] < h[u])
		swap(v, u);
	for (int i = 18; i >= 0; i--)
		if (h[v] - (1 << i) >= h[u])
			v = par[v][i];
	if (v == u)
		return v;
	for (int i = 18; i >= 0; i--){
		if (par[v][i] != par[u][i]){
			v = par[v][i];
			u = par[u][i];
		}
	}
	return par[v][0];
}

int get_par(int v, int x){
	for (int i = 0; i <= 18; i++)
		if (x & (1 << i))
			v = par[v][i];
	return v;
}

int Time = 1;
void dfs(int v, bool isheavy = 0){
	up[v] = v;
	if (isheavy)
		up[v] = up[par[v][0]];

	st[v] = Time++;
	for (auto u : t[v]){
		if (u == par[v][0])
			continue;
		dfs(u, u == t[v][0]);
	}
}

int dfs_sz(int v, int p = -1){
	par[v][0] = p;
	for (int i = 1; par[v][i - 1] != -1 and i <= 18; i++)
		par[v][i] = par[par[v][i - 1]][i - 1];

	sz[v] = 1;
	for (int i = 0; i < t[v].size(); i++){
		int u = t[v][i];
		if (u == p)
			continue;
		h[u] = h[v] + 1;
		sz[v] += dfs_sz(u, v);
		if (t[v][0] == p or sz[u] > sz[t[v][0]]){
			swap(t[v][i], t[v][0]);
		}
	}
	return sz[v];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	memset(par, -1, sizeof par);
	for (int v = 1; v <= n; v++){
		int u;
		cin >> u;
		if (u == 0)
			continue;
		t[v].push_back(u);
		t[u].push_back(v);
	}
	dfs_sz(1);
	dfs(1);
	int m;
	cin >> m;
	r[0] = 1;
	build(r[0], 1, n + 1);
	for (int i = 1; i <= m; i++){
		lastroot = r[i - 1];
		int type;
		cin >> type;
		if (type == 1){
			int v;
			cin >> v;
			r[i] = add(r[i - 1], 1, n + 1, st[v]);
		}
		else{
			r[i] = r[i - 1];
			int v, u, k, y;
			cin >> v >> u >> k >> y;
			int w = lca(v, u);
			if (v != w)
				v = par[v][0];
			else
				v = get_par(u, h[u] - h[v] - 1);
			if (v == u){
				cout << "-1\n";
				continue;
			}
			w = lca(v, u);
			if (u != w)
				u = par[u][0];
			else
				u = get_par(v, h[v] - h[u] - 1);
			w = lca(v, u);

			if (cnt(r[y], v) + cnt(r[y], u) - cnt(r[y], w) - cnt(r[y], par[w][0]) < k){
				cout << "-1\n";
				continue;
			}
			int x = cnt(r[y], v) - cnt(r[y], par[w][0]);
			if (x >= k)
				cout << find(r[y], v, k) << '\n';
			else{
				k -= x;
				x = cnt(r[y], u) - cnt(r[y], w);
				cout << find(r[y], u, x - k + 1) << endl;
			}
		}
	}
}