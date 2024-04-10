#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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

#pragma comment(linker,"/STACK:36777216")

template<class T> void chmax(T& l, const T r){ l = max(l, r); }
template<class T> void chmin(T& l, const T r){ l = min(l, r); }

#ifdef _WIN32
#   define mygc(c) (c)=getchar()
#   define mypc(c) putchar(c)
#else
#   define mygc(c) (c)=getchar_unlocked()
#   define mypc(c) putchar_unlocked(c)
#endif

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

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> T extgcd(T a, T b, T& x, T& y){ for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m){ T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
template<class T> T CRT(T r1, T m1, T r2, T m2) { T a1, a2; extgcd(m1, m2, a1, a2); T ret = (m1*a1*r2 + m2*a2*r1) % (m1*m2); return ret < 0 ? ret + m1 * m2 : ret; }

#pragma region {vf(struct,typedef)

typedef int T;

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

	//rp
	bool operator<(const P &a)const { return (x != a.x) ? (x < a.x) : (y < a.y); }
};


#pragma endregion

#pragma region {vf()

T SQ(T x){ return x*x; }
T dist2(const P &a, const P &b){ return SQ(a.x - b.x) + SQ(a.y - b.y); }
T abs2(const P& p){ return SQ(p.x) + SQ(p.y); }
T abs(const P& p){ return sqrt(abs2(p)); }
T dot(const P& a, const P& b){ return a.x*b.x + a.y*b.y; }
T cross(const P& a, const P& b){ return a.x*b.y - a.y*b.x; }

enum { CCW = 1, CW = -1, ON = 0 };
int ccw(const P &a, P b, P c){
	b -= a; c -= a;
	int rdir = cross(b, c);
	if (rdir> 0) return CCW; //cab(v)
	if (rdir< 0) return CW; // cab(v)
	return ON; // a,b,c
}

void P_sort(vector<P>& vp){
	//vsort
	//C3x
	auto g = [](const P& p) {
		if (p.x == 0 && p.y == 0) return 0;
		if (p.x > 0 && p.y >= 0) return 1;
		if (p.x <= 0 && p.y > 0) return 2;
		if (p.x < 0 && p.y <= 0) return 3;
		return 4;

	};
	auto f = [&g](const P&l, const P& r) {
		int gl = g(l);
		int gr = g(r);
		if (gl != gr) return gl < gr;
		P o;
		int c = ccw(o, l, r);
		return c > 0;
	};

	sort(vp.begin(), vp.end(), f);
}


int main(){
	int n; reader(n);
	vector<P> vp;
	FOR(i, n){
		int x, y; reader(x, y);
		vp.emplace_back(x, y);
	}

	ll ans = 0;
	FOR(i, n){
		map<P, int> mp;
		ll ac = 0;
		FOR(j, n){
			if (j <= i) continue;
			P p = vp[j] - vp[i];
			if (p.x == 0) {
				p.y = 1;
			} else if (p.y == 0) {
				p.x = 1;
			} else {
				if (p.x * p.y > 0) {
					p.x = abs(p.x);
					p.y = abs(p.y);
				} else {
					p.x = -abs(p.x);
					p.y = abs(p.y);
				}
				int g = gcd(abs(p.x), p.y);
				p.x /= g;
				p.y /= g;
			}

			mp[p]++;
			ac++;
		}

		for(auto kv : mp) {
			ll add = (ac - kv.second) * kv.second;
			ans += add;
		}
	}
	ans /= 2;

	cout << ans << endl;
}