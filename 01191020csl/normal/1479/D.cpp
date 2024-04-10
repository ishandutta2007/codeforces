#include<bits/stdc++.h>
using namespace std;
int head[300001], ver[600001], nxt[600001], sz;
void addedge(int u, int v) {
	ver[++sz] = v, nxt[sz] = head[u], head[u] = sz;
	ver[++sz] = u, nxt[sz] = head[v], head[v] = sz;
}
const int m1 = 998244353, m2 = 19260817;
int pw1[300001], pw2[300001];
struct node {
	int ls, rs;
	int h1, h2;
}nd[20000001];
int tot;
void insert(int &p, int np, int l, int r, int x) {
	nd[p] = nd[np];
	if (l == r) {
		nd[p].h1 ^= 1, nd[p].h2 ^= 1;
		return;
	}
	int mid = (l + r) / 2;
	if (x <= mid) nd[p].ls = ++tot, insert(nd[p].ls, nd[np].ls, l, mid, x);
	else nd[p].rs = ++tot, insert(nd[p].rs, nd[np].rs, mid + 1, r, x);
	nd[p].h1 = (1ll*pw1[r-mid]*nd[nd[p].ls].h1+nd[nd[p].rs].h1)%m1;
	nd[p].h2 = (1ll*pw2[r-mid]*nd[nd[p].ls].h2+nd[nd[p].rs].h2)%m2;
}
int getres(int p, int l, int r, int x) {
	if (!p) return 0;
	if (l == r) return nd[p].h1;
	int mid = (l + r) / 2;
	if (x <= mid) return getres(nd[p].ls, l, mid, x);
	else return getres(nd[p].rs, mid + 1, r, x);
}
int query(int p1, int p2, int l, int r, int l0, int r0, int x, int op) {
	if (l >= l0 && r <= r0) {
		long long h1 = nd[p1].h1, h2 = nd[p2].h1, h3 = nd[p1].h2, h4 = nd[p2].h2;
		if (x >= l && x <= r) {
			if (op) h1 = (m1+h1-pw1[r-x])%m1, h3 = (m2+h3-pw2[r-x])%m2;
			else h1 = (h1+pw1[r-x])%m1, h3 = (h3+pw2[r-x])%m2;
		}
		if (h1 == h2 && h3 == h4) return -1;
		if (l == r) return l;
		int mid = (l + r) / 2, res;
		res = query(nd[p1].rs, nd[p2].rs, mid + 1, r, l0, r0, x, op);
		if (res > -1) return res;
		res = query(nd[p1].ls, nd[p2].ls, l, mid, l0, r0, x, op);
		assert(res!=-1);
		return res;
	}
	int mid = (l + r) / 2, res = -1;
	if (l0 <= mid) res = query(nd[p1].ls, nd[p2].ls, l, mid, l0, r0, x, op);
	if (res != -1) return res;
	if (r0 > mid) res = query(nd[p1].rs, nd[p2].rs, mid + 1, r, l0, r0, x, op);
	return res;
}
int n, rt[300001];
int a[300001], fa[300001], dep[300001], f[300001][20];
void dfs(int x) {
	for (int i = head[x]; i; i = nxt[i])
		if (fa[x] != ver[i]) {
			fa[ver[i]] = x;
			dep[ver[i]] = dep[x] + 1;
			rt[ver[i]] = ++tot, insert(rt[ver[i]], rt[x], 1, n, a[ver[i]]);
			dfs(ver[i]);
		}
}
int lca(int u, int v) {
	if (dep[u] < dep[v]) swap(u, v);
	for (int i = 19; i >= 0; i--)
		if (dep[f[u][i]] >= dep[v])
			u = f[u][i];
	if (u == v) return u;
	for (int i = 19; i >= 0; i--)
		if (f[u][i] != f[v][i])
			u = f[u][i], v = f[v][i];
	return f[u][0];
}
int main() {
	int q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		addedge(u, v);
	}
	pw1[0] = pw2[0] = 1;
	for (int i = 1; i <= n; i++)
		pw1[i] = 1ll*pw1[i-1]*13331%m1, pw2[i] = 1ll*pw2[i-1]*13331%m2;
	rt[1] = tot = 1, insert(rt[1], rt[0], 1, n, a[1]);
	dep[1] = 1, dfs(1);
	for (int i = 1; i <= n; i++) f[i][0] = fa[i];
	for (int j = 1; j < 20; j++)
		for (int i = 1; i <= n; i++)
			f[i][j] = f[f[i][j-1]][j-1];
	for (int i = 1; i <= q; i++) {
		int u, v, l, r;
		cin >> u >> v >> l >> r;
		int p = lca(u, v);
		int test = getres(rt[u], 1, n, a[p]);
		cout << query(rt[u], rt[v], 1, n, l, r, a[p], test) << endl;
	}
}