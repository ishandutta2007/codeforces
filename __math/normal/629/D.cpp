#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <limits>
#include <ctime>
#include <cassert>
#include <map>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <stack>
#include <queue>
#include <numeric>
#include <iterator>
#include <bitset>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)

// #pragma comment(linker,"/STACK:36777216")

template<typename ...> static inline int getchar_unlocked(void) { return getchar(); }
template<typename ...> static inline void putchar_unlocked(int c) { putchar(c); }
#define mygc(c) (c)=getchar_unlocked()
#define mypc(c) putchar_unlocked(c)
void reader(int& x) { int k, m = 0; x = 0; for (;;) { mygc(k); if (k == '-') { m = 1; break; }if ('0' <= k&&k <= '9') { x = k - '0'; break; } }for (;;) { mygc(k); if (k<'0' || k>'9')break; x = x * 10 + k - '0'; }if (m) x = -x; }
void reader(ll& x) { int k, m = 0; x = 0; for (;;) { mygc(k); if (k == '-') { m = 1; break; }if ('0' <= k&&k <= '9') { x = k - '0'; break; } }for (;;) { mygc(k); if (k<'0' || k>'9')break; x = x * 10 + k - '0'; }if (m) x = -x; }
int reader(char c[]) { int i, s = 0; for (;;) { mygc(i); if (i != ' '&&i != '\n'&&i != '\r'&&i != '\t'&&i != EOF) break; }c[s++] = i; for (;;) { mygc(i); if (i == ' ' || i == '\n' || i == '\r' || i == '\t' || i == EOF) break; c[s++] = i; }c[s] = '\0'; return s; }
template <class T, class S> void reader(T& x, S& y) { reader(x); reader(y); }
template <class T, class S, class U> void reader(T& x, S& y, U& z) { reader(x); reader(y); reader(z); }
template <class T, class S, class U, class V> void reader(T& x, S& y, U& z, V & w) { reader(x); reader(y); reader(z); reader(w); }
void writer(int x, char c) { int s = 0, m = 0; char f[10]; if (x<0)m = 1, x = -x; while (x)f[s++] = x % 10, x /= 10; if (!s)f[s++] = 0; if (m)mypc('-'); while (s--)mypc(f[s] + '0'); mypc(c); }
void writer(ll x, char c) { int s = 0, m = 0; char f[20]; if (x<0)m = 1, x = -x; while (x)f[s++] = x % 10, x /= 10; if (!s)f[s++] = 0; if (m)mypc('-'); while (s--)mypc(f[s] + '0'); mypc(c); }
void writer(const char c[]) { int i; for (i = 0; c[i] != '\0'; i++)mypc(c[i]); }
void writer(const char x[], char c) { int i; for (i = 0; x[i] != '\0'; i++)mypc(x[i]); mypc(c); }
template<class T> void writerLn(T x) { writer(x, '\n'); }
template<class T, class S> void writerLn(T x, S y) { writer(x, ' '); writer(y, '\n'); }
template<class T, class S, class U> void writerLn(T x, S y, U z) { writer(x, ' '); writer(y, ' '); writer(z, '\n'); }
template<class T> void writerArr(T x[], int n) { if (!n) { mypc('\n'); return; }FOR(i, n - 1)writer(x[i], ' '); writer(x[n - 1], '\n'); }

template<class T> void chmax(T& l, const T r) { l = max(l, r); }
template<class T> void chmin(T& l, const T r) { l = min(l, r); }
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
ll mod_pow(ll a, ll n, ll mod) {
	ll ret = 1;
	ll p = a % mod;
	while (n) {
		if (n & 1) ret = ret * p % mod;
		p = p * p % mod;
		n >>= 1;
	}
	return ret;
}

#include <unordered_map>
#include <unordered_set>

template<class val_t>
struct min_t {
	val_t val;
	static min_t zero() { return min_t(); }
	min_t() : val(numeric_limits<val_t>::max()) {}
	min_t(val_t val) : val(val) {}
	operator val_t () const { return val; }
	bool is_zero() const { return val == zero().val; }
	min_t operator+ (const min_t& r) const {
		if (is_zero()) return r;
		else if (r.is_zero()) return *this;

		min_t ret(min(val, r.val));
		return ret;
	}
};

template<class val_t>
struct max_t {
	val_t val;
	static max_t zero() { return max_t(); }
	max_t() : val(numeric_limits<val_t>::min()) {}
	max_t(val_t val) : val(val) {}
	operator val_t () const { return val; }
	bool is_zero() const { return val == zero().val; }
	max_t  operator+ (const max_t & r) const {
		if (is_zero()) return r;
		else if (r.is_zero()) return *this;

		max_t ret(max(val, r.val));
		return ret;
	}
};

template<class val_t>
struct add_t {
	val_t val;
	static add_t zero() { return add_t(); }
	add_t() : val(0) {}
	add_t(val_t val) : val(val) {}
	operator val_t () const { return val; }
	bool is_zero() const { return val == zero().val; }
	add_t  operator+ (const add_t & r) const {
		if (is_zero()) return r;
		else if (r.is_zero()) return *this;

		add_t ret(val + r.val);
		return ret;
	}
};

struct pair_t {
	using S = min_t<ll>;
	using T = add_t<ll>;
	S first;
	T second;

	static pair_t zero() { return pair_t(S(),T()); }
	pair_t() {}
	pair_t(S f,T s) : first(f), second(s) {}
	bool is_zero() const { return first.is_zero() && second.is_zero(); }
	pair_t operator+ (const pair_t& r) const {
		if (is_zero()) return r;
		else if (r.is_zero()) return *this;
		pair_t ret;
		ret.first = first + r.first;
		ret.second = second + r.second;
		return ret;
	}
};

//0-indexed segment tree
template<class P>
class seg_tree {
public:
	vector<P> dat;
	int n;

	void propagate(int i) {
		dat[i] = dat[i * 2 + 1] + dat[i * 2 + 2];
	}

	void init(int size) {
		n = 1;
		while (n < size) n <<= 1;
		dat.resize(2 * n - 1);
		fill(dat.begin(), dat.end(), P::zero());
		for (int i = n - 2; i >= 0; i--) propagate(i);
	}

	void update(int k, P val) {
		k += n - 1;
		dat[k] = dat[k] + val;
			while (k > 0) {
				k = (k - 1) / 2;
				propagate(k);
			}
	}

	//[a,b)
	P query(int a, int b) {
		return query(a, b, 0, 0, n);
	}

	P query(int a, int b, int k, int l, int r) {
		if (r <= a || b <= l) return P::zero();
		if (a <= l && r <= b) return dat[k];

		int md = (l + r) / 2; //[l,md),[md,r)
		int nl = k * 2 + 1, nr = nl + 1;
		P lval = query(a, b, nl, l, md);
		P rval = query(a, b, nr, md, r);

		return lval + rval;
	}
};


int main() {
	int n; reader(n);
	vector<ll> vp;
	FOR(i, n) {
		ll r, h; reader(r, h);
		vp.emplace_back(r*r*h);
	}
	reverse(vp.begin(), vp.end());
	vector<ll> cmp = vp;
	sort(cmp.begin(), cmp.end());
	cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());

	seg_tree<max_t<ll>> seg;
	seg.init(n);
	FOR(i, n) {
		int id = lower_bound(cmp.begin(), cmp.end(), vp[i]) - cmp.begin();
		ll v = seg.query(id + 1, n).val;
		v = max(v, 0LL);
		seg.update(id, v + vp[i]);
	}
	double ans = seg.query(0, n).val * acos(-1);
	printf("%.15lf\n", ans);
}