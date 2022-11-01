#define _CRT_SECURE_NO_WARNINGS

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
#include <unordered_map>
#include <unordered_set>

using namespace std;
#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)c.size())
#define ten(n) ((int)1e##n)
using ll = long long;
using ull = unsigned long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

template<typename ...> static inline int getchar_unlocked(void) { return getchar(); }
template<typename ...> static inline void putchar_unlocked(int c) { putchar(c); }
#define mygc(c) (c)=getchar_unlocked()
#define mypc(c) putchar_unlocked(c)
void reader(int& x) { int k, m = 0; x = 0; for (;;) { mygc(k); if (k == '-') { m = 1; break; }if ('0' <= k && k <= '9') { x = k - '0'; break; } }for (;;) { mygc(k); if (k < '0' || k>'9')break; x = x * 10 + k - '0'; }if (m) x = -x; }
void reader(ll& x) { int k, m = 0; x = 0; for (;;) { mygc(k); if (k == '-') { m = 1; break; }if ('0' <= k && k <= '9') { x = k - '0'; break; } }for (;;) { mygc(k); if (k < '0' || k>'9')break; x = x * 10 + k - '0'; }if (m) x = -x; }
int reader(char c[]) { int i, s = 0; for (;;) { mygc(i); if (i != ' ' && i != '\n' && i != '\r' && i != '\t' && i != EOF) break; }c[s++] = i; for (;;) { mygc(i); if (i == ' ' || i == '\n' || i == '\r' || i == '\t' || i == EOF) break; c[s++] = i; }c[s] = '\0'; return s; }
int reader(string& c) { int i; for (;;) { mygc(i); if (i != ' ' && i != '\n' && i != '\r' && i != '\t' && i != EOF) break; }c.push_back(i); for (;;) { mygc(i); if (i == ' ' || i == '\n' || i == '\r' || i == '\t' || i == EOF) break; c.push_back(i); }; return sz(c); }
template <class T, class S> void reader(T& x, S& y) { reader(x); reader(y); }
template <class T, class S, class U> void reader(T& x, S& y, U& z) { reader(x); reader(y); reader(z); }
template <class T, class S, class U, class V> void reader(T& x, S& y, U& z, V& w) { reader(x); reader(y); reader(z); reader(w); }
void writer(int x, char c) { int s = 0, m = 0; char f[10]; if (x < 0)m = 1, x = -x; while (x)f[s++] = x % 10, x /= 10; if (!s)f[s++] = 0; if (m)mypc('-'); while (s--)mypc(f[s] + '0'); mypc(c); }
void writer(ll x, char c) { int s = 0, m = 0; char f[20]; if (x < 0)m = 1, x = -x; while (x)f[s++] = x % 10, x /= 10; if (!s)f[s++] = 0; if (m)mypc('-'); while (s--)mypc(f[s] + '0'); mypc(c); }
void writer(const char c[]) { int i; for (i = 0; c[i] != '\0'; i++)mypc(c[i]); }
void writer(const string& x, char c) { int i; for (i = 0; x[i] != '\0'; i++)mypc(x[i]); mypc(c); }
void writer(const char x[], char c) { int i; for (i = 0; x[i] != '\0'; i++)mypc(x[i]); mypc(c); }
template<class T> void writerLn(T x) { writer(x, '\n'); }
template<class T, class S> void writerLn(T x, S y) { writer(x, ' '); writer(y, '\n'); }
template<class T, class S, class U> void writerLn(T x, S y, U z) { writer(x, ' '); writer(y, ' '); writer(z, '\n'); }
template<class T, class S, class U, class V> void writerLn(T x, S y, U z, V v) { writer(x, ' '); writer(y, ' '); writer(z, ' '); writer(v, '\n'); }
template<class T> void writerArr(T x[], int n) { if (!n) { mypc('\n'); return; }FOR(i, n - 1)writer(x[i], ' '); writer(x[n - 1], '\n'); }
template<class T> void writerArr(vector<T>& x) { writerArr(x.data(), (int)x.size()); }
void reader(ull& x) { int k, m = 0; x = 0; for (;;) { mygc(k); if (k == '-') { m = 1; break; }if ('0' <= k && k <= '9') { x = ull(k - '0'); break; } }for (;;) { mygc(k); if (k < '0' || k>'9')break; x = x * 10 + k - '0'; } }
void writer(ull x, char c) { int s = 0, m = 0; char f[20]; while (x)f[s++] = x % 10, x /= 10; if (!s)f[s++] = 0; if (m)mypc('-'); while (s--)mypc(f[s] + '0'); mypc(c); }
template<class T> vector<T> readerArray(int n) { vector<T> ret(n); for (int i = 0; i < n; i++) reader(ret[i]); return ret; }

template<class T> void chmin(T& a, const T& b) { if (a > b) a = b; }
template<class T> void chmax(T& a, const T& b) { if (a < b) a = b; }

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
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
template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
ll mod_inv(ll a, ll m) { ll x, y; extgcd<ll>(a, m, x, y); return (m + x % m) % m; }

#ifdef _MSC_VER
// #ifdef _DEBUG
template <typename ... Args>
void debugPrintf(const char* format, Args const& ... args) {
	fprintf(stderr, format, args ...);
	fflush(stderr);
}
#else
#define debugPrintf(...)
#endif

int lightMax[ten(6) + 10];
vector<Pii> events[ten(6) + 10];

template<class val_t>
struct max_t {
	val_t val;
	static max_t zero() { return max_t(); }
	max_t() : val(numeric_limits<val_t>::min()) {}
	max_t(val_t val) : val(val) {}
	operator val_t () const { return val; }
	bool is_zero() const { return val == zero().val; }
	max_t  operator+ (const max_t& r) const {
		if (is_zero()) return r;
		else if (r.is_zero()) return *this;

		max_t ret(max(val, r.val));
		return ret;
	}
};

using P = max_t<ll>;

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
	}

	void update(int k, P val) {
		k += n - 1;
		dat[k] = val;
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
	int n, m; reader(n, m);
	vector<Pii> robber(n);
	FOR(i, n) reader(robber[i].first, robber[i].second);
	vector<Pii> light(m);
	FOR(i, m) reader(light[i].first, light[i].second);
	memset(lightMax, -1, sizeof lightMax);
	FOR(i, m) {
		chmax(lightMax[light[i].first], light[i].second);
	}
	vector<Pii> l;
	for (int i = ten(6); i >= 0; i--) {
		if (lightMax[i] <= lightMax[i + 1]) {
			lightMax[i] = lightMax[i + 1];
		} else {
			l.emplace_back(i, lightMax[i]);
		}
	}
	reverse(l.begin(), l.end());
	l.emplace_back(ten(6) + 4, -1);
	
	FOR(id, n) {
		auto kv = robber[id];
		int px = 0;
		for (auto& ll : l) {
			int diff = max(0, ll.second + 1 - kv.second);
			int npx = max(0, ll.first + 1 - kv.first);
			if (px != npx) {
				events[px].emplace_back(id, diff);
				px = npx;
			}
		}
	}

	seg_tree seg;
	seg.init(n);

	ll ans = ll(1e16);
	FOR(i, ten(6) + 2) {
		for (auto& kv : events[i]) {
			seg.update(kv.first, kv.second);
		}
		ans = min(ans, seg.query(0, n).val + i);
	}
	writerLn(ans);


	return 0;
}