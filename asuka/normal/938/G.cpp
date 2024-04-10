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
using edge = array<int, 3>;
int n, m, q, ans[N];
map<pii, pii> M;
vector<edge> que[N], t[N << 2];
#define ls (p << 1)
#define rs (p << 1 | 1)
void push(int p, int l, int r, int x, int y, edge e) {
	if(x <= l && r <= y) return t[p].pb(e), void();
	int mid = (l + r) >> 1;
	if(x <= mid) push(ls, l, mid, x, y, e);
	if(y > mid) push(rs, mid + 1, r, x, y, e); 
}
pii stk[N << 1];
int top;
namespace UF {
	int fa[N], siz[N], tag[N];
	void init() {rep(i, 1, n) fa[i] = i, siz[i] = 1;}
	int find(int x) {return x == fa[x] ? x : find(fa[x]);}
	int ftag(int x) {return x == fa[x] ? 0 : (tag[x] ^ ftag(fa[x]));}
	void uni(int u, int v, int w) {
		w ^= ftag(u) ^ ftag(v);
		u = find(u);
		v = find(v);
		if(siz[u] < siz[v]) swap(u, v);
		siz[u] += siz[v];
		fa[v] = u;
		tag[v] = w;
		stk[++top] = mp(v, 0);
	}
}
using namespace UF;
namespace LB {
	int d[35];
	void insert(int x) {
		per(i, 0, 29) {
			if(!(x >> i & 1)) continue;
			if(!d[i]) {
				d[i] = x;
				stk[++top] = mp(i, 1);
				return;
			}
			x ^= d[i];
		}
	}
	int query(int x) {
		per(i, 0, 29) {
			if((x ^ d[i]) < x) x ^= d[i];
		}
		return x;
	}
}
using namespace LB;
void dfs(int p, int l, int r) {
	int cur = top;
	for(auto e : t[p]) {
		int u = e[0], v = e[1], w = e[2];
		if(find(u) == find(v)) {
			insert(w ^ ftag(u) ^ ftag(v));
		} else {
			uni(u, v, w);
		}
	}
	if(l == r) {
		for(auto u : que[l]) {
			ans[u[2]] = query(ftag(u[0]) ^ ftag(u[1]));
		}
	} else {
		int mid = (l + r) >> 1;
		dfs(ls, l, mid);
		dfs(rs, mid + 1, r);
	}
	while(top > cur) {
		pii u = stk[top--];
		if(u.se == 0) {
			siz[fa[u.fi]] -= siz[u.fi];
			fa[u.fi] = u.fi;
			tag[u.fi] = 0;
		} else d[u.fi] = 0;
 	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d", &n, &m);
	rep(i, 1, m) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		M[mp(u, v)] = mp(w, 1);
	}
	memset(ans, -1, sizeof ans);
	scanf("%d", &q);
	rep(i, 1, q) {
		int opt, x, y, d;
		scanf("%d%d%d", &opt, &x, &y);
		if(opt == 1) {
			scanf("%d", &d);
			M[mp(x, y)] = mp(d, i);
		} else if(opt == 2) {
			pii u = M[mp(x, y)];
			push(1, 1, q, u.se, i, {x, y, u.fi});
			M[mp(x, y)] = mp(-1, -1);
			// printf("[%d %d] (%d %d %d)\n", u.se, clk, x, y, u.fi);
		} else {
			que[i].pb({x, y, i});
		}
	}
	for(auto u : M) {
		if(u.se == mp(-1, -1)) continue;
		int x = u.fi.fi, y = u.fi.se, w = u.se.fi, t = u.se.se;
		push(1, 1, q, t, q, {x, y, w});
		// printf("[%d %d] (%d %d %d)\n", t, clk, x, y, w);
	}
	init();
	dfs(1, 1, q);
	rep(i, 1, q) if(~ans[i]) printf("%d\n", ans[i]);
	return 0;
}