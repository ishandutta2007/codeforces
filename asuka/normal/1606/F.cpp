#include<bits/stdc++.h>
#define ll long long
#define N 200015
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
#define VI vector<int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
int n, q, V, c[N], par[N], ans[N], dfn[N], siz[N], son[N], dep[N], clk, top[N];
VI e[N];
vector<pii> que[N];
struct node {
	int c, m;
	bool operator < (const node &rhs) const {
		return (ll) (c - 1) * (rhs.m + 1) > (ll) (rhs.c - 1) * (m + 1);
	}
	node operator + (const node &rhs) const {
		return (node) {c + rhs.c, m + rhs.m};
	}
};
node sum[N];
namespace seg {
	#define ls (p << 1)
	#define rs (p << 1 | 1)
	node tr[N << 2], lazy[N << 2];
	void down(int p, node v) {
		tr[p] = tr[p] + v;
		lazy[p] = lazy[p] + v;
	} 
	void pushdown(int p) {
		down(ls, lazy[p]);
		down(rs, lazy[p]);
		lazy[p] = (node) {0, 0};
	}
	void add(int p, int l, int r, int x, int y, node v) {
		if(x <= l && r <= y) return down(p, v);
		pushdown(p);
		int mid = (l + r) >> 1;
		if(x <= mid) add(ls, l, mid, x, y, v);
		if(y > mid) add(rs, mid + 1, r, x, y, v);
	}
	node query(int p, int l, int r, int pos) {
		if(l == r) return tr[p];
		pushdown(p);
		int mid = (l + r) >> 1;
		if(pos <= mid) return query(ls, l, mid, pos);
		else return query(rs, mid + 1, r, pos);
	}
};
using namespace seg;
set<pair<node, int>> S;
int fa[N];
int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}
void dfs(int u, int pa) {
	par[u] = pa;
	dep[u] = dep[pa] + 1;
	siz[u] = 1;
	for(auto v : e[u]) if(v != pa) {
		c[u]++;
		dfs(v, u);
		siz[u] += siz[v];
		if(!son[u] || siz[v] > siz[son[u]]) son[u] = v;
	}
}
void dfs2(int u, int pa, int tp) {
	dfn[u] = ++clk;
	top[u] = tp;
	if(son[u]) dfs2(son[u], u, tp);
	for(auto v : e[u]) {
		if(v == pa || v == son[u]) continue;
		dfs2(v, u, v);
	}
}
void add(int u, int v, node val) {
	while(top[u] != top[v]) {
		add(1, 1, n, dfn[top[u]], dfn[u], val);
		u = par[top[u]];
	}
	add(1, 1, n, dfn[v], dfn[u], val);
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &n);
	rep(i, 1, n) fa[i] = i;
	rep(i, 2, n) {
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].pb(v);
		e[v].pb(u);
	}
	dfs(1, 0);
	dfs2(1, 0, 1);
	rep(i, 1, n) sum[i] = (node) {c[i], 0}, add(1, 1, n, dfn[i], dfn[i], sum[i]);
	scanf("%d", &q);
	rep(i, 1, q) {
		int v, k;
		scanf("%d%d", &v, &k);
		que[k].pb(mp(v, i));
		V = max(V, k);
	}
	rep(i, 1, n) S.insert(mp(sum[i], i));
	per(k, 0, V) {
		// printf("K %d\n", k);
		// for(auto x : S) printf("%d %d %d\n", x.fi.c, x.fi.m, x.se);
		while(SZ(S) > 0) {
			if(S.begin() -> fi.c - 1 < (ll) (S.begin() -> fi.m + 1) * k) break;
			int u = S.begin() -> se;
			S.erase(S.begin());
			if(!par[u]) continue;
			int v = find(par[u]);
			// printf("merge %d -> %d\n", u, v);
			S.erase(mp(sum[v], v));
			node val = sum[u] + (node) {-1, 1};
			sum[v] = sum[v] + val;
			fa[u] = v;
			add(par[u], v, val);
			// printf("add %d %d\n", par[u], v);
			// printf("sumv %d %d %d\n", sum[v].c, sum[v].m, v);
			if(par[v]) S.insert(mp(sum[v], v));
		}
		// rep(i, 1, n) {
		// 	node u = query(1, 1, n, dfn[i]);
		// 	printf("(%d %d) ", u.c, u.m);
		// }
		// printf("\n");
		for(auto x : que[k]) {
			node u = query(1, 1, n, dfn[x.fi]);
			ans[x.se] = u.c - u.m * k;
		}
	}
	rep(i, 1, q) printf("%d\n", ans[i]);
	return 0;
}
/*
8
6 7
3 2
8 3
5 7
7 4
7 1
7 3
5
1 0
1 2
1 3
7 1
5 0

20
2 1
3 1
4 2
5 3
6 4
7 1
8 5
9 5
10 4
11 6
12 3
13 10
14 5
15 7
16 11
17 3
18 7
19 15
20 6
1
13 1
15 1
18 1

*/