#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <queue>
#include <deque>
#include <bitset>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <random>
#include <ctime>
#include <utility>
#include <fstream>

#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")
#pragma comment(linker, "/STACK:256000000")
#pragma warning(disable:4996)

using namespace std;

typedef long long ll;
typedef long double ld;

const char el = '\n';
const int inf = 1e9;
const ll llinf = 3e18, mod = 1000'000'007, maxn = 1e5;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define firn(i, n) for (int i = 1; i < (int)n; ++i)
#define all(v) v.begin(), v.end()
#define x first
#define y second
//#define int ll

template<typename T> bool uin(T &a, T b) { if (b < a) { a = b; return 1; } return 0; }
template<typename T> bool uax(T &a, T b) { if (b > a) { a = b; return 1; } return 0; }
template<class iterator> void output(iterator begin, iterator end, char p = ' ', ostream & out = cout) { while (begin != end) { out << (*begin) << p; begin++; } out << '\n'; }
template<class T> void output(T x, char p = ' ', ostream & out = cout) { output(all(x), p, out); }

mt19937 rnd(time(NULL));

int binpow(ll a, int n = mod - 2) {
	ll res = 1ll;
	while (n) {
		if (n & 1) res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	ll ans = 1;
	for (int i = 2; i <= n; ++i) {
		vector<int> p;
		int k = i;
		bool ok = 1;
		for (int j = 2; j * j <= k; ++j) {
			if (k % j == 0) {
				if (k % (j * j) == 0) ok = 0;
				while (k % j == 0) {
					p.push_back(j);
					k /= j;
				}
			}
		}
		if (k > 1) p.push_back(k);
		if (!ok) continue;
		ll t = n / i;
		t = t * 1ll * binpow(n * 1ll) % mod;
		if ((int)p.size() & 1)
			ans += t * binpow((mod + 1 - t) % mod);
		else ans -= t * binpow((mod + 1 - t) % mod);
		ans %= mod;
	}
	ans = (ans % mod + mod) % mod;
	cout << ans;
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}