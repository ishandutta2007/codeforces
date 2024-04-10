#include <bits/stdc++.h>
 
using namespace std;
 
struct DSU {
	int n;
	vector<int> sz, par;
	DSU(int _n) {
		n = _n;
		sz.resize(n, 1);
		par.resize(n);
		for(int i = 0; i < n; i++) par[i] = i;
	}
	int find(int v) {
		return (v == par[v] ? v : par[v] = find(par[v]));
	}
	void unite(int u, int v, int &cnt) {
		u = find(u), v = find(v);
		if(u != v) {
			if(sz[u] < sz[v]) swap(u, v);
			par[v] = u; sz[u] += sz[v];
			--cnt;
		}
	}
};
 
struct node {
	int i1, i2, cnt;
	vector<int> v1, v2;
};
 
int n, m, q, a[10][100000], TMP;
node t[4 * 100000];
 
node merge(node x, node y) {
	node z;
	z.i1 = x.i1;
	z.i2 = y.i2;
	z.cnt = x.cnt + y.cnt;
	DSU dsu(4 * n);
	for(int i = 0; i < n; i++)
		if(a[i][x.i2] == a[i][y.i1])
			dsu.unite(x.v2[i], y.v1[i] + 2 * n, z.cnt);
	z.v1.resize(n);
	z.v2.resize(n);
	for(int i = 0; i < n; i++) {
		z.v1[i] = dsu.find(x.v1[i]);
		z.v2[i] = dsu.find(y.v2[i] + 2 * n);
	}
	int sz = 0;
	vector<int> re(4 * n, -1);
	for(int i = 0; i < n; i++) {
		if(re[z.v1[i]] == -1)
			re[z.v1[i]] = sz++;
		if(re[z.v2[i]] == -1)
			re[z.v2[i]] = sz++;
		z.v1[i] = re[z.v1[i]];
		z.v2[i] = re[z.v2[i]];
	}
	return z;
}
 
void build(int v, int l, int r) {
	if(l == r) {
		t[v].i1 = t[v].i2 = l;
		vector<int> vec(n);
		vec[0] = 0;
		t[v].cnt = 1;
		for(int i = 1; i < n; i++)
			if(a[i][l] == a[i - 1][l]) vec[i] = vec[i - 1];
			else {
				vec[i] = vec[i - 1] + 1;
				t[v].cnt++;
			}
		t[v].v1 = t[v].v2 = vec;
	} else {
		int m = (l + r) / 2;
		build(v * 2 + 1, l, m);
		build(v * 2 + 2, m + 1, r);
		t[v] = merge(t[v * 2 + 1], t[v * 2 + 2]);
	}
}
 
node get(int v, int l, int r, int l1, int r1) {
	if(l1 <= l && r <= r1) return t[v];
	int m = (l + r) / 2;
	if(m + 1 > r1) return get(v * 2 + 1, l, m, l1, r1);
	if(m < l1) return get(v * 2 + 2, m + 1, r, l1, r1);
	return merge(get(v * 2 + 1, l, m, l1, r1), get(v * 2 + 2, m + 1, r, l1, r1));
}
 
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m >> q;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> a[i][j];
	build(0, 0, m - 1);
	while(q--) {
		int l, r;
		cin >> l >> r;
		--l; --r;
		cout << get(0, 0, m - 1, l, r).cnt << '\n';
	}
}