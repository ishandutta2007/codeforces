#include<bits/stdc++.h>
#define ll long long
#define N 300015
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
int n, q, k;
int a[N], Min[N][21], Log[N];
ll ans[N];
VI vec[N];
vector<pair<pii, int>> que[N];
int query(int l, int r) {
	int k = Log[r - l + 1];
	return min(Min[l][k], Min[r - (1 << k) + 1][k]);
}
vector<pii> stk;
#define ls (p << 1)
#define rs (p << 1 | 1)
int lazy[N << 2];
ll sum[N << 2];
void init(int m) {
	rep(i, 1, m * 4) lazy[i] = sum[i] = 0;
}
void pushup(int p) {sum[p] = sum[ls] + sum[rs];}
void down(int p, int l, int r, int v) {
	lazy[p] = v;
	sum[p] = (ll) (r - l + 1) * v;
}
void pushdown(int p, int l, int r) {
	if(lazy[p]) {
		int mid = (l + r) >> 1;
		down(ls, l, mid, lazy[p]);
		down(rs, mid + 1, r, lazy[p]);
		lazy[p] = 0;
	}
}
void modify(int p, int l, int r, int x, int y, int v) {
	if(x <= l && r <= y) return down(p, l, r, v);
	int mid = (l + r) >> 1;
	pushdown(p, l, r);
	if(x <= mid) modify(ls, l, mid, x, y, v);
	if(y > mid) modify(rs, mid + 1, r, x, y, v);
	pushup(p);
}
ll query(int p, int l, int r, int x, int y) {
	if(x <= l && r <= y) return sum[p];
	pushdown(p, l, r);
	int mid = (l + r) >> 1;
	ll res = 0;
	if(x <= mid) res += query(ls, l, mid, x, y);
	if(y > mid) res += query(rs, mid + 1, r, x, y);
	return res;
}
void solve(int x) {
	int m = SZ(vec[x]), ptr = SZ(que[x]) - 1;
	// printf("X: %d\n", x);
	// rep(i, 0, m - 1) printf("%d ", vec[x][i]);
	// printf("\n");
	init(m);
	stk.clear();
	per(i, 0, m - 1) {
		int r = i;
		while(SZ(stk) > 0 && stk.back().se >= vec[x][i]) r = stk.back().fi, stk.pop_back();
		stk.pb(mp(r, vec[x][i]));
		// for(auto y : stk) printf("!%d ", y.se);
		// printf("\n");
		modify(1, 1, m, i + 1, r + 1, vec[x][i]);
		// printf("[%d %d]\n", i + 1, r + 1);
		while(ptr >= 0 && que[x][ptr].fi.fi == i) {
			int len = que[x][ptr].fi.se;
			// printf("id: %d, [%d %d]\n", que[x][ptr].se, i + 1, i + len);
			// printf("a %d\n", a[i * k + (x == 0 ? k : x)]);
			assert(i + len <= m);
			// if(que[x][ptr].se == 4827) printf("%d %d %d %d\n", i * k + (x == 0 ? k : x), i, len, a[i * k + (x == 0 ? k : x)]);
			ans[que[x][ptr].se] = (ll) a[i * k + (x == 0 ? k : x)] + (len > 0 ? query(1, 1, m, i + 1, i + len) : 0);
			// puts("OK");
			ptr--;
		}
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d%d", &n, &q, &k);
	rep(i, 1, n) scanf("%d", &a[i]), Min[i][0] = a[i];
	rep(i, 2, n) Log[i] = Log[i >> 1] + 1;
	rep(j, 1, 19) {
		rep(i, 1, n) {
			if(i + (1 << j) - 1 > n) break;
			Min[i][j] = min(Min[i][j - 1], Min[i + (1 << (j - 1))][j - 1]);
		}
	}
	rep(i, 1, n) vec[i % k].pb(query(i, min(n, i + k)));
	rep(i, 1, q) {
		int l, r;
		scanf("%d%d", &l, &r);
		que[l % k].pb(mp(mp((l - 1) / k, (r - l) / k), i));
	}
	rep(i, 0, k - 1) sort(all(que[i]));
	rep(i, 0, k - 1) solve(i);
	rep(i, 1, q) printf("%lld\n", ans[i]);
	return 0;
}
/*
10 1 3
6 9 8 8 4 8 5 7 5 8
2 6

*/