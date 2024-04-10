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
	mi& operator /= (const mi &o) { x = (ll) x * o.inv().val() % mod; return *this; }
#define gen(o) friend mi operator o(const mi&lhs,const mi&rhs){mi res = lhs; return res o##=rhs;}
	gen(+)gen(-)gen(*)gen( /)
#undef gen
};
const int mod = 1e9 + 7;
using mint = modint<mod>;
using Int = __int128_t;

struct P {
	ll x, y;
	P(ll a = 0, ll b = 0) { x = a, y = b; }
	void read() { scanf("%lld%lld", &x, &y); }
} ;

P operator - (const P &a, const P &b) {return (P) {a.x - b.x, a.y - b.y};}
P operator + (const P &a, const P &b) {return (P) {a.x + b.x, a.y + b.y};}
Int operator & (const P &a, const P &b) {return (Int) a.x * b.y - (Int) a.y * b.x;}
const int N = 500015;

int n;
Int sum[N << 1];
P a[N << 1];

int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	scanf("%d", &n);
	rep(i, 1, n) a[i].read(), a[i + n] = a[i];
	rep(i, 2, n + n) sum[i] = sum[i - 1] + (a[i] & a[i - 1]);
	Int area = a[1] & a[n];
	rep(i, 2, n) area += a[i] & a[i - 1];
	P vsum;
	mint ssum = 0, ans = 0;
	auto check = [&](int l, int r) { return (sum[r] - sum[l] + (a[l] & a[r])) * 2 >= area; };

	for (int i = n + 1, r = 2, c = 0; i <= n + n; ++i) {
		// [i - n + 2, r]
		while (r + 1 < i && check(r + 1, i)) {
			r++;

			if (r >= i - n + 2) {
				c++;
				ssum += sum[r];
				vsum = vsum + a[r];
			}
		}

		ans += 2 * (mint(vsum & a[i]) + mint(sum[i]) * c - ssum);
		ans -= mint(area) * c;

		if (i - n + 2 <= r) {
			ssum -= sum[i - n + 2];
			vsum = vsum - a[i - n + 2];
			c--;
		}
	}

	printf("%d\n", ans.val());
	return 0;
}