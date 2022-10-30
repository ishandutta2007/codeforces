#include <bits/stdc++.h>

#define pb push_back
#define rep(i, n) for (int i = 1 ; i <= (n) ; i++)
#define per(i, n) for (int i = (n) ; i >= 1 ; i--)
#define repi(n) for (int i = 1; i <= (n) ; i++)
#define mabs(n) ((n) > 0 ? (n) : (-n))
#define sqr(n) ((n) * (n))
#define print(V) for (auto v: V) printf("%d ",v)
using namespace std;
typedef pair<int, int> mp;
typedef long long LL ;
const int maxn = 8e5 + 5;
const int inf = 1 << 28;

vector<int> adj[maxn];
#define add(u, v) adj[u].pb(v)

int siz[maxn], top[maxn], par[maxn], mson[maxn];
int ans[maxn], n, m, ord[maxn], x[maxn], t[maxn];
int dfn[maxn], edfn[maxn], idx, pos[maxn], dep[maxn];
int maxd[maxn], rst[maxn], eff[maxn];

#define ls rt << 1
#define rs rt << 1 | 1
void build(int rt, int L, int R)
{
	rst[rt] = eff[rt] = -inf;
	if (L >= R) {maxd[rt] = dep[pos[L]]; return ;}
	int mid = L + R >> 1;
	build(ls, L, mid);
	build(rs, mid + 1, R);
	maxd[rt] = max(maxd[ls], maxd[rs]);
}
void effect(int rt, int val)
{
	eff[rt] = max(eff[rt], val);
	rst[rt] = max(rst[rt], maxd[rt] * 2 + val);
}
void pushdown(int rt)
{
	effect(ls, eff[rt]);
	effect(rs, eff[rt]);
}
void modify(int rt, int L, int R, int l, int r, int val)
{
	if (L >= l && R <= r) {effect(rt, val); return ;}
	int mid = L + R >> 1; pushdown(rt);
	if (l <= mid) modify(ls, L, mid, l, r, val);
	if (r > mid) modify(rs, mid + 1, R, l, r, val);
	rst[rt] = max( rst[ls], rst[rs]);
}
int query(int rt, int L, int R, int l, int r, int val)
{
	if (rst[rt] <= val) return 0;
	if (L >= R) return pos[L];
	int mid = L + R >> 1; pushdown(rt);
	if (r > mid) {
		int res = query(rs, mid + 1, R, l, r, val);
		if (res) return res;
	}
	if (l <= mid) {
		int res = query(ls, L, mid, l, r, val);
		if (res) return res;
	}
	return 0;
}

void dfs1(int u)
{
	siz[u] = 1;
	for (auto v : adj[u]) if (v != par[u])
	{
		par[v] = u; dep[v] = dep[u] + 1; dfs1(v);
		siz[u] += siz[v]; siz[v] > siz[mson[u]] ? mson[u] = v : 0;
	}
}
void dfs2(int u, int tp)
{
	dfn[u] = edfn[n] = ++idx; pos[idx] = u; top[u] = tp;
	if (mson[u]) dfs2(mson[u], tp);
	for (auto v : adj[u])
		if (v != par[u] && v != mson[u]) dfs2(v, v);
	edfn[u] = idx;
}
void modify(int u, int t, int val)
{
	while (top[u] != top[t])
	{
		modify(1, 1, n, dfn[top[u]], dfn[u], val);
		u = par[top[u]];
	}
	modify(1, 1, n, dfn[t], dfn[u], val);
}
int solve(int u, int val)
{
	while (top[u] != 1)
	{
		int res = query(1, 1, n, dfn[top[u]], dfn[u], val);
		if (res) return res;
		u = par[top[u]];
	}
	int res = query(1, 1, n, 1, dfn[u], val);
	return res ? res : 1;
}
bool cmp(int a, int b) {
	int ta = dep[x[a]] + t[a];
	int tb = dep[x[b]] + t[b];
	return ta != tb ? ta < tb : x[a] < x[b];
}
int main()
{
	#ifdef FILE_TEST
		freopen("tree.in", "r", stdin);
	#endif
	
	scanf("%d %d", &n, &m); ++n;
	for (int v, i = 2; i <= n; i++)
		scanf("%d", &v), add(v + 1, i);
	dfs1(1); dfs2(1, 1); build(1, 1, n);
	
	repi(m) scanf("%d %d", &x[i], &t[i]);
	repi(m) ord[i] = i, x[i]++;
	sort(ord + 1, ord + m + 1, cmp);
	
	repi(m) {
		int o = ord[i] , top = solve(x[o], t[o] + dep[x[o]]);
		ans[o] = t[o] + 2 * (dep[x[o]] - dep[top]);
		modify(x[o], top, ans[o] - dep[x[o]]);
	}
	repi(m) printf("%d ",ans[i]);
	return 0;
}