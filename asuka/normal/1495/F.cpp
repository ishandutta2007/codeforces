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
int n, q, a[N], b[N], p[N], R[N], x[N];
VI vec[N], qry[N];
map<pii, ll> M;
int stk[N], top;
void getR() {
	rep(i, 1, n + 1) {
		while(top && p[stk[top]] < p[i]) R[stk[top--]] = i;
		stk[++top] = i;
	}
	per(i, 1, n) vec[R[i]].pb(i);
}
set<int> S;
void getQ() {
	S.insert(1);
	S.insert(n + 1);
	auto add = [&](int l, int r) {qry[r].pb(l);};
	add(1, n + 1);
	rep(i, 1, q) {
		scanf("%d", &x[i]);
		if(x[i] == 1) continue;
		auto it = S.find(x[i]);
		int l, r;
		if(it != S.end()) {
			l = *prev(it), r = *next(it);
			S.erase(x[i]);
		} else {
			it = S.lower_bound(x[i]);
			l = *prev(it), r = *it;
			S.insert(x[i]);
		}
		add(l, x[i]);
		add(x[i], r);
		add(l, r);
	}
}
void output() {
	S.clear();
	S.insert(1);
	S.insert(n + 1);
	ll ans = M[mp(1, n + 1)];
	rep(i, 1, q) {
		if(x[i] != 1) {
			auto it = S.find(x[i]);
			int l, r;
			if(it != S.end()) {
				l = *prev(it), r = *next(it);
				ans -= M[mp(l, x[i])];
				ans -= M[mp(x[i], r)];
				ans += M[mp(l, r)];
				S.erase(x[i]);
			} else {
				it = S.lower_bound(x[i]);
				l = *prev(it), r = *it;
				ans += M[mp(l, x[i])];
				ans += M[mp(x[i], r)];
				ans -= M[mp(l, r)];
				S.insert(x[i]);
			}
		}
		printf("%lld\n", ans);
	}
}
namespace LCT {
	#define M N << 2
	#define ls(p) ch[p][0]
	#define rs(p) ch[p][1]
	int lazy[M], ch[M][2], fa[M];
	ll sum[M], W[M];
	pii from[M];
	int get(int p) {return rs(fa[p]) == p;}
	bool isroot(int p) {return ls(fa[p]) != p && rs(fa[p]) != p;}
	void pushup(int p) {sum[p] = sum[ls(p)] + sum[rs(p)] + W[p];}
	void down(int p){swap(ls(p), rs(p)); lazy[p] ^= 1;}
	void pushdown(int p) {
		if(lazy[p]) {
			down(ls(p));
			down(rs(p));
		}
		lazy[p] = 0;
	}
	void rotate(int x) {
		int y = fa[x], z = fa[y], k = get(x);
		if(!isroot(y)) ch[z][y == ch[z][1]] = x;
		fa[ch[x][!k]] = y;
		ch[y][k] = ch[x][!k];
		ch[x][!k] = y;
		fa[y] = x;
		fa[x] = z;
		pushup(y);
		pushup(x);
	}
	VI stk;
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
		down(p);
	}
	void split(int x, int y) {
		makeroot(x);
		access(y);
		splay(y);
	}
	void link(int x, int y) {
		makeroot(x);
		splay(x);
		fa[x] = y;
	}
	void cut(int x, int y) {
		split(x, y);
		ls(y) = fa[x] = 0;
	}
	#undef M
};
using namespace LCT;
int cnt;
void init() {
	cnt = n + 1;
	rep(i, 1, n) from[i] = mp(-1, -1);
}
void Link(int u, int v, ll w) {
	if(from[u] != mp(-1, -1)) {
		int e = from[u].fi, to = from[u].se;
		cut(u, e);
		cut(e, to);
	}
	from[u] = mp(++cnt, v);
	W[cnt] = w;
	link(u, cnt);
	link(cnt, v);
}
ll query(int l, int r) {
	split(l, r);
	return sum[r];
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d", &n, &q);
	rep(i, 1, n) scanf("%d", &p[i]);
	p[n + 1] = n + 1;
	rep(i, 1, n) scanf("%d", &a[i]);
	rep(i, 1, n) scanf("%d", &b[i]);
	getR();
	getQ();
	init();
	rep(i, 2, n + 1) {
		Link(i - 1, i, a[i - 1]);
		for(auto u : vec[i]) {
			// printf("Try %lld\n", query(u, i));
			Link(u, i, min(query(u, i), (ll) b[u]));
		}
		for(auto l : qry[i]) {
			M[mp(l, i)] = query(l, i);
		}
	}
	output();
	return 0;
}