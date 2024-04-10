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

typedef long double T;

struct P {
	T x, y;
	P() : x(0), y(0) {}
	P(const T& x, const T& y) : x(x), y(y) {}
	P operator+(const P &a)const { return P(x + a.x, y + a.y); }
	P& operator+=(const P &a) { x += a.x; y += a.y; return *this; }
	P operator-(const P &a)const { return P(x - a.x, y - a.y); }
	P& operator-=(const P &a) { x -= a.x; y -= a.y; return *this; }
	P operator*(const T a)const { return P(a*x, a*y); }
	P& operator*=(const T a) { x *= a; y *= a; return *this; }
	P operator/(const T a)const { return P(x / a, y / a); }
	P& operator/=(const T a) { x /= a; y /= a; return *this; }

	//
	bool operator<(const P &a)const { return (x != a.x) ? (x < a.x) : (y < a.y); }
};
const double PI = acos(-1);

P rot(const P& a, double theta) {
	theta = -theta / 180 * PI;
	return P(a.x*cos(theta) - a.y*sin(theta),
		a.x*sin(theta) + a.y*cos(theta));
}
T SQ(T x) { return x*x; }
T dist2(const P &a, const P &b) { return SQ(a.x - b.x) + SQ(a.y - b.y); }
T abs2(const P& p) { return SQ(p.x) + SQ(p.y); }
T dot(const P& a, const P& b) { return a.x*b.x + a.y*b.y; }
T cross(const P& a, const P& b) { return a.x*b.y - a.y*b.x; }
T abs(const P& p) { return sqrt(abs2(p)); }
double arg(const P &a) { double t = atan2(a.y, a.x); return t<0 ? t + 2 * PI : t; }

struct Q {
	long double x, y;
	int argsum;
	static Q zero() {
		Q ret = { 0, 0, 0 };
		return ret;
	}
	bool is_zero() const { return x == 0 && y == 0; }
	Q operator+(const Q& r) const {
		if (is_zero()) return r;
		else if (r.is_zero()) return *this;

		P p1(x, y);
		P p2(r.x, r.y);
		p2 = rot(p2, argsum);

		P cur = p1 + p2;
		Q ret;
		ret.x = cur.x;
		ret.y = cur.y;
		ret.argsum = argsum + r.argsum;

		return ret;
	}
};

//0-indexed segment tree
class seg_tree {
public:
	vector<int> len, args;
	vector<Q> dat;
	int n;

	void propagate(int i) {
		dat[i] = dat[i * 2 + 1] + dat[i * 2 + 2];
	}

	void init(int size) {
		n = 1;
		len.resize(size, 1);
		args.resize(size);
		while (n < size) n <<= 1;
		dat.resize(2 * n - 1);
		fill(dat.begin(), dat.end(), Q::zero());
		for (int i = 0; i < size; i++) dat[n - 1 + i].x = 1.0;
		for (int i = n - 2; i >= 0; i--) propagate(i);
	}

	void update_k(int k) {
		P cur(len[k], 0);
		cur = rot(cur, args[k]);
		k += n - 1;
		dat[k].x = cur.x;
		dat[k].y = cur.y;
		dat[k].argsum = args[k-n+1];
	}

	void update_len(int k, int len) {
		this->len[k] += len;
		update_k(k);
		k += n - 1;
		while (k > 0) {
			k = (k - 1) / 2;
			propagate(k);
		}
	}

	void update_arg(int k, int arg) {
		args[k] += arg;
		update_k(k);
		k += n - 1;
		while (k > 0) {
			k = (k - 1) / 2;
			propagate(k);
		}
	}

	void update_query(int t, int id, int val) {
		id--;
		if (t == 1) {
			update_len(id, val);
		} else {
			update_arg(id, val);
		}
	}

	//void update(int k, P val) {
	//	k += n - 1;
	//	choose update method.
	//		// dat[k] = val;
	//		// dat[k] = dat[k] + val;
	//		while (k > 0) {
	//			k = (k - 1) / 2;
	//			propagate(k);
	//		}
	//}

	//[a,b)
	Q query(int a, int b) {
		return query(a, b, 0, 0, n);
	}

	Q query(int a, int b, int k, int l, int r) {
		if (r <= a || b <= l) return Q::zero();
		if (a <= l && r <= b) return dat[k];

		int md = (l + r) / 2; //[l,md),[md,r)
		int nl = k * 2 + 1, nr = nl + 1;
		Q lval = query(a, b, nl, l, md);
		Q rval = query(a, b, nr, md, r);

		return lval + rval;
	}
};

P q2p(Q& q) {
	return P(q.x, q.y);
}

void print(seg_tree& seg, int n) {
	FOR(i, n) {
		Q q = seg.dat[seg.n - 1 + i];
		P p = q2p(q);
		printf("%d : (%lf,%lf)\n",i,p.x,p.y);
	}
}

int main() {
	int n, q;  reader(n,q);

	seg_tree seg;
	seg.init(n);
	FOR(i, q) {
		int t, a, b; reader(t, a, b);
		seg.update_query(t, a, b);
		// print(seg, n);
		Q val = seg.query(0, n);

		P cur = q2p(val);
		printf("%.10lf %.10lf\n",(double)cur.x,(double)cur.y);
	}

	return 0;
}