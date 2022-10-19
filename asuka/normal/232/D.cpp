#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
const int N = 400015, M = N * 19;
int rt[N], ls[M], rs[M], sum[M], tot;

void pull(int p) {sum[p] = sum[ls[p]] + sum[rs[p]];}

void ins(int &p, int l, int r, int x) {
	if (!p) p = ++tot;

	if (l == r) return sum[p] = 1, void();

	int mid = (l + r) >> 1;

	if (x <= mid)
		ins(ls[p], l, mid, x);
	else
		ins(rs[p], mid + 1, r, x);

	pull(p);
}

int merge(int u, int v, int l, int r) {
	if (!u || !v) return u | v;

	int p = ++tot;

	if (l == r) {
		sum[p] = sum[u] + sum[v];
		return p;
	}

	int mid = (l + r) >> 1;
	ls[p] = merge(ls[u], ls[v], l, mid);
	rs[p] = merge(rs[u], rs[v], mid + 1, r);
	pull(p);
	return p;
}

int ask(int p, int l, int r, int x, int y) {
	if (!p || x > y) return 0;

	if (x <= l && r <= y) return sum[p];

	int res = 0, mid = (l + r) >> 1;

	if (x <= mid) res += ask(ls[p], l, mid, x, y);

	if (y > mid) res += ask(rs[p], mid + 1, r, x, y);

	return res;
}

int link[N], len[N], fa[N][20], sz, las;
map<int, int> ch[N];

void init() { link[0] = -1; }

int insert(int c) {
	int cur = ++sz;
	len[cur] = len[las] + 1;
	int p = las;

	while (~p && ch[p].count(c) == 0) ch[p][c] = cur, p = link[p];

	if (p == -1) link[cur] = 0;
	else {
		int q = ch[p][c];

		if (len[q] == len[p] + 1) link[cur] = q;
		else {
			int clone = ++sz;
			len[clone] = len[p] + 1;
			link[clone] = link[q];
			link[q] = link[cur] = clone;
			ch[clone] = ch[q];

			while (~p && ch[p][c] == q) ch[p][c] = clone, p = link[p];
		}
	}

	return las = cur;
}

int n, h[N], q, pos[N];
vector<int> e[N];

void dfs(int u) {
	fa[u][0] = max(0, link[u]);

	rep(j, 1, 19) fa[u][j] = fa[fa[u][j - 1]][j - 1];

	for (int v : e[u]) {
		dfs(v);
		rt[u] = merge(rt[u], rt[v], 1, n);
	}
}

int jump(int u, int l) {
	int x = u;

	per(j, 0, 19) {
		if (len[fa[x][j]] >= l) x = fa[x][j];
	}

	return x;
}

int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	init();
	scanf("%d", &n);

	rep(i, 1, n) scanf("%d", &h[i]);

	rep(i, 2, n) pos[i] = insert(h[i] - h[i - 1]);

	insert(inf);

	rep(i, 2, n) {
		int u = insert(h[i - 1] - h[i]);
		ins(rt[u], 1, n, i);
	}

	rep(i, 1, sz) e[link[i]].pb(i);

	dfs(0);
	scanf("%d", &q);

	rep(_, 1, q) {
		int l, r;
		scanf("%d%d", &l, &r);

		if (l == r) {
			printf("%d\n", n - 1);
			continue;
		}

		int u = jump(pos[r], r - l);
		printf("%d\n", ask(rt[u], 1, n, 1, l - 1) + ask(rt[u], 1, n, r + r - l + 1, n));
	}

	return 0;
}