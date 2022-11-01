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

const double PI = acos(-1.0);

#pragma region (struct,typedef)

typedef double T;

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

struct S {
	P a, b;
	S() {}
	S(const P& a, const P& b) : a(a), b(b) {}
};

struct line {
	P a, b;
	line() : a(P()), b(P()) {}
	line(const P& a, const P& b) : a(a), b(b) {}
};

struct circle {
	P c;
	T r;
	circle() {}
	circle(const P &c, T& r) : c(c), r(r) {}
};

#pragma endregion
const double EPS = 1e-8;

#pragma region ()

T SQ(T x) { return x*x; }
T dist2(const P &a, const P &b) { return SQ(a.x - b.x) + SQ(a.y - b.y); }
T abs2(const P& p) { return SQ(p.x) + SQ(p.y); }
T abs(const P& p) { return sqrt(abs2(p)); }
T dot(const P& a, const P& b) { return a.x*b.x + a.y*b.y; }
T cross(const P& a, const P& b) { return a.x*b.y - a.y*b.x; }
P rot(const P& a, const double theta) {
	return P(a.x*cos(theta) - a.y*sin(theta),
		a.x*sin(theta) + a.y*cos(theta));
}
double arg(const P &a) { double t = atan2(a.y, a.x); return t<0 ? t + 2 * PI : t; }

enum { CCW = 1, CW = -1, ON = 0 };
int ccw(const P &a, P b, P c) {
	b -= a; c -= a;
	double rdir = cross(b, c);
	double len = abs(b) * abs(c); // ()
	if (rdir> EPS * len) return CCW; //cab()
	if (rdir<-EPS * len) return CW; // cab()
	return ON; // a,b,c
}

P move_to(double v, P w) {
	double y = w.y;
	double x = sqrt(v * v - y * y);
	return P(x + w.x, y);
}

double solve(double len,double maxv, double t, P v, P w) {
	double fmove = sqrt(maxv * maxv - v.y * v.y) + v.x;
	double ans1 = len / fmove;
	if (ans1 <= t) return ans1;

	auto f = [&](double md) {
		P to(maxv,0);
		to = (rot(to, md) + v) * t;
		P dir = P(len, 0) - to;
		double rem = abs(dir);
		P cw = rot(w, -arg(dir));
		double vlast = sqrt(maxv * maxv - cw.y * cw.y) + cw.x;
		return t + rem / vlast;
	};

	double l = -PI / 2, r = PI / 2;
	FOR(_, 100) {
		double md1 = (l + l + r) / 3, md2 = (l + r + r) / 3;
		double a1 = f(md1);
		double a2 = f(md2);
		if (a1 < a2) r = md2;
		else l = md1;
	}
	return f(l);
}

int main(){
	double x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
	P to(x2 - x1, y2 - y1);
	double vmax, t; cin >> vmax >> t;
	double vx, vy, wx, wy; cin >> vx >> vy >> wx >> wy;
	P v(vx, vy), w(wx, wy);

	double angle = -arg(to);
	double len = abs(to);
	v = rot(v, angle);
	w = rot(w, angle);

	double ans = solve(len, vmax, t, v, w);
	printf("%.15lf\n",ans);

	return 0;
}