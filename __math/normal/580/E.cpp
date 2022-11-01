#define _USE_MATH_DEFINES
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

ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

ull h[ten(5) + 10];
ull hsum[ten(5) + 10];
const int MOD = ten(9) + 7;
const ull M = ten(8) + 7;

void init_hash() {
	h[0] = 1;
	FOR(i, ten(5)) h[i + 1] = h[i] * M % MOD;
	FOR(i, ten(5)) hsum[i + 1] = (hsum[i] + h[i]) % MOD;
}

const int INF = ten(9);

struct A {
	int len;
	ull val;
	bool lazyflag;
	int lazyval;
	static A identify() {
		A res = { 0, 0, false, 0 };
		return res;
	}
	bool is_identify() const {
		return len == 0;
	}
	static A add(const A &a, const A &b) {
		if (a.is_identify()) return b;
		if (b.is_identify()) return a;
		A res;
		res.len = a.len + b.len;
		res.val = (a.val * h[b.len] + b.val) % MOD;
		res.lazyflag = false;
		return res;
	}
};

class LasySegTree {
	int n;
	std::vector<A> node;
	void update(int a, int b, int x, int k, int l, int r) {
		if (r <= a || b <= l)return;
		if (a <= l && r <= b) {
			A &v = node[k];
			v.len = r - l;
			v.val = x * hsum[v.len] % MOD;
			v.lazyflag = true;
			v.lazyval = x;
			return;
		}
		int m = (l + r) / 2;
		if (node[k].lazyflag) {
			update(l, r, node[k].lazyval, 2 * k + 1, l, m);
			update(l, r, node[k].lazyval, 2 * k + 2, m, r);
			node[k].lazyflag = false;
		}
		update(a, b, x, 2 * k + 1, l, m);
		update(a, b, x, 2 * k + 2, m, r);
		node[k] = A::add(node[2 * k + 1], node[2 * k + 2]);
	}
	A query(int a, int b, int k, int l, int r) {
		if (r <= a || b <= l)return A::identify();
		if (a <= l && r <= b) {
			return node[k];
		}
		int m = (l + r) / 2;
		if (node[k].lazyflag) {
			update(l, r, node[k].lazyval, 2 * k + 1, l, m);
			update(l, r, node[k].lazyval, 2 * k + 2, m, r);
			node[k].lazyflag = false;
		}
		return A::add(query(a, b, 2 * k + 1, l, m), query(a, b, 2 * k + 2, m, r));
	}
public:
	LasySegTree(vector<int> vals) {
		init(sz(vals));
		FOR(i, sz(vals)) update(i, i + 1, vals[i]);
	}
	void init(int n) {
		while (n&(n - 1))n += n&-n;
		this->n = n;
		node.assign(2 * n - 1, A::identify());
	}
	void update(int a, int b, int x) {
		update(a, b, x, 0, 0, n);
	}
	A query(int a, int b) {
		return query(a, b, 0, 0, n);
	}
};

int main() {
	init_hash();
	int n, m, k; reader(n, m, k);
	string s; cin >> s;
	vector<int> v;
	for (auto& c : s) v.push_back(c - '0');

	LasySegTree seg(v);
	FOR(i, m + k) {
		int t, l, r, c; reader(t, l, r, c);
		l--;
		if (t == 1) {
			seg.update(l, r, c);
		} else {
			auto v1 = seg.query(l, r - c);
			auto v2 = seg.query(l + c, r);
			bool ok = v1.val == v2.val;
			puts(ok ? "YES" : "NO");
		}
	}

	return 0;
}