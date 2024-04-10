#include<bits/stdc++.h>
#define ll long long
#define N 100015
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
mt19937 rnd(114);
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
namespace Treap {
	const int M = 400015;
	int ls[M], rs[M], rnk[M], sz[M];
	ll val[M], sum[M], ans[M], tag[M];
	int rt, tot, top;
	int stk[20000015];
	inline int node(ll x) {
		int id = stk[++tot];
		val[id] = sum[id] = ans[id] = x;
		tag[id] = 0;
		rnk[id] = (int)rnd();
		sz[id] = 1;
		return id;
	}

	inline void pushup(int p) { 
		sz[p] = sz[ls[p]] + sz[rs[p]] + 1;
		sum[p] = sum[ls[p]] + sum[rs[p]] + val[p];
		ans[p] = ans[ls[p]] + (ll) (sz[ls[p]] + 1) * (val[p] + sum[rs[p]]) + ans[rs[p]];
	}
	inline void down(int p, ll v) {
		if(!p) return;
		val[p] += v;
		tag[p] += v;
		sum[p] += (ll) sz[p] * v;
		ans[p] += (ll) v * (1 + sz[p]) * sz[p] / 2;
	}
	inline void pushdown(int p) {
		if(tag[p]) {
			down(ls[p], tag[p]);
			down(rs[p], tag[p]);
			tag[p] = 0;
		}
	}
	void split(int p, ll k, int &u, int &v) {
		if (!p) {
			u = v = 0;
			return;
		}
		pushdown(p);
		if (val[p] <= k)
			u = p, split(rs[p], k, rs[u], v);
		else
			v = p, split(ls[p], k, u, ls[v]);
		pushup(p);
	}

	void Split(int p, int k, int &u, int &v) {
		if (!p) {
			u = v = 0;
			return;
		}
		pushdown(p);
		if (sz[ls[p]] + 1 <= k)
			u = p, Split(rs[p], k - sz[ls[p]] - 1, rs[u], v);
		else
			v = p, Split(ls[p], k, u, ls[v]);
		pushup(p);
	}

	int merge(int u, int v) {
		if (!u || !v)
			return u | v;
		pushdown(u);
		pushdown(v);
		if (rnk[u] < rnk[v]) {
			rs[u] = merge(rs[u], v);
			return pushup(u), u;
		} else {
			ls[v] = merge(u, ls[v]);
			return pushup(v), v;
		}
	}

	void insert(ll v) {
		int x, y;
		split(rt, v, x, y);
		rt = merge(merge(x, node(v)), y);
	}

	void del(ll v) {
		int x, y, yy, z;
		split(rt, v, x, z);
		split(x, v - 1, x, y); // x y z
		Split(y, 1, y, yy);
		if(y) stk[++top] = y;
		if (sz[yy] > 0) rt = merge(merge(x, yy), z);
		else rt = merge(x, z);
	}
	void out(int p) {
		if(!p) return;
		pushdown(p);
		printf("p: %d %d %d\n", p, ls[p], rs[p]);
		printf("val: %lld %lld %lld\n", val[p], sum[p], ans[p]);
		out(ls[p]);
		out(rs[p]);
	}
};
using namespace Treap;
int n, m, q;
ll a[114], b[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d%d", &n, &m, &q);
	rep(i, 1, n) scanf("%lld", &a[i]);
	rep(i, 1, m) scanf("%lld", &b[i]);
	per(i, 2, n) a[i] -= a[i - 1];
	per(i, 2, m) b[i] -= b[i - 1];
	rep(i, 1, n + m) stk[++top] = i;
	rep(i, 2, m) insert(b[i]);
	while(q--) {
		int typ, k;
		ll d;
		scanf("%d%d%lld", &typ, &k, &d);
		if(typ == 1) {
			rep(i, n - k + 1, n) a[i] += d;
		} else {
			int L, R;
			Split(rt, max(0, m - k - 1), L, R);
			if(k == m) b[1] += d;
			// printf("R: \n");
			down(R, d);
			rt = merge(L, R);
		}
		ll res = (ll) (n + m - 1) * (a[1] + b[1] + sum[rt]) - ans[rt];
		int x, y = rt;
		rt = 0;
		rep(i, 2, n) {
			split(y, a[i], x, y);
			// out(x);
			rt = merge(rt, x);
			res -= (ll) (i - 1 + sz[rt]) * a[i] + sum[y];
			res += (ll) (n + m - 1) * a[i];
			
		}
		rt = merge(rt, y);
		// rep(i, 2, n) insert(a[i]);
		printf("%lld\n", res);
		// rep(i, 2, n) del(a[i]);
	}
	return 0;
}