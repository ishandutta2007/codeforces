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

#ifdef _WIN32
template <typename ... Args>
void debugPrintf(const char *format, Args const & ... args) {
	fprintf(stdout, format, args ...);
	fflush(stdout);
}
#else
#define debugPrintf(...)
#endif

#define int long long

bool gfp(vector<int> x) {
	sort(x.begin(), x.end());
	while (sz(x)) {
		int p = x.back();
		if (p == 0) break;
		x.pop_back();
		FOR(i, p) {
			if (x[sz(x) - 1 - i]-- == 0) {
				return false;
			}
		}

		sort(x.begin(), x.end());
	}

	return true;
}

vector<int> naive(vector<int> a) {
	const int n = sz(a);
	a.push_back(0);
	vector<int> xx;
	FOR(i, n + 1) {
		a[n] = i;
		bool ans = gfp(a);
		if (ans)  xx.push_back(i);
	}

	return xx;
}

vector<int> solve(vector<int> a) {
	sort(a.rbegin(), a.rend());
	const int n = sz(a);

	vector<ll> sa(n + 1);
	FOR(i, n) sa[i + 1] = sa[i] + a[i];
	vector<vector<ll>> erdosGallai;

	FOR(k, 2) {
		vector<ll> cans;
		vector<ll> q;
		ll qsum = 0;
		for (int i = sz(a) - 1; i >= 0; i--) {
			int ci = i;
			if (k) ci++;
			while (sz(q) && q.back() >= ci + 1) {
				qsum -= q.back();
				q.pop_back();
			}
			int upperCount = sz(a) - 1 - i;
			ll exceeds = ll(upperCount - sz(q)) * (ci + 1);

			ll cval = ci * (ci + 1) + qsum + exceeds - sa[i + 1];
			qsum += a[i];
			q.push_back(a[i]);
			cans.push_back(cval);
		}
		reverse(cans.begin(), cans.end());
		erdosGallai.push_back(cans);
	}

	multiset<ll> upperBounds;
	FOR(i, n) upperBounds.insert(erdosGallai[1][i]);
	bool possibleLowerBound = true;
	ll cLowerBound = 0;

	vector<int> ans;
	int bobId = 0;
	for (int bob = n; bob >= 0; bob--) {
		if ((sa.back() + bob) % 2 != 0) continue;
		while (bobId < n && bob < a[bobId]) {
			upperBounds.erase(upperBounds.find(erdosGallai[1][bobId]));
			ll ccLB = -erdosGallai[0][bobId];
			if (ccLB > 0) {
				int threshould = bobId + 1;
				if (ccLB > threshould) {
					possibleLowerBound = false;
				}
				cLowerBound = max(cLowerBound, ccLB);
			}
			bobId++;
		}

		bool ok = possibleLowerBound;
		if (sz(upperBounds)) {
			if (bob > *upperBounds.begin()) {
				ok = false;
			}
		}
		if (bob < cLowerBound) {
			ok = false;
		}

		if (bobId != n) {
			ll cc = erdosGallai[0][bobId] + a[bobId] + min(bobId + 1, a[bobId]);
			if (bob > cc) {
				ok = false;
			}
		}

		if (ok) {
			ans.push_back(bob);
		}
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

void test(int n) {
	int x = 1;
	FOR(i, n) x *= n + 1;
	FOR(i, x) {
		vector<int> a;
		int y = i;
		FOR(j, n) {
			a.push_back(y % (n + 1));
			y /= n + 1;
		}
		auto a1 = solve(a);
		auto a2 = naive(a);
		if (a1 != a2) {
			cout << "?";
		}
	}
}

signed main() {
	int n; reader(n);
	vector<int> a(n); FOR(i, n) reader(a[i]);

	auto ans = solve(a);
	if (sz(ans)) {
		writerArr(ans);
	} else {
		writerLn(-1);
	}

	return 0;
}