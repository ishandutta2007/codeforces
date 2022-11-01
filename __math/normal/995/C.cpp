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
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

template<typename ...> static inline int getchar_unlocked(void) { return getchar(); }
template<typename ...> static inline void putchar_unlocked(int c) { putchar(c); }
#define mygc(c) (c)=getchar_unlocked()
#define mypc(c) putchar_unlocked(c)
void reader(int& x) { int k, m = 0; x = 0; for (;;) { mygc(k); if (k == '-') { m = 1; break; }if ('0' <= k&&k <= '9') { x = k - '0'; break; } }for (;;) { mygc(k); if (k<'0' || k>'9')break; x = x * 10 + k - '0'; }if (m) x = -x; }
void reader(ll& x) { int k, m = 0; x = 0; for (;;) { mygc(k); if (k == '-') { m = 1; break; }if ('0' <= k&&k <= '9') { x = k - '0'; break; } }for (;;) { mygc(k); if (k<'0' || k>'9')break; x = x * 10 + k - '0'; }if (m) x = -x; }
int reader(char c[]) { int i, s = 0; for (;;) { mygc(i); if (i != ' '&&i != '\n'&&i != '\r'&&i != '\t'&&i != EOF) break; }c[s++] = i; for (;;) { mygc(i); if (i == ' ' || i == '\n' || i == '\r' || i == '\t' || i == EOF) break; c[s++] = i; }c[s] = '\0'; return s; }
int reader(string& c) { int i; for (;;) { mygc(i); if (i != ' '&&i != '\n'&&i != '\r'&&i != '\t'&&i != EOF) break; }c.push_back(i); for (;;) { mygc(i); if (i == ' ' || i == '\n' || i == '\r' || i == '\t' || i == EOF) break; c.push_back(i); }; return sz(c); }
template <class T, class S> void reader(T& x, S& y) { reader(x); reader(y); }
template <class T, class S, class U> void reader(T& x, S& y, U& z) { reader(x); reader(y); reader(z); }
template <class T, class S, class U, class V> void reader(T& x, S& y, U& z, V & w) { reader(x); reader(y); reader(z); reader(w); }
void writer(int x, char c) { int s = 0, m = 0; char f[10]; if (x<0)m = 1, x = -x; while (x)f[s++] = x % 10, x /= 10; if (!s)f[s++] = 0; if (m)mypc('-'); while (s--)mypc(f[s] + '0'); mypc(c); }
void writer(ll x, char c) { int s = 0, m = 0; char f[20]; if (x<0)m = 1, x = -x; while (x)f[s++] = x % 10, x /= 10; if (!s)f[s++] = 0; if (m)mypc('-'); while (s--)mypc(f[s] + '0'); mypc(c); }
void writer(const char c[]) { int i; for (i = 0; c[i] != '\0'; i++)mypc(c[i]); }
void writer(const string& x, char c) { int i; for (i = 0; x[i] != '\0'; i++)mypc(x[i]); mypc(c); }
void writer(const char x[], char c) { int i; for (i = 0; x[i] != '\0'; i++)mypc(x[i]); mypc(c); }
template<class T> void writerLn(T x) { writer(x, '\n'); }
template<class T, class S> void writerLn(T x, S y) { writer(x, ' '); writer(y, '\n'); }
template<class T, class S, class U> void writerLn(T x, S y, U z) { writer(x, ' '); writer(y, ' '); writer(z, '\n'); }
template<class T, class S, class U, class V> void writerLn(T x, S y, U z, V v) { writer(x, ' '); writer(y, ' '); writer(z, ' '); writer(v, '\n'); }
template<class T> void writerArr(T x[], int n) { if (!n) { mypc('\n'); return; }FOR(i, n - 1)writer(x[i], ' '); writer(x[n - 1], '\n'); }
template<class T> void writerArr(vector<T>& x) { writerArr(x.data(), (int)x.size()); }

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

typedef ll T;

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
	
	bool operator<(const P &a)const { return (x != a.x) ? (x < a.x) : (y < a.y); }
};

T SQ(T x) { return x*x; }
T abs2(const P& p) { return SQ(p.x) + SQ(p.y); }

