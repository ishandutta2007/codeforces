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
#define VI vector<int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
using namespace std;
const int N = 30015, base = 1e7 + 19, mod = 1e9 + 7;
int n, m, k, q, v[N], w[N], st[N], ans[N];
tuple<int, int, int> ooo[N];
VI t[N << 2], qry[N];
int tp, f[N][1015], res[N];
void add(int id) {
	int pd = 1;
	tp++; res[tp] = 0;
	rep(j, 0, k) {
		f[tp][j] = f[tp - 1][j];
		if(j >= w[id]) f[tp][j] = max(f[tp][j], f[tp - 1][j - w[id]] + v[id]);
		if(j > 0) {
			res[tp] += (ll) f[tp][j] * pd % mod;
			if(res[tp] >= mod) res[tp] -= mod;
			pd = (ll) pd * base % mod;
		}
	}
}
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)
void push(int p, int l, int r, int x, int y, int id) {
	if(x <= l && r <= y) return t[p].pb(id), void();
	if(x <= mid) push(ls, l, mid, x, y, id);
	if(y > mid) push(rs, mid + 1, r, x, y, id);
}
void dfs(int p, int l, int r) {
	int cur = tp;
	for(auto id : t[p]) add(id);
	if(l == r) for(auto x : qry[l]) ans[x] = res[tp];
	else dfs(ls, l, mid), dfs(rs, mid + 1, r);
	while(tp > cur) tp--;
}
int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	scanf("%d%d", &n, &k);
	rep(i, 1, n) scanf("%d%d", &v[i], &w[i]), st[i] = 1;
	scanf("%d", &q);
	int c1 = 0, c2 = 0;
	rep(i, 1, q) {
		int opt, x = 0, y = 0;
		scanf("%d", &opt);
		if(opt == 1) scanf("%d%d", &x, &y);
		if(opt == 2) scanf("%d", &x);
		if(opt == 3) c2++;
		else c1++;
		ooo[i] = make_tuple(opt, x, y);
	}
	m = q + 1;
	int clk = 1, top = 0;
	rep(i, 1, q) {
		int opt, x, y; tie(opt, x, y) = ooo[i];
		clk++;
		if(opt == 1) {
			n++;
			tie(st[n], v[n], w[n]) = make_tuple(clk, x, y);
		}
		if(opt == 2) push(1, 1, m, st[x], clk, x), st[x] = 0;
		if(opt == 3) qry[clk].pb(++top);
	}
	rep(i, 1, n) if(st[i] > 0) push(1, 1, m, st[i], clk, i);
	dfs(1, 1, m);
	rep(i, 1, top) printf("%d\n", ans[i]);
	return 0;
}