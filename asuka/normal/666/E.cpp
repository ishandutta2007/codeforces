#include<bits/stdc++.h>
#define ll long long
#define N 500015
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;

int n, m, q, pos[N];
char s[N];

namespace seg {
int rt[N * 20], ls[N * 20], rs[N * 20], Max[N * 20], id[N * 20], tot;
void pushup(int p) {
	if (Max[ls[p]] < Max[rs[p]]) Max[p] = Max[rs[p]], id[p] = id[rs[p]];
	else Max[p] = Max[ls[p]], id[p] = id[ls[p]];
}
void add(int &p, int l, int r, int pos, int val) {
	if (!p) p = ++tot;
	if (val >= Max[p]) Max[p] = val, id[p] = pos;
	if (l == r) return;
	int mid = (l + r) >> 1;
	if (pos <= mid)
		add(ls[p], l, mid, pos, val);
	else
		add(rs[p], mid + 1, r, pos, val);
}
int merge(int u, int v, int l, int r) {
	if (!u || !v) return u | v;
	int p = ++tot;
	if (l == r) {
		Max[p] = Max[u] + Max[v];
		id[p] = l;
		return p;
	}
	int mid = (l + r) >> 1;
	ls[p] = merge(ls[u], ls[v], l, mid);
	rs[p] = merge(rs[u], rs[v], mid + 1, r);
	pushup(p);
	return p;
}
pii query(int p, int l, int r, int x, int y) {
	if (x <= l && r <= y) {
		return mp(Max[p], -id[p]);
	}
	int mid = (l + r) >> 1;
	pii res = mp(0, 0);
	if (x <= mid) res = max(res, query(ls[p], l, mid, x, y));
	if (y > mid) res = max(res, query(rs[p], mid + 1, r, x, y));
	return res;
}
}
using namespace seg;
int fa[N << 2][23];
VI e[N << 2];
namespace SAM {

int link[N << 2], len[N << 2], ch[N << 2][27], sz, las;
void init() {
	link[0] = -1;
}
int insert(int c) {
	int cur = ++sz;
	len[cur] = len[las] + 1;
	int p = las;
	while (~p && !ch[p][c]) ch[p][c] = cur, p = link[p];
	if (p == -1) link[cur] = 0;
	else {
		int q = ch[p][c];
		if (len[q] == len[p] + 1) link[cur] = q;
		else {
			int clone = ++sz;
			len[clone] = len[p] + 1;
			link[clone] = link[q];
			link[q] = link[cur] = clone;
			rep(i, 0, 25) ch[clone][i] = ch[q][i];
			while (~p && ch[p][c] == q) ch[p][c] = clone, p = link[p];
		}
	}
	return las = cur;
}
void add(int u, int v) {
	e[u].pb(v); e[v].pb(u);
}
void dfs(int u, int pa) {
	fa[u][0] = pa;
	rep(i, 1, 19) fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (auto v : e[u]) if (v != pa) {
			dfs(v, u);
			rt[u] = merge(rt[u], rt[v], 1, m);
		}
}
void build() {
	rep(i, 1, sz) add(i, link[i]);
	dfs(0, -1);
}

int jump(int u, int L) {
	per(i, 0, 19) {
		if (len[fa[u][i]] >= L) u = fa[u][i];
	}
	return u;
}
}
using namespace SAM;
int main() {
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%s", s + 1);
	n = strlen(s + 1);
	init();
	rep(i, 1, n) pos[i] = insert(s[i] - 'a');
	scanf("%d", &m);
	rep(i, 1, m) {
		scanf("%s", s + 1);
		insert(26); // $
		for (int j = 1; s[j]; ++j) {
			int u = insert(s[j] - 'a');
			add(rt[u], 1, m, i, 1);
		}
	}
	build();
	scanf("%d", &q);
	rep(_, 1, q) {
		int l, r, pl, pr;
		scanf("%d%d%d%d", &l, &r, &pl, &pr);
		int u = jump(pos[pr], pr - pl + 1);
		pii res = query(rt[u], 1, m, l, r);
		if(res.fi == 0) res.se = -l;
		printf("%d %d\n", - res.se, res.fi);
	}
	return 0;
}