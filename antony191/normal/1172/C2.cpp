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
const ll llinf = 1e18, mod = 998'244'353ll;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define firn(i, n) for (int i = 1; i < (int)n; ++i)
#define all(v) v.begin(), v.end()
#define x first
#define y second

template<typename T> bool uin(T &a, T b) { if (b < a) { a = b; return 1; } return 0; }
template<typename T> bool uax(T &a, T b) { if (b > a) { a = b; return 1; } return 0; }
template<class iterator> void output(iterator begin, iterator end, char p = ' ', ostream & out = cout) { while (begin != end) { out << (*begin) << p; begin++; } out << el; }
template<class T> void output(T x, char p = ' ', ostream & out = cout) { output(all(x), p, out); }

mt19937 rnd(time(NULL));

#define int ll

ll fast(int a) {
	ll res = 1, n = mod - 2;
	while (n) {
		if (n & 1) res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}
ll ver[3001][3001];
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> a(n), w(n);
	forn(i, n) cin >> a[i];
	forn(i, n) cin >> w[i];
	int s = 0, wsum = 0, wp = 0, wm = 0;
	forn(i, n) s += a[i];
	forn(i, n) {
		wsum += w[i];
		if (a[i]) wp += w[i];
		else wm += w[i];
	}
	ver[0][0] = 1;
	forn(i, m)
		forn(j, i + 1) {
		ll tmp = fast(wsum + j - (i - j));
		ver[i + 1][j + 1] += ver[i][j] * (wp + j) % mod * tmp % mod;
		ver[i + 1][j + 1] %= mod;
		ver[i + 1][j] += ver[i][j] * (wm - (i - j)) % mod * tmp % mod;
		ver[i + 1][j] %= mod;
	}
	vector<int> dp(m + 1);
	int ans = 0;
	dp[0] = 1;
	forn(j, m) dp[j + 1] = dp[j] * (fast(wp + j) + 1) % mod;
	vector<int> dp1(m + 1);
	dp1[0] = 1;
	forn(j, m) dp1[j + 1] = dp1[j] * (1 - fast(wm - j)) % mod;
	ll ans1 = 0, ans2 = 0;
	forn(j, m + 1) ans1 = (ans1 + dp[j] * ver[m][j]) % mod;
	forn(j, m + 1) ans2 = (ans2 + dp1[j] * ver[m][m - j]) % mod;
	forn(i, n) {
		ans = 0;
		ans = (a[i] ? ans1 : ans2) * w[i] % mod;
		ans = (ans % mod + mod) % mod;
		cout << ans << el;
	}
	
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}