#include <bits/stdc++.h>
using namespace std;

#define db double
#define ll long long
#define ld long double
#define ull unsigned long long
/////////////
#define pii pair <int, int>
#define fi first
#define se second
#define pb push_back
#define mem(x, v, s) memset(x, v, sizeof(x[0]) * (s))
#define cpy(x, y, s) memcpy(x, y, sizeof(x[0]) * (s))
//
const int N = 6e3 + 5;
const int L = 1e6;
const int mod = 998244353;

int node, R[N], ls[N << 5], rs[N << 5];
int pre[N << 5], suf[N << 5], ans;
void modify(int l, int r, int p, int v, int &x, int *val) {
	if(!x) x = ++node; val[x] = max(val[x], v);
	if(l == r) return;
	int m = l + r >> 1;
	if(p <= m) modify(l, m, p, v, ls[x], val);
	else modify(m + 1, r, p, v, rs[x], val);
}
int merge(int x, int y) {
	if(!x || !y) return x | y;
	pre[x] = max(pre[x], pre[y]), suf[x] = max(suf[x], suf[y]);
//	cerr << "pre " << ans << " " << x << " " << y << endl;
//	cerr << pre[ls[x]] + suf[rs[x]] << " " << pre[rs[x]] + suf[ls[x]] << endl; 
	ans = max(ans, max(pre[ls[x]] + suf[rs[y]], suf[rs[x]] + pre[ls[y]]));
//	cerr << "suf " << ans << endl;
	ls[x] = merge(ls[x], ls[y]), rs[x] = merge(rs[x], rs[y]);
	return x;
}
int query(int l, int r, int ql, int qr, int x, int *val) {
	if(ql > qr) return 0;
	if(!x || ql <= l && r <= qr) return val[x];
	int m = l + r >> 1, ans = 0;
	if(ql <= m) ans = query(l, m, ql, qr, ls[x], val);
	if(m < qr) ans = max(ans, query(m + 1, r, ql, qr, rs[x], val));
	return ans;
}

int n, a[N];
vector <int> e[N];
void dfs(int id, int f) {
	int np = 0, ns = 0, cur = 0;
	for(int it : e[id]) if(it != f) {
		int tpre = 0, tsuf = 0; dfs(it, id);
		tpre = query(1, L, 1, a[id] - 1, R[it], pre);
		tsuf = query(1, L, a[id] + 1, L, R[it], suf);
		cerr << "it " << it << " " << tpre + ns << " " << tsuf + np << endl;
		ans = max(ans, max(np + tsuf, ns + tpre) + 1);
		np = max(np, tpre), ns = max(ns, tsuf);
		R[id] = merge(R[id], R[it]);
	}
	cerr << np << " " << ns << endl;
	modify(1, L, a[id], np + 1, R[id], pre);
	modify(1, L, a[id], ns + 1, R[id], suf);
}
int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		e[u].pb(v), e[v].pb(u);
	} dfs(1, 0), cout << ans << endl;
	return 0;
}