vector<int> solve(vector<Pii>& _v) {
	vector<P> v;
	for (auto x : _v) {
		v.emplace_back(x.first, x.second);
	}

	auto classify = [](P p) {
		if (p.y < 0) p *= -1;
		int val = 0;
		if (abs(p.x) <= abs(p.y)) {
			val += 2;
		}
		if (p.x < 0) {
			val += 1;
		}
		return val;
	};

	vector<pair<P, int>> vp[4];
	FOR(i, sz(v)) {
		vp[classify(v[i])].emplace_back(v[i], i);
	}

	vector<int> sign;
	vector<Pii> child;
	FOR(i, sz(v)) {
		sign.push_back(0);
		child.push_back(Pii(-1, -1));
	}

	while (true) {
		bool updated = false;
		FOR(i, 4) {
			if (sz(vp[i]) <= 1) continue;
			updated = true;

			auto a1 = vp[i].back(); vp[i].pop_back();
			auto a2 = vp[i].back(); vp[i].pop_back();
			v.push_back(P());

			auto& a3 = v.back();
			int nid = sz(v) - 1;
			Pii signs;

			if (abs2(a1.first + a2.first) <= SQ(ten(6))) {
				a3 = a1.first + a2.first;
				signs = Pii(1, 1);
			} else {
				a3 = a1.first - a2.first;
				signs = Pii(1, -1);
			}

			if (abs2(a3) > SQ(ten(6))) {
				cout << "?";
			}

			sign[a1.second] = signs.first;
			sign[a2.second] = signs.second;

			vp[classify(a3)].emplace_back(a3, nid);
			sign.push_back(0);
			child.emplace_back(a1.second, a2.second);
		}
		if (!updated) break;
	}

	vector<pair<P, int>> rem;
	FOR(i, 4) if (sz(vp[i])) rem.push_back(vp[i][0]);

	int use = -1;
	FOR(i, 1 << sz(rem)) {
		P cc;
		FOR(j, sz(rem)) {
			if (i & (1 << j)) {
				cc += rem[j].first;
			} else {
				cc -= rem[j].first;
			}
		}
		bool b = abs2(cc) <= SQ(ll(1.5 * ten(6)));
		if (b) {
			use = i;
			break;
		}
	}

	if (use == -1) {
		return {};
	}

	FOR(j, sz(rem)) {
		int s;
		if (use & (1 << j)) {
			s = 1;
		} else {
			s = -1;
		}
		sign[rem[j].second] = s;
	}

	for (int i = sz(v) - 1; i >= sz(_v); i--) {
		if (sign[i] == -1) {
			int a, b; tie(a, b) = child[i];
			sign[a] *= -1;
			sign[b] *= -1;
		}
	}

	vector<int> ret(sign.begin(), sign.begin() + sz(_v));
	return ret;
}

void test() {

	//vector<Pii> ng;
	//const int C = 20;
	//FOR(i, C * 2 + 1) {
	//	FOR(j, C * 2 + 1) {
	//		int ci = i - C, cj = j - C;
	//		if (ci * ci + cj * cj >= C * C) continue;

	//		int di = abs(ci - C), dj = abs(cj);
	//		bool ok = false;
	//		if (di * di + dj * dj <= C * C) ok = true;
	//		di = abs(ci + C), dj = abs(cj);
	//		if (di * di + dj * dj <= C * C) ok = true;

	//		// printf("%d,%d : ", ci, cj);
	//		putchar(ok ? ' ' : '*');
	//		// puts("");

	//		if (!ok) {
	//			ng.emplace_back(ci, cj);
	//		}
	//	}
	//	puts("");
	//}


	int n = 100;
	vector<Pii> vp;

	auto f = []() {
		int a = (rand() % 1000);
		a *= (ten(6) / 1000);
		int b = (int)sqrt(1e12 - double(a) * a);
		if (rand() % 2 == 0) b *= -1;
		return make_pair(a, b);
	};

	FOR(i, n) vp.emplace_back(f());

	auto ans = solve(vp);

	Pii cur = { 0,0 };
	FOR(i, n) {
		if (ans[i] == 1) cur.first += vp[i].first, cur.second += vp[i].second;
		else  cur.first -= vp[i].first, cur.second -= vp[i].second;
	}

	ll val = ll(cur.first) * cur.first + ll(cur.second) * cur.second;
	if (val > 1.5 * 1.5 * 1e12) {
		cout << "?";
	}
}

int main() {
	//while (true) {
	//	test();
	//}

	int n; reader(n);
	vector<Pii> vp(n);
	FOR(i, n) reader(vp[i].first, vp[i].second);
	auto ans = solve(vp);

	//Pii cur = { 0,0 };
	//FOR(i, n) {
	//	if (ans[i] == 1) cur.first += vp[i].first, cur.second += vp[i].second;
	//	else  cur.first -= vp[i].first, cur.second -= vp[i].second;
	//}

	//ll val = ll(cur.first) * cur.first + ll(cur.second) * cur.second;
	//if (val > 1.5 * 1.5 * 1e12) {
	//	cout << "?";
	//}

	writerArr(ans);

	return 0;
}