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
ll ver[51][51][51];
ll mat[51][51][51];
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
	forn(i, n) {
		forn(j, m + 1)
			forn(k, m + 1)
			forn(t, m + 1)
			ver[j][k][t] = 0;
		ver[0][0][0] = 1;
		forn(j, m) {
			forn(k, j + 1)
				forn(t, j + 1) {
				ll tmp = fast(wsum + t - (j - t));
				ver[j + 1][k][t + 1] += ver[j][k][t] * (wp + t + (a[i] ? -(w[i] + k) : 0)) % mod * tmp % mod;
				ver[j + 1][k][t + 1] %= mod;
				ver[j + 1][k][t] += ver[j][k][t] *
					(wm - (j - t) + (!a[i] ? -(w[i] - k) : 0)) % mod * tmp % mod;
				ver[j + 1][k][t] %= mod;
				if (a[i]) {
					ver[j + 1][k + 1][t + 1] += ver[j][k][t] * (w[i] + k) % mod * tmp % mod;
					ver[j + 1][k + 1][t + 1] %= mod;
				}
				else {
					ver[j + 1][k + 1][t] += ver[j][k][t] * (w[i] - k) % mod * tmp % mod;
					ver[j + 1][k + 1][t] %= mod;
				}
			}
		}
		ll ans = 0;
		forn(k, m + 1)
			forn(t, m + 1)
			ans = (ans + ver[m][k][t] * (w[i] + (a[i] ? k : -k))) % mod;
		cout << ans << el;
	}
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}