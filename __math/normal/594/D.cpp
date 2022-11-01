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
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }

const int MOD = ten(9) + 7;

struct P {
	ll v;
	static P zero() {
		P ret = { 1 };
		return ret;
	}
	bool is_zero() const { return v == 1; }
	P operator+(const P& r) const {
		return {v * r.v % MOD};
	}
};

//0-indexed segment tree
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

const int N = ten(6) + 1;
ll inverse[N];
void init_inverse() {
	inverse[1] = 1;
	for (int i = 2; i < N; i++) inverse[i] = (MOD - MOD / i) * inverse[MOD%i] % MOD;
}
int factors[N];
void init_factor() {
	for (int i = 2; i < N; i += 2) factors[i] = 2;
	for (int i = 3; i < N; i += 2) factors[i] = i;
	for (int i = 3; i < N; i += 2) if (factors[i] == i)
		for (int j = 3 * i; j < N; j += 2 * i) factors[j] = i;
}

int last_p[ten(6) + 1];
int a[2*ten(5)];

int main() {
	memset(last_p, -1, sizeof(last_p));
	init_inverse();
	init_factor();

	int n, q; reader(n);
	FOR(i, n) reader(a[i]);
	reader(q);
	vector<pair<Pii,int> > vq;
	FOR(i, q) {
		int l, r; reader(l, r); l--;
		vq.emplace_back(Pii(l, r), i);
	}
	sort(vq.begin(), vq.end(), [](const pair<Pii, int>& l, const pair<Pii, int>& r) {
		return l.first.second < r.first.second;
	});

	seg_tree seg;
	seg.init(n);

	static ll anses[ten(5) * 2];
	int vqi = 0;
	FOR(i, n) {
		int x = a[i], phi = a[i];
		while (x != 1) {
			int f = factors[x];
			if (last_p[f] != i) {
				seg.update(last_p[f], { f * inverse[f - 1] % MOD });
				phi = phi / f * (f - 1);
				last_p[f] = i;
			}
			x /= f;
		}
		seg.update(i, { phi });

		while (vqi < q && vq[vqi].first.second == i + 1) {
			P ans = seg.query(vq[vqi].first.first, vq[vqi].first.second);
			anses[vq[vqi].second] = ans.v;
			vqi++;
		}
	}
	FOR(i, q) writerLn(anses[i]);

	return 0;
}