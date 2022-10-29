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
const ll llinf = 1e18, mod = 998244353, md = 998244352;
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
const int maxn = 1000;
int a[maxn][maxn], b[maxn][maxn], c[maxn][maxn], d[maxn][maxn], e[maxn][maxn];
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	forn(i, n)
		forn(j, m) {
		char c;
		cin >> c;
		a[i][j] = c - 'a';
	}
	forn(i, n) {
		int t = 0;
		forn(j, m) {
			if (j > 0 && a[i][j - 1] != a[i][j]) t = 0;
			t++;
			b[i][j] = t;
		}
	}
	forn(j, m) {
		int t = 0, k = inf;
		forn(i, n) {
			if (i > 0 && a[i - 1][j] != a[i][j]) t = 0, k = inf;
			t++;
			uin(k, b[i][j]);
			c[i][j] = t; d[i][j] = k;
		}
		k = inf;
		for (int i = n - 1; i >= 0; --i) {
			if (i < n - 1 && a[i][j] != a[i + 1][j]) k = inf;
			uin(k, b[i][j]);
			e[i][j] = k;
		}
	}
	int ans = 0;
	forn(i, n)
		forn(j, m) {
		int tmp = inf;
		uin(tmp, d[i][j]);
		int k = c[i][j];
		if (i - k < 0 || c[i - k][j] != k) continue;
		if (i - k - k < 0 || c[i - k - k][j] < k) continue;
		uin(tmp, d[i - k][j]);
		uin(tmp, e[i - 3 * k + 1][j]);
		ans += tmp;
	}
	cout << ans;
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}