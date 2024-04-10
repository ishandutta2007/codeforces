#include <bits/stdc++.h>
using namespace std;
const int N = 50005;
struct Node {
	long long sum;
	int tag;
	Node *lson, *rson;
} *rt[N], *null;
int n, m, Q, C, f[N], c[N], pa[N], dep[N], sz[N], son[N], top[N], dfn[N], pos[N], dfc;
vector<int> G[N];
long long sumd[N], sum2[N];
void dfs1(int u, int depth) {
	dep[u] = depth;
	sz[u] = 1;
	for (int v : G[u]) {
		dfs1(v, depth + 1);
		sz[u] += sz[v];
		if (sz[son[u]] < sz[v]) son[u] = v;
	}
}
void dfs2(int u, int tp) {
	pos[dfn[u] = ++dfc] = u;
	top[u] = tp;
	if (son[u]) {
		dfs2(son[u], tp);
	}
	for (int v : G[u]) if (v != son[u]) {
		dfs2(v, v);
	}
}
long long Qry(Node *&i, int l, int r, int lf, int rg, int tag) {
	if (lf <= l && r <= rg) return i -> sum + 1ll * tag * (r - l + 1);
	int mid = (l + r) >> 1;
	long long ret = 0;
	if (lf <= mid) ret += Qry(i -> lson, l, mid, lf, rg, tag + i -> tag);
	if (rg > mid) ret += Qry(i -> rson, mid + 1, r, lf, rg, tag + i -> tag);
	return ret;
}
void Add(Node *&i, int l, int r, int lf, int rg, int ty) {
	if (i == null) {
		i = new Node();
		*i = *null;
	}
	if (lf <= l && r <= rg) {
		i -> tag += ty;
		i -> sum += ty * (r - l + 1);
	} else {
		int mid = (l + r) >> 1;
		if (lf <= mid) Add(i -> lson, l, mid, lf, rg, ty);
		if (rg > mid) Add(i -> rson, mid + 1, r, lf, rg, ty);
		i -> sum = i -> lson -> sum + i -> rson -> sum + i -> tag * (r - l + 1);
	}
	if (!(i -> tag) && !(i -> sum)) {
		delete i;
		i = null;
	}
}
void Add(int idx, int u, int ty) {
	while (u) {
		Add(rt[idx], 1, n, dfn[top[u]], dfn[u], ty);
		u = pa[top[u]];
	}
}
long long Qry(int idx, int u) {
	long long ret = 0;
	while (u) {
		ret += Qry(rt[idx], 1, n, dfn[top[u]], dfn[u], 0);
		u = pa[top[u]];
	}
	return ret;
}
void Modify(int idx, int u, int ty) {
	sumd[idx] += ty * dep[u];
	if (ty == 1) {
		sum2[idx] += ty * Qry(idx, u);
		Add(idx, u, ty);
	} else {
		Add(idx, u, ty);
		sum2[idx] += ty * Qry(idx, u);
	}
}
int main() {
	null = new Node();
	null -> tag = null -> sum = 0;
	null -> lson = null -> rson = null;
	scanf("%d%d%d%d", &n, &m, &Q, &C);
	for (int i = 1; i <= m; i++) rt[i] = null;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &f[i]);
	}
	for (int i = 2; i <= n; i++) {
		scanf("%d", &pa[i]);
		G[pa[i]].push_back(i);
	}
	for (int i = 1; i <= m; i++) scanf("%d", &c[i]);
	dfs1(1, 1);
	dfs2(1, 1);
	for (int i = 1; i <= n; i++) Modify(f[i], i, 1);
	while (Q--) {
		int op;
		scanf("%d", &op);
		if (op == 1) {
			int u, k;
			scanf("%d%d", &u, &k);
			Modify(f[u], u, -1);
			f[u] = k;
			Modify(f[u], u, 1);
		} else {
			int k;
			scanf("%d", &k);
			double ans = (1.0 * (sum2[k] * 2 + sumd[k]) * c[k] * c[k] - 2.0 * sumd[k] * C * c[k]) / n + 1.0 * C * C;
			printf("%.10lf\n", ans);
		}
	}
	return 0;
}