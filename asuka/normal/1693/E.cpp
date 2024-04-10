#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
const int N = 200015;

int n, a[N], cnt[N][2];

struct fenwick {
	int D[N];

	void upd(int p, int v) {
		for (p++; p <= n + 1; p += lowbit(p))
			D[p] += v;
	}

	int ask(int p) {
		int res = 0;

		for (p++; p; p -= lowbit(p))
			res += D[p];

		return res;
	}
} rk, ans, grey;

set<int> P;
set<pii> seg;

int L(int u) { return prev(seg.upper_bound(mp(u, inf))) -> fi; }

int R(int u) { return prev(seg.upper_bound(mp(u, inf))) -> se; }

int f(int x) { return (x + 1) >> 1; }

void link(int u, int v) {
	int p = L(u), q = R(v), lu = rk.ask(u), lv = rk.ask(q);
	ans.upd(p, - f(lu) + f(lu + lv + 1));
	ans.upd(v, - f(lv));
	seg.erase(mp(p, u));
	seg.erase(mp(v, q));
	seg.emplace(p, q);
	rk.upd(u + 1, lu + 1), rk.upd(q + 1, - lu - 1);
}

void cut(int u, int v) {
	int p = L(u), q = R(v), lu = rk.ask(u), lv = rk.ask(q);
	ans.upd(p, - f(lv) + f(lu));
	ans.upd(v, f(lv - lu - 1));
	seg.erase(mp(p, q));
	seg.emplace(p, u);
	seg.emplace(v, q);
	rk.upd(u + 1, - lu - 1), rk.upd(q + 1, lu + 1);
}

int col[N];

void ins(int x) {
	auto it = P.insert(x).fi;

	if (it != P.begin() && next(it) != P.end() && (col[*prev(it)] ^ col[*next(it)]) == 1)
		cut(*prev(it), *next(it));

	seg.emplace(x, x);

	if (col[x] == 2) grey.upd(x, 1);

	if (it != P.begin() && (col[*prev(it)] ^ col[x]) == 1)
		link(*prev(it), x);

	if (next(it) != P.end() && (col[*next(it)] ^ col[x]) == 1)
		link(x, *next(it));
}

void era(int x) {
	auto it = P.lower_bound(x);

	if (it != P.begin() && (col[*prev(it)] ^ col[x]) == 1)
		cut(*prev(it), x);

	if (next(it) != P.end() && (col[*next(it)] ^ col[x]) == 1)
		cut(x, *next(it));

	seg.erase(mp(x, x));

	if (col[x] == 2) grey.upd(x, -1);

	if (it != P.begin() && next(it) != P.end() && (col[*prev(it)] ^ col[*next(it)]) == 1)
		link(*prev(it), *next(it));

	P.erase(it);
}

int ask(int x) {
	auto it = P.lower_bound(x);

	if (it == P.begin()) return 0;

	it = prev(it);
	return f(rk.ask(*it)) + ans.ask(L(*it) - 1) + grey.ask(x - 1);
}

void upd(int x, int o, int v) {
	if (~col[x]) era(x);

	cnt[x][o] += v;

	if (cnt[x][0] && cnt[x][1]) col[x] = 2;
	else if (cnt[x][0]) col[x] = 0;
	else if (cnt[x][1]) col[x] = 1;
	else col[x] = -1;

	if (~col[x]) ins(x);
}

int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &a[i]);
	memset(col, -1, sizeof col);
	rep(i, 1, n + 1) upd(a[i], 1, 1);
	ll ans = 0;

	rep(i, 1, n) {
		upd(a[i - 1], 0, 1);
		upd(a[i], 1, -1);
		ans += ask(a[i]);
	}

	printf("%lld\n", ans);
	return 0;
}