#include<bits/stdc++.h>
#define ll long long
#define N 500015
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
int n, m;
bool istr[N];
pii edge[N];
namespace LCT {
	#define ls(p) ch[p][0]
	#define rs(p) ch[p][1]
	VI stk;
	int Max[N << 1], rev[N << 1], lazy[N << 1], fa[N << 1], ch[N << 1][2], siz[N << 1], val[N << 1];
	void pushup(int p) {
		siz[p] = siz[ls(p)] + siz[rs(p)] + (p > n);
		Max[p] = max({val[p], Max[ls(p)], Max[rs(p)]});
	}
	void rdown(int p) {
		rev[p] ^= 1;
		swap(ls(p), rs(p));
	}
	void ldown(int p, int v) {
		Max[p] = ((siz[p] > 0) ? v : 0);
		val[p] = p > n ? v : 0;
		lazy[p] = v;
	}
	void pushdown(int p) {
		if(rev[p]) rdown(ls(p)), rdown(rs(p));
		if(~lazy[p]) ldown(ls(p), lazy[p]), ldown(rs(p), lazy[p]);
		lazy[p] = -1;
		rev[p] = 0;
	}
	bool get(int p) {return rs(fa[p]) == p;}
	bool isroot(int p) {return ls(fa[p]) != p && rs(fa[p]) != p;}
	void rotate(int x) {
		int y = fa[x], z = fa[y], k = get(x);
		if(!isroot(y)) ch[z][ch[z][1] == y] = x;
		ch[y][k] = ch[x][!k];
		fa[ch[x][!k]] = y;
		ch[x][!k] = y;
		fa[y] = x;
		fa[x] = z;
		pushup(y);
		pushup(x);
	}
	void upd(int x) {
		stk.clear();
		while(1) {
			stk.pb(x);
			if(isroot(x)) break;
			x = fa[x];
		}
		per(i, 0, SZ(stk) - 1) pushdown(stk[i]);
	}
	void splay(int x) {
		upd(x);
		for(int f; f = fa[x], !isroot(x); rotate(x)) {
			if(!isroot(f)) rotate(get(x) == get(f) ? f : x);
		}
	}
	int access(int x) {
		int p;
		for(p = 0; x; p = x, x = fa[x]) {
			splay(x);
			rs(x) = p;
			pushup(x);
		}
		return p;
	}
	void makeroot(int p) {
		p = access(p);
		rdown(p);
	}
	void link(int x, int y) {
		makeroot(x);
		splay(x);
		fa[x] = y;
	}
	void cut(int x, int y) {
		makeroot(x);
		access(y);
		splay(y);
		fa[x] = ls(y) = 0;
	}
	void split(int x, int y) {
		makeroot(x);
		access(y);
		splay(y);
	}
	int findroot(int p) {
		access(p);
		splay(p);
		pushdown(p);
		while(ls(p)) p = ls(p), pushdown(p);
		splay(p);
		return p;
	}
	bool conn(int x, int y) {
		makeroot(x);
		return findroot(y) == x;
	}
};
using namespace LCT;
bool add(int x) {
	int u = edge[x].fi, v = edge[x].se;
	if(!conn(u, v)) {
		istr[x] = 1;
		link(u, x + n);
		link(x + n, v);
		return 1;
	}
	split(u, v);
	if(Max[v] == 0) {
		ldown(v, x);
		istr[x] = 0;
		return 1;
	}
	return 0;
}
void del(int x) {
	int u = edge[x].fi, v = edge[x].se;
	if(istr[x]) {
		split(u, v);
		int val = Max[v];
		cut(u, x + n);
		cut(x + n, v);
		if(val) {
			int U = edge[val].fi, V = edge[val].se;
			link(U, val + n);
			link(val + n, V);
			istr[val] = 1;
			split(u, v);
			ldown(v, 0);
		}
	} else {
		split(u, v);
		ldown(v, 0);
	}
	istr[x] = 0;
}

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	memset(lazy, -1, sizeof lazy);
	scanf("%d%d", &n, &m);
	rep(i, 1, m) scanf("%d%d", &edge[i].fi, &edge[i].se);
	int l = 1;
	ll ans = 0;
	for(int r = 1; r <= m; ++r) {
		while(!add(r)) del(l++);
		ans += r - l + 1;
	}
	printf("%lld\n", ans);
	return 0;
}