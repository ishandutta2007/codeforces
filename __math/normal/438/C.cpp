#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <ctime>
#include <cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>
#include <iomanip>
#include <fstream>
#include <iterator>

using namespace std;
const int MOD = 1000000007; // check!!!
const int INF = 100000000; //1e8

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
#define tenll(x) ((ll)1e##x)

inline int fastMin(int x, int y) { return x > y ? y : x; }
inline int fastMax(int x, int y) { return (((y - x) >> (32 - 1))&(x^y)) ^ y; }
inline int fastAbs(int x) { return ((x >> (32 - 1))&(x ^ (-x))) ^ x; }
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

template<class T>
struct point {
	T x, y;
	point() : x(0), y(0) {}
	point(const T& x, const T& y) : x(x), y(y) {}
	point operator+(const point &a)const { return point(x + a.x, y + a.y); }
	point& operator+=(const point &a) { x += a.x; y += a.y; return *this; }
	point operator-(const point &a)const { return point(x - a.x, y - a.y); }
	point& operator-=(const point &a) { x -= a.x; y -= a.y; return *this; }
	point operator*(const int a)const { return point(a*x, a*y); }
	point& operator*=(const int a) { x *= a; y *= a; return *this; }
	point operator/(const int a)const { return point(x / a, y / a); }
	point& operator/=(const int a) { x /= a; y /= a; return *this; }

	//rp
	bool operator<(const point &a)const { return (x != a.x) ? (x < a.x) : (y < a.y); }

};

template<class T>
struct segment {
	point<T> a, b;
	segment() : a(point<T>()), b(point<T>()) {}
	segment(const point<T>& a, const point<T>& b) : a(a), b(b) {}
};

typedef point<ll> P;
typedef segment<ll> S;

template<class T> T dot(const point<T>& a, const point<T>& b) {
	return a.x*b.x + a.y*b.y;
}
template<class T> T cross(const point<T>& a, const point<T>& b) {
	return a.x*b.y - a.y*b.x;
}

enum { CCW = 1, CW = -1, ON = 0 };
template<class T>
int ccw(const point<T> &a, point<T> b, point<T> c) {
	b -= a; c -= a;
	ll rdir = cross(b, c);
	if (rdir > 0) return CCW; //cab(v)
	if (rdir < 0) return CW; // cab(v)
	return ON; // a,b,c
}

//_
bool intersected(const S &S1, const S &S2) {
	if (max(S1.a.x, S1.b.x) < min(S2.a.x, S2.b.x)
		|| max(S1.a.y, S1.b.y) < min(S2.a.y, S2.b.y)
		|| max(S2.a.x, S2.b.x) < min(S1.a.x, S1.b.x)
		|| max(S2.a.y, S2.b.y) < min(S1.a.y, S1.b.y)) return false;
	return ccw(S1.a, S1.b, S2.a)*ccw(S1.a, S1.b, S2.b) <= 0
		&& ccw(S2.a, S2.b, S1.a)*ccw(S2.a, S2.b, S1.b) <= 0;
}

enum { POLY_OUT = -1, POLY_ON = 0, POLY_IN = 1 };
int contains(vector<P>& poly, const P& p) {
	bool in = false;
	FOR(i, sz(poly)) {
		P a = poly[i] - p, b = poly[(i + 1) % sz(poly)] - p;
		if (a.y > b.y) swap(a, b);
		if (a.y <= 0 && 0 < b.y)
			if (cross(a, b) < 0) in = !in;

		if (cross(a, b) == 0 && dot(a, b) <= 0) return POLY_ON;
	}
	return in ? POLY_IN : POLY_OUT;
}

ll dp[210][210];
bool e[200][200];
int n;
vector<P> p;

ll memo(int l, int _r) {
	ll& ret = dp[l][_r];
	if (ret != -1) return ret;
	int r = _r;
	if (r < l) r += n;
	int diff = r - l;
	if (diff <= 2) {
		return ret = 1;
	}
	ret = 0;
	for (int _i = l + 1; _i < r; _i++) {
		int i = _i % n;

		bool ok = true;
		if (_i - l != 1 && !e[i][l]) ok = false;
		if (_i + 1 != r && !e[i][_r]) ok = false;
		if (!ok) continue;

		ll a1 = memo(l, i);
		ll a2 = memo(i, _r);
		ret += a1 * a2 % MOD;
	}

	return ret %= MOD;
}

int main() {
	memset(dp, -1, sizeof(dp));
	cin >> n;
	p.resize(n);
	FOR(i, n) {
		cin >> p[i].x >> p[i].y;
		p[i].x *= 2;
		p[i].y *= 2;
	}

	vector<S> seg;
	FOR(i, n) {
		seg.push_back(S(p[i], p[(i + 1) % n]));
	}

	FOR(i, n){
		FOR(j, n) {
			int aa = (i - j + n) % n;
			if (aa <= 1 || n - aa <= 1) continue;
			S s(p[i], p[j]);
			bool ok = true;
			FOR(k, n) {
				int l = k, r = (k + 1) % n;
				if (l == i || l == j || r == i || r == j) continue;
				bool b = intersected(s, seg[k]);
				if (b) {
					ok = false;
					break;
				}
			}
			if (ok) {
				P md = (p[i] + p[j]) / 2;
				int r = contains(p, md);
				ok = (r == POLY_IN);
			}
			e[i][j] = ok;
		}
	}

	ll ans = memo(1,0);
	ans %= MOD;
	cout << ans << endl;

}