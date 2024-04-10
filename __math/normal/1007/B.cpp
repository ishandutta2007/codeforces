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

int test(int a, int b, int c) {
	set<tuple<int, int, int>> st;
	FOR(i, a + 1) if (i != 0 && a % i == 0) {
		FOR(j, b + 1) if (j != 0 && b % j == 0) {
			FOR(k, c + 1) if (k != 0 && c % k == 0) {
				int cur[] = { i,j,k };
				sort(cur, cur + 3);
				st.emplace(cur[0], cur[1], cur[2]);
			}
		}
	}

	int x[] = { 0,0,0,0 };
	for (auto abc : st) {
		int a, b, c; tie(a, b, c) = abc;
		if (a == b && b == c) x[0]++;
		else if (a == b && b < c) x[1]++;
		else if (a < b && b == c) x[2]++;
		else if(a < b && b < c) x[3]++;
		else {
			cout << "?";
		}
	}

	return sz(st);
}

int cnt[ten(5) + 1];

void init() {
	for (int i = 1; i <= ten(5); i++) {
		for (int j = i; j <= ten(5); j += i) {
			cnt[j]++;
		}
	}
}

int solve(int x, int y, int z) {
	int g = cnt[gcd(gcd(x, y), z)];
	int d = cnt[gcd(x, y)] - g;
	int e = cnt[gcd(x, z)] - g;
	int f = cnt[gcd(y, z)] - g;
	int a = cnt[x] - d - e - g;
	int b = cnt[y] - d - f - g;
	int c = cnt[z] - f - e - g;

	int h[] = { a,b,c,d,e,f,g };
	int oks[3][7] = {
		{ 1,0,0,1,1,0,1 },
		{ 0,1,0,1,0,1,1 },
		{ 0,0,1,0,1,1,1 },
	};

	bool used[7][7][7] = {};
	auto checkUsed = [&](int i, int j, int k) {
		if (i > k) swap(i, k);
		if (j > k) swap(j, k);
		if (i > j) swap(i, j);
		if (used[i][j][k]) return false;
		used[i][j][k] = true;
		return true;
	};

	int part[5] = {};
	int ans = 0;
	FOR(i, 7) if (oks[0][i]) {
		FOR(j, 7) if (oks[1][j]) {
			FOR(k, 7) if (oks[2][k]) {
				if (!checkUsed(i, j, k)) {
					continue;
				}

				if (i != j && j != k && i != k) {
					int cur = h[i] * h[j] * h[k];
					ans += cur;
					part[0] += cur;
				} else if (i == j && j != k) {
					int cur = (h[i] - 1) * h[i] / 2 + h[i];
					cur *= h[k];
					ans += cur;
					part[1] += cur;
				} else if (i != j && j == k) {
					int cur = (h[j] - 1) * h[j] / 2 + h[j];
					cur *= h[i];
					ans += cur;
					part[2] += cur;
				} else if (i == k && j != k) {
					int cur = (h[k] - 1) * h[k] / 2 + h[k];
					cur *= h[j];
					ans += cur;
					part[3] += cur;
				} else {
					// i == j && j == k
					int aa = h[i];
					int bb = (h[i]) * (h[i] - 1) * (h[i] - 2);
					int cc = h[i] * h[i] * h[i] - aa - bb;
					int cur = aa + bb / 6 + cc / 3;
					ans += cur;
					part[4] += cur;
				}
			}
		}
	}

	return ans;
}

void test() {
	for (int i = 1; i <= 70; i++) {
		for (int j = 1; j <= 70; j++) {
			for (int k = 1; k <= 70; k++) {
				int a1 = test(i, j, k);
				int a2 = solve(i, j, k);
				if (a1 != a2) {
					cout << "?";
				}
			}
		}
	}
	cout << "ok" << endl;

}

int main() {
	init();
	// cout << test(83160, 83160, 83160) << endl;

	// test();

	int t; reader(t);
	while (t--) {
		int x, y, z; reader(x, y, z);

		int ans = solve(x, y, z);
		writerLn(ans);
	}

	
	return 0;
}