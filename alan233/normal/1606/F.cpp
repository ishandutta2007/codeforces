#include <bits/stdc++.h>
using namespace std;
#define rep(i, x, y) for(int i = x, i##end = y; i <= i##end; ++i)
#define per(i, x, y) for(int i = x, i##end = y; i >= i##end; --i)
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
typedef long long LL;
typedef double db;
inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while(!isdigit(ch)) { if(ch == '-') f = 0; ch = getchar(); }
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? x : -x;
}

const int N = 200005;
vector<int> adj[N];
int n, m, fa[N], a[N], siz[N], dfn[N], tmr;
LL ans[N];
vector<int> e[N];
struct node {
	LL val, key; int siz, u;
	node() { val = siz = 0; }
	node(LL v_, int s_, int u_) { val = v_, siz = s_, u = u_, key = ceil((db)-val / siz); } 
	inline bool operator == (const node &t) const { return key == t.key && u == t.u; }
	inline bool operator < (const node &t) const {// -val / siz < -t.val / t.siz
		return key != t.key ? key > t.key : u > t.u;
	}
};
struct QUE {
	int u, x, id;
	inline bool operator < (const QUE &t) const {
		return x < t.x;
	}
} q[N];
namespace Set {
	priority_queue<node> pq, del;
	inline void insert(const node &t) { pq.push(t); }
	inline void erase(const node &t) { del.push(t); }
	inline node top() {
		while(!del.empty() && del.top() == pq.top()) del.pop(), pq.pop();
		return pq.top();
	}
	inline bool empty() { return pq.size() == del.size(); }
}
int F[N];
struct BIT {
	LL tr[N];
	inline void add(int x, LL d) { if(!x) return; for(int i = x; i <= n; i += i & - i) tr[i] += d; }
	inline LL ask(int x) { LL res = 0; for(int i = x; i > 0; i -= i & -i) res += tr[i]; return res; }
	inline LL ask(int l, int r) { return ask(r) - ask(l - 1); }
} tr[2];//tr[0] : siz; tr[1] : sum

inline int anc(int x) { return x == F[x] ? x : F[x] = anc(F[x]); }
inline void init_DSU() { rep(i, 1, n) F[i] = i; }

int heng[N], hengid;

void dfs1(int u, int fa) {
  ++hengid, heng[hengid] = u;
	siz[u] = 1, dfn[u] = ++tmr;
	for(int v : adj[u]) {
	  if (v == fa) continue;
	  a[u]++; ::fa[v] = u;
    dfs1(v, u), siz[u] += siz[v];
  }
	if(u != 1) Set::insert(node(a[u], 1, u));
}
#define getsz(u) (tr[0].ask(dfn[u], dfn[u] + siz[u] - 1))
#define getsm(u) (tr[1].ask(dfn[u], dfn[u] + siz[u] - 1))
inline void link(int u) {
	int sz = getsz(u);
	LL sm = getsm(u);
	F[u] = anc(fa[u]);
	if(F[u] != 1) {
		Set::erase(node(getsm(F[u]), getsz(F[u]), F[u]));
	}
	tr[0].add(dfn[fa[u]], sz), tr[1].add(dfn[fa[u]], sm);
	if(F[u] != 1) {
		int gfa = fa[F[u]];
		tr[0].add(dfn[gfa], -sz), tr[1].add(dfn[gfa], -sm);
		Set::insert(node(getsm(F[u]), getsz(F[u]), F[u]));
	}
}
signed main() {
	n = read(), init_DSU();
	rep(i, 1, n - 1) {
	  int u = read(), v = read();
	  adj[u].pb(v), adj[v].pb(u);
  }
	m = read();
	rep(i, 1, m) {
	  q[i].u = read(), q[i].x = -read() - 1, q[i].id = i;
	  ans[i] -= q[i].x;
  }
	dfs1(1, 0), sort(q + 1, q + m + 1);
//	rep(i, 1, n) {
//	  printf("val[%d] = %d\n", i, a[i]);
//  }
//	return 0;
	rep(_, 1, n) {
	  int i = heng[_];
		tr[0].add(dfn[i], 1), tr[1].add(dfn[i], a[i]);
		if(i != 1) tr[0].add(dfn[fa[i]], -1), tr[1].add(dfn[fa[i]], -a[i]);
	}
	rep(i, 1, m) {
		int u = q[i].u, x = q[i].x;
		while(!Set::empty()) {
			node now = Set::top();
			if(now.key <= x) Set::erase(now), link(now.u); //-now.val / now.siz <= x
			else break;
		}
		int l = dfn[u], r = dfn[u] + siz[u] - 1;
		ans[q[i].id] += tr[0].ask(l, r) * q[i].x + tr[1].ask(l, r);
	}
	rep(i, 1, m) printf("%lld\n", ans[i]);
	return 0;
}