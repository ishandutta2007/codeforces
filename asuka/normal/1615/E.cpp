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
using namespace std;
const int N = 200015;
int n, k, dfn[N], dep[N], clk, rev[N], ed[N], fa[N];
bool vis[N];
VI e[N];
namespace seg {
	pii val[N << 2], Max[N << 2];
	int tag[N << 2];
	#define ls (p << 1)
	#define rs (p << 1 | 1)
	#define mid ((l + r) >> 1)
	void pushup(int p) {
		val[p] = max(val[ls], val[rs]);
		Max[p] = max(Max[ls], Max[rs]);
	}
	void down(int p, int v) {
		if(tag[p] == -1) return;
		v = tag[p] = max(v, tag[p]);
		val[p] = min(val[p], mp(Max[p].fi - v, Max[p].se));
	}
	void pushdown(int p) {
		down(ls, tag[p]);
		down(rs, tag[p]);
	}
	void build(int p, int l, int r) {
		if(l == r) {
			Max[p] = mp(dep[rev[l]], rev[l]);
			val[p] = mp(dep[rev[l]], rev[l]);
			return;
		}
		build(ls, l, mid); build(rs, mid + 1, r);
		pushup(p);
	}
	void modify(int p, int l, int r, int x, int y, int v) {
		if(x <= l && r <= y) return down(p, v);
		pushdown(p);
		if(x <= mid) modify(ls, l, mid, x, y, v);
		if(y > mid) modify(rs, mid + 1, r, x, y, v);
		pushup(p);
	}
	void del(int p, int l, int r, int pos) {
		if(l == r) return Max[p] = val[p] = mp(-1, -1), tag[p] = -1, void();
		pushdown(p);
		if(pos <= mid) del(ls, l, mid, pos);
		else del(rs, mid + 1, r, pos);
		pushup(p);
	}
	int query() {return val[1].se;}
}
using namespace seg;
void dfs(int u, int pa) {
	fa[u] = pa;
	dfn[u] = ++clk;
	rev[clk] = u;
	dep[u] = dep[pa] + 1;
	for(auto v : e[u]) if(v != pa) {
		dfs(v, u);
	}
	ed[u] = clk;
} 
int main() {
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d", &n, &k);
	rep(i, 2, n) {
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].pb(v);
		e[v].pb(u);
	}
	dfs(1, 0);
	build(1, 1, n);
	vis[0] = 1;
	auto calc = [](int x, int y) -> ll {
		int lef = n - x - y;
		int o = min(x, lef);
		x -= o; lef -= o;
		if(lef == 0) return (ll) x * y;
		int oo = min(y, lef);
		x -= oo; lef -= oo;
		if(lef == 0) return (ll) x * y;
		int t = lef / 2;
		return (ll) -1ll * (ll) (max(-x, y) + t) * ((ll) min(-x, y) + lef - t);
	};
	int y = 0;
	ll ans = -infll;
	rep(x, 1, k) {
		int u = query(), _u = u;
		VI stk;
		while(!vis[u] && u > 0) stk.pb(u), u = fa[u];
		y += SZ(stk) - 1;
		reverse(all(stk));
		for(auto o : stk) modify(1, 1, n, dfn[o], ed[o], dep[o]), vis[o] = 1;
		del(1, 1, n, dfn[_u]);
		// printf("%d %d %lld\n", x, y, calc(x, y));
		ans = max(ans, calc(x, y));
	}
	ans = max(ans, calc(k, 0));
	printf("%lld\n", ans);
	return 0;
}