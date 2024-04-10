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
using pll = pair<ll, ll>;
const int N = 100015;
const pll Ninf = mp(-infll, -infll);
pll& operator += (pll& a, const pll &b) {a.fi += b.fi; a.se += b.se; return a;}
pll operator + (const pll& a, const pll &b) {return mp(a.fi + b.fi, a.se + b.se);}

int n, a[N];
ll k;
struct seg {
	pll Max[N << 2];
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)
	void init() {rep(i, 1, n << 2) Max[i] = mp(-infll, -infll);}
	void pu(int p) {Max[p] = max(Max[ls], Max[rs]);}
	void modify(int p, int l, int r, int x, pll v) {
		if (l == r) return void(Max[p] = v);
		x <= mid ? modify(ls, l, mid, x, v) : modify(rs, mid + 1, r, x, v);
		pu(p);
	}
	pll query(int p, int l, int r, int x, int y) {
		if (x > y) return Ninf;
		if (x <= l && r <= y) return Max[p];
		pll res = Ninf;
		if (x <= mid) res = max(res, query(ls, l, mid, x, y));
		if (y > mid) res = max(res, query(rs, mid + 1, r, x, y));
		return res;
	}
#undef mid
} J, T;
pll dp[N];
int L[N], ord[N];
vector<ll> num;
ll sum[N], Min[N];

struct fenwick {
	pll D[N];
	int Min[N];
	void init() {rep(i, 0, n) D[i] = mp(0, 0), Min[i] = inf;}
	void add(int p, pll v, int id) {for (; p <= n; p += lowbit(p)) D[p] += v, Min[p] = min(Min[p], id);}
	pair<pll, int> query(int p) {pll res = mp(0, 0); int id = inf; for (; p; p -= lowbit(p)) res += D[p], id = min(id, Min[p]); return mp(res, id);}
} fen;

pll calc(ll d) {
	pll res = mp(0, 0);
	fen.init();
	rep(i, 1, n) {
		fen.add(ord[i - 1], mp(sum[i - 1], 1), i);
		int p = upper_bound(all(num), sum[i] + d) - num.begin();
		auto [v, j] = fen.query(p); j = min(j, i + 1);
		v.fi = v.se * (sum[i] + d) - v.fi;
		res += v; L[i] = j;
	}
	// fprintf(stderr, "%lld %lld\n", res.fi, res.se);
	J.init(); T.init();
	rep(i, 1, n) dp[i] = Ninf;
	auto upd = [&](int i) {
		if (i == n) return;
		J.modify(1, 1, n, i + 1, dp[i]);
		T.modify(1, 1, n, i + 1, dp[i] + mp(-Min[i], 0));
	};
	dp[0] = mp(0, 0); upd(0);
	rep(i, 1, n) {
		dp[i] = max({dp[i], J.query(1, 1, n, L[i], n), T.query(1, 1, n, 1, L[i] - 1) + mp(sum[i] + d, 1)});
		// fprintf(stderr, "%d (%lld %lld)\n", L[i], dp[i].fi, dp[i].se);
		upd(i);
	}
	res += dp[n];
	// exit(0);
	return res;
}

int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	scanf("%d%lld", &n, &k);
	rep(i, 1, n) scanf("%d", &a[i]);
	rep(i, 1, n) sum[i] = sum[i - 1] + a[i];
	rep(i, 0, n - 1) num.pb(sum[i]);
	sort(all(num)); num.erase(unique(all(num)), num.end());
	rep(i, 0, n - 1) ord[i] = lower_bound(all(num), sum[i]) - num.begin() + 1;
	rep(i, 1, n) Min[i] = min(Min[i - 1], sum[i]);
	ll l = -1e10, r = 1e10, ans = 1145141919;
	while (l <= r) {
		ll mid = (l + r) >> 1;
		auto [res, cnt] = calc(mid);
		// fprintf(stderr, "mid: %lld res: %lld cnt: %lld\n", mid, res, cnt);
		if (cnt >= k) r = mid - 1, ans = res - mid * k;
		else l = mid + 1;
	}
	printf("%lld\n", ans);
	return 0;
}