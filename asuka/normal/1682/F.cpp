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

const int mod = 1e9 + 7;
template<int mod>
struct modint {
	using mi = modint;
	int x;
	int val() const { return x; }
	modint() { x = 0; }
	int mo(int x) { return x < 0 ? x + mod : x >= mod ? x - mod : x; }
	template<class T>
	modint(T o) { x = 0 <= o && o < mod ? static_cast<int>(o) : mo(static_cast<int>(o % mod));}
	bool operator == (const mi &o) const { return x == o.x; }
	bool operator != (const mi &o) const { return x != o.x; }
	mi operator - () const { return x ? mod - x : 0; }
	template<class T>
	mi mpow(T b) const {
		int res = 1, a = x;

		for (; b; b >>= 1, a = (ll) a * a % mod)
			if (b & 1) res = (ll) res * a % mod;

		return res;
	}
	mi inv() const { return mpow(mod - 2); }
	mi& operator += (const mi &o) { x += o.x; if (x >= mod) x -= mod; return *this; }
	mi& operator -= (const mi &o) { x -= o.x; if (x < 0) x += mod; return *this; }
	mi& operator *= (const mi &o) { x = (ll) x * o.x % mod; return *this; }
	mi& operator /= (const mi &o) { x = (ll) x * o.inv() % mod; return *this; }
#define gen(o) friend mi operator o(const mi&lhs,const mi&rhs){mi res = lhs; return res o##=rhs;}
	gen(+)gen(-)gen(*)gen( /)
#undef gen
};
using mint = modint<mod>;
const int N = 200015;

struct node {
	int l, mid, r;
	mint s1, s2;
	node *ls, *rs;
	node() {s1 = s2 = 0; }

	void pull() {s1 = ls -> s1 + rs -> s1; s2 = ls -> s2 + rs -> s2; }

	void upd(int x, mint s, mint a) {
		if (l == r) {
			s1 = s * a;
			s2 = a;
			return;
		}

		(x <= mid ? ls : rs) -> upd(x, s, a);
		pull();
	}

	pair<mint, mint> ask(int x, int y) {
		if (x <= l && r <= y) {
			return mp(s1, s2);
		}

		mint a1 = 0, a2 = 0;

		if (x <= mid) {
			auto [b1, b2] = ls -> ask(x, y);
			a1 += b1;
			a2 += b2;
		}

		if (y > mid) {
			auto [b1, b2] = rs -> ask(x, y);
			a1 += b1;
			a2 += b2;
		}

		return mp(a1, a2);
	}
} Pool[N << 2], *rt, *ptr = Pool;

node *build(int l, int r) {
	node *p = ptr++;
	int mid = (l + r) >> 1;
	p -> l = l;
	p -> r = r;
	p -> mid = mid;

	if (l != r) {
		p -> ls = build(l, mid);
		p -> rs = build(mid + 1, r);
	}

	return p;
}

int n, q, a[N], b[N], ord[N];
mint ans[N];
ll s[N];
vector<pii> qry[N];

int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	scanf("%d%d", &n, &q);

	rep(i, 1, n) scanf("%d", &a[i]);

	rep(i, 1, n) scanf("%d", &b[i]);

	rep(i, 1, n) s[i] = s[i - 1] + b[i];

	rep(i, 1, q) {
		int l, r;
		scanf("%d%d", &l, &r);
		qry[l].emplace_back(r, i);
	}

	iota(ord + 0, ord + n + 1, 0);

	{
		rt = build(1, n);
		sort(ord, ord + n + 1, [&](int u, int v) {
			return s[u] > s[v];
		});

		rep(i, 0, n) {
			int u = ord[i];

			for (auto [r, id] : qry[u + 1]) {
				auto [p, q] = rt -> ask(u + 1, r - 1);
				ans[id] += p - q * s[u];
			}

			if (u) rt -> upd(u, mint(s[u]), a[u + 1] - a[u]);
		}
	}

	{
		rt = build(1, n);
		sort(ord, ord + n + 1, [&](int u, int v) {
			return s[u] < s[v];
		});

		rep(i, 0, n) {
			int u = ord[i];

			for (auto [r, id] : qry[u + 1]) {
				auto [p, q] = rt -> ask(u + 1, r - 1);
				ans[id] += q * s[u] - p;
			}

			if (u) rt -> upd(u, mint(s[u]), a[u + 1] - a[u]);
		}
	}

	rep(i, 1, q) printf("%d\n", ans[i].val());

	return 0;
}