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
const int N = 300015;
int n, q, x[N], w[N], pre[N];
ll ans[N];
vector<int> vec[N];
vector<pii> que[N];

ll D[N];
void init() {fill(D, D + n + 1, (ll) 5e18);}
void upd(int p, ll v) {for (; p <= n; p += lowbit(p)) D[p] = min(D[p], v);}
ll ask(int p) {ll res = 5e18; for (; p; p -= lowbit(p)) res = min(res, D[p]); return res;}
ll calc(int i, int j) {return (ll) (x[j] - x[i]) * (w[i] + w[j]);}

int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	scanf("%d%d", &n, &q);
	rep(i, 1, n) scanf("%d%d", &x[i], &w[i]);
	vector<int> stk;
	rep(i, 1, n) {
		while (SZ(stk) && w[stk.back()] >= w[i]) stk.pop_back();
		if (SZ(stk)) pre[i] = stk.back();
		stk.push_back(i);
	}
	rep(i, 2, n) {
		vec[i].pb(i - 1);
		if (w[i - 1] <= w[i] || !pre[i - 1]) continue;
		int o = pre[i - 1];
		while (o && w[o + 1] > w[i]) vec[i].pb(o--);
	}
	rep(i, 1, q) {
		int l, r;
		scanf("%d%d", &l, &r);
		que[r].emplace_back(l, i);
	}
	init();
	rep(r, 1, n) {
		for (int l : vec[r]) upd(n - l + 1, calc(l, r));
		for (auto [l, id] : que[r]) ans[id] = ask(n - l + 1);
	}
	rep(i, 1, q) printf("%lld\n", ans[i]);
	return 0;
}