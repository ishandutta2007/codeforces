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
const int N = 100015;
int n, q, fa[N], siz[N], son[N], dfn[N], clk, top[N];
VI e[N];
void dfs0(int u) {
	siz[u] = 1;
	for(auto v : e[u]) {
		dfs0(v);
		siz[u] += siz[v];
		if(siz[v] > siz[son[u]]) son[u] = v;
	}
}
void dfs1(int u, int tp) {
	dfn[u] = ++clk; top[u] = tp;
	if(son[u]) dfs1(son[u], tp);
	for(auto v : e[u]) if(v != son[u]) dfs1(v, v);
}
namespace seg {
	struct info {
		int rem, ext;
		void fix() {int x = min(rem, ext); rem -= x; ext -= x;}
		info operator + (const info &o) const {
			info res = (info) {rem + o.rem, ext + o.ext};
			res.fix();
			return res;
		}
		info operator * (const info &o) const {
			if(ext < o.rem) return (info) {rem + o.rem - ext, o.ext};
			else return (info) {rem, o.ext + ext - o.rem};
		}
	} t[N << 2];
	#define ls (p << 1)
	#define rs (p << 1 | 1)
	bool tag[N << 2]; // {len, 0}
	void pushup(int p) {t[p] = t[ls] * t[rs];}
	void down(int p, int l, int r) {
		t[p] = (info) {r - l + 1, 0};
		tag[p] = 1;
	}
	void pushdown(int p, int l, int r) {
		if(tag[p]) {
			int mid = (l + r) >> 1;
			down(ls, l, mid);
			down(rs, mid + 1, r);
			tag[p] = 0;
		}
	}
	void add(int p, int l, int r, int pos, info val) {
		if(l == r) return t[p] = t[p] + val, void();
		int mid = (l + r) >> 1;
		pushdown(p, l, r);
		if(pos <= mid) add(ls, l, mid, pos, val);
		else add(rs, mid + 1, r, pos, val);
		pushup(p);
	}
	void reset(int p, int l, int r, int x, int y) {
		if(x <= l && r <= y) return down(p, l, r), void();
		int mid = (l + r) >> 1;
		pushdown(p, l, r);
		if(x <= mid) reset(ls, l, mid, x, y);
		if(y > mid) reset(rs, mid + 1, r, x, y);
		pushup(p);
	}
	info query(int p, int l, int r, int x, int y) {
		if(x <= l && r <= y) return t[p];
		int mid = (l + r) >> 1;
		info res = (info) {0, 0};
		pushdown(p, l, r);
		if(x <= mid) res = res * query(ls, l, mid, x, y);
		if(y > mid) res = res * query(rs, mid + 1, r, x, y);
		return res;
	}
}
using namespace seg;
info qry(int u) {
	if(!u) return (info) {0, 0};
	return qry(fa[top[u]]) * query(1, 1, n, dfn[top[u]], dfn[u]);
}
void cover(int u) {
	info o = qry(fa[u]);
	reset(1, 1, n, dfn[u], dfn[u] + siz[u] - 1);
	add(1, 1, n, dfn[u], (info) {o.ext, 0});
}
bool color(int u) {
	info o = qry(fa[u]), oo = query(1, 1, n, dfn[u], dfn[u]);
	return ((info) {0, o.ext} * oo).rem == 0;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d", &n, &q);
	rep(i, 2, n) scanf("%d", &fa[i]), e[fa[i]].pb(i);
	dfs0(1); 
	dfs1(1, 1);
	reset(1, 1, n, 1, n);
	rep(_, 1, q) {
		int o, x;
		scanf("%d%d", &o, &x);
		if(o == 1) add(1, 1, n, dfn[x], (info) {0, 1});
		if(o == 2) cover(x);
		if(o == 3) puts(color(x) ? "black" : "white");
	}
	return 0;
}