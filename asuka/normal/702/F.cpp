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
mt19937 rng(time(0));
namespace Treap {
	#define M N << 5
	int rt, tot, ls[M], rs[M], lans[M], lval[M], val[M], id[M], ans[M], rnk[M];
	int node(int x, int i, int j) {
		tot++;
		val[tot] = x;
		rnk[tot] = rng();
		id[tot] = i;
		ans[tot] = j;
		return tot;
	}
	void dans(int p, int v) {
		if(!p) return;
		ans[p] += v;
		lans[p] += v;
	}
	void dval(int p, int v) {
		if(!p) return; 
		val[p] += v;
		lval[p] += v;
	}
	void pushdown(int p) {
		if(lval[p]) {
			dval(ls[p], lval[p]);
			dval(rs[p], lval[p]);
			lval[p] = 0;
		}
		if(lans[p]) {
			dans(ls[p], lans[p]);
			dans(rs[p], lans[p]);
			lans[p] = 0;
		}
	}
	void split(int p, int k, int &u, int &v) {
		if(!p) {
			u = v = 0;
			return;
		}
		pushdown(p);
		if(val[p] <= k) {
			u = p;
			split(rs[p], k, rs[u], v);
		} else {
			v = p;
			split(ls[p], k, u, ls[v]);
		}
	}
	int merge(int u, int v) {
		if(!u || !v) return u | v;
		if(rnk[u] > rnk[v]) {
			pushdown(u);
			rs[u] = merge(rs[u], v);
			return u;
		} else {
			pushdown(v);
			ls[v] = merge(u, ls[v]);
			return v;
		}
	}
	#undef M
}
using namespace Treap;
VI vec;
void get(int p) {
	if(!p) return;
	vec.pb(p);
	pushdown(p);
	get(ls[p]);
	get(rs[p]);
}
void insert(int x, int i, int j) {
	int L, M = node(x, i, j), R;
	split(rt, x - 1, L, R);
	rt = merge(L, merge(M, R));
}
int n, m, b[N], res[N];
pii a[N];
void getres(int p) {
	if(!p) return;
	// printf("%d %d\n", id[p], ans[p]);
	pushdown(p);
	res[id[p]] = ans[p];
	getres(ls[p]);
	getres(rs[p]);
}
int cnt[N];
int main(){
	// freopen("data.in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d%d", &a[i].fi, &a[i].se);
	sort(a + 1, a + n + 1, [](pii u, pii v) {
		return u.se != v.se ? u.se > v.se : u.fi < v.fi;
	});
	scanf("%d", &m);
	rep(i, 1, m) scanf("%d", &b[i]), insert(b[i], i, 0);
	rep(i, 1, n) {
		int x = a[i].fi;
		int L, M, R;
		split(rt, 2 * x - 1, L, R);
		split(L, x - 1, L, M);
		dans(R, 1);
		dval(R, -x);
		vec.clear();
		get(M);
		rt = merge(L, R);
		for(auto u : vec) insert(val[u] - x, id[u], ans[u] + 1), cnt[id[u]]++;//, printf("add %d\n", id[u]); 
	}
	getres(rt);
	rep(i, 1, m) printf("%d ", res[i]);
	return 0;
}