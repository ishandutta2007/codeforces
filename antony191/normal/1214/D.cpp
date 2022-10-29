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
const ll llinf = 1e18, mod = 1000'000'007ll;
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

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m, 1));
	forn(i, n)
		forn(j, m) {
		char c;
		cin >> c;
		if (c == '#') a[i][j] = 0;
	}
	for (int i = n - 1; i >= 0; --i)
		for (int j = m - 1; j >= 0; --j) {
			if (!a[i][j]) continue;
			if (i == n - 1 && j == m - 1) continue;
			if (i == n - 1) a[i][j] = a[i][j + 1];
			else if (j == m - 1) a[i][j] = a[i + 1][j];
			else a[i][j] = (a[i + 1][j] | a[i][j + 1]);
		}
	forn(i, n)
		forn(j, m) {
		if (!a[i][j]) continue;
		if (!i && !j) continue;
		if (!i) a[i][j] = a[i][j - 1];
		else if (!j) a[i][j] = a[i - 1][j];
		else a[i][j] = (a[i - 1][j] | a[i][j - 1]);
	}
	int ans = 2;
	for (int sum = 1; sum < n + m - 2; ++sum) {
		int tmp = 0;
		for (int i = max(0, sum - (m - 1)); i < n && i <= sum; ++i) {
			tmp += a[i][sum - i];
		}
		uin(ans, tmp);
	}
	cout << ans;
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}