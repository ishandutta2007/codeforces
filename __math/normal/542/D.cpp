#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <limits>
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
#include <bitset>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
#define tenll(x) ((ll)1e##x)

// #pragma comment(linker,"/STACK:36777216")

template<class T> void chmax(T& l, const T r) { l = max(l, r); }
template<class T> void chmin(T& l, const T r) { l = min(l, r); }

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


bool prime[1000001]; //10^6
vector<int> prs;

//f
void init_prime() {
	memset(prime, 1, sizeof(prime));
	prime[0] = prime[1] = false;
	for (int i = 2; i < sizeof(prime); i++) if (prime[i])
		for (int j = i * 2; j < sizeof(prime); j += i) prime[j] = false;
	for (int i = 2; i < sizeof(prime); i++) if (prime[i]) prs.push_back(i);
}

bool is_prime(ll n) {
	for (ll p : prs) {
		if (p * p > n) return true;
		if (n % p == 0) return false;
	}
	return true;
}
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

int greedy(int n) {
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int cur = 0;
		for (int k = 1; k <= i; k++) if (i % k == 0 && gcd(k,i/k) == 1) cur += k;
		if (cur == n)
			ans++;
	}
	return ans;
}

bool can_div[ten(6)];

int f(ll a) {
	if (a == 1) return 1;
	if (a == 2) return 0;
	for (int i = 1; i < ten(6); i++) {
		if (i > a) break;
		if (a % i == 0) {
			can_div[i] = true;
		}
	}
	map<ll, int> mp;
	mp[a] = 1;
	for (ll p : prs) {
		map<ll, int> add;
		for (ll np = p; np < a; np *= p) {
			const ll b = np + 1;
			if (b < ten(6)) {
				if (!can_div[b]) continue;
			} else {
				if (a % b != 0) continue;
			}
			for (auto it = mp.rbegin(); it != mp.rend(); ++it) {
				auto& kv = *it;
				if (kv.first < b) break;
				if (kv.first % b == 0) {
					add[kv.first / b] += kv.second;
				}
			}
		}
		for (auto kv : add) {
			mp[kv.first] += kv.second;
		}
	}

	ll ans = 0;
	ans += mp[1];
	for (auto kv : mp) {
		if (kv.first <= ten(6)) continue;
		ll x = kv.first - 1;
		if (is_prime(x)) ans += kv.second;
	}
	return ans;
}

int main() {
	init_prime();
	//for (int i = 5; i <= 1000; i++) {
	//	int cur = f(i);
	//	int g = greedy(i);
	//	if (cur != g) {
	//		cout << i << "?" << endl;
	//	}
	//}
	ll a; cin >> a;
	int ans = f(a);

	cout << ans << endl;

}