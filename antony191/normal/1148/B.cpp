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
const ll llinf = 3e18, mod = 1000'000'007;
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
#define int ll
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m, ta, tb, k;
	cin >> n >> m >> ta >> tb >> k;
	vector<int> a(n), b(m);
	forn(i, n) {
		cin >> a[i];
		a[i] += ta;
	}
	forn(i, m) cin >> b[i];
	int l = -1, r = m;
	while (r - l > 1) {
		int mid = (l + r) >> 1;
		int t = 0;
		int x = upper_bound(all(a), b[mid]) - a.begin() - 1, y = mid;
		while (x >= 0 && y >= 0) {
			if (a[x] <= b[y]) {
				t++;
				x--; y--;
				continue;
			}
			while (x >= 0 && a[x] > b[y]) x--;
		}
		if (t <= k) l = mid;
		else r = mid;
	}
	cout << (r < m ? b[r] + tb : -1);
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}