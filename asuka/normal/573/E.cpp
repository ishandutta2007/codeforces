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
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
const int N = 100015, M = N;

struct node {
	ll k, b;
	void clear() {k = b = 0;}
	node() {clear();}
	node(ll x, ll y) {k = x; b = y;}
	node operator + (const node &o) const {
		node res = *this; res.k += o.k; res.b += o.b;
		return res;
	}
	ll val(int x) {return (ll) k * x + b;}
} tag[M];
mt19937 rnd(114);
int ls[M], rs[M], rnk[M], siz[M];
ll val[M], rmost[M];
int rt, tot;

inline int Node(ll x) {
	tot++;
	val[tot] = rmost[tot] = x;
	rnk[tot] = (int)rnd();
	siz[tot] = 1;
	return tot;
}

inline void pushup(int p) { siz[p] = siz[ls[p]] + siz[rs[p]] + 1; rmost[p] = rs[p] ? rmost[rs[p]] : val[p];}

void down(int p, node v) {
	tag[p] = tag[p] + v;
	val[p] += v.val(siz[ls[p]] + 1);
	rmost[p] += v.val(siz[p]);
}

void pushdown(int p) {
	down(ls[p], tag[p]);
	tag[p].b += (ll) tag[p].k * (siz[ls[p]] + 1);
	down(rs[p], tag[p]);
	tag[p].clear();
}

void Split(int p, int k, int &u, int &v) {
	if (!p) return void(u = v = 0);
	pushdown(p);
	if (siz[ls[p]] + 1 <= k)
		u = p, Split(rs[p], k - siz[ls[p]] - 1, rs[u], v);
	else
		v = p, Split(ls[p], k, u, ls[v]);
	pushup(p);
}

int merge(int u, int v) {
	if (!u || !v)
		return u | v;
	if (rnk[u] < rnk[v]) {
		pushdown(u);
		rs[u] = merge(rs[u], v);
		return pushup(u), u;
	} else {
		pushdown(v);
		ls[v] = merge(u, ls[v]);
		return pushup(v), v;
	}
}

ll query(int p, int v) {
	pushdown(p);
	if (v == siz[ls[p]] + 1) return val[p];
	if (v > siz[ls[p]] + 1) return query(rs[p], v - siz[ls[p]] - 1);
	return query(ls[p], v);
}

// max i s.t. f[i] >= f[i - 1] + i * c)

int find(int p, int i, ll pre, const int c) {
	if (!p) return -1;
	pushdown(p);
	ll npre = pre;
	int ni = i + siz[ls[p]];
	if (ls[p]) npre = rmost[ls[p]];
	if (ni == 0 || val[p] >= npre + (ll) ni * c) {
		return max(ni + 1, find(rs[p], ni + 1, val[p], c));
	} else return find(ls[p], i, pre, c);
}

int n, a[N];
int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &a[i]);
	rt = merge(rt, Node(0));
	rep(i, 1, n) {
		int pos = i == 1 ? 1 : find(rt, 0, 0, a[i]), l, r;
		Split(rt, pos, l, r);
		ll v = query(l, siz[l]);
		r = merge(Node(v), r);
		down(r, node(a[i], (ll) (pos - 1) * a[i]));
		rt = merge(l, r);
	}
	ll ans = 0;
	rep(i, 1, n + 1) ans = max(ans, query(rt, i));
	printf("%lld\n", ans);
	return 0;
}