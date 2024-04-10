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
#include <cassert>
#include <sstream>

#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("vpt")
#pragma comment(linker, "/STACK:256000000")
#pragma warning(disable:4996)

using namespace std;

typedef long long ll;
typedef long double ld;

const char el = '\n';
const int inf = 1e9;
const ll llinf = 1e18, mod = 1000'000'007;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define firn(i, n) for (int i = 1; i < (int)n; ++i)
#define all(v) v.begin(), v.end()
#define x first
#define y second
#define pb push_back
#define debug(x) cout << #x << ": " << x << el

template<typename T> bool uin(T &a, T b) { if (b < a) { a = b; return 1; } return 0; }
template<typename T> bool uax(T &a, T b) { if (b > a) { a = b; return 1; } return 0; }
template<class iterator> void output(iterator begin, iterator end, char p = ' ', ostream & out = cout) { while (begin != end) { out << (*begin) << p; begin++; } out << el; }
template<class T> void output(T x, char p = ' ', ostream & out = cout) { output(all(x), p, out); }

mt19937 rnd(time(NULL));

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n), b(n + n, n);
		forn(i, n) cin >> a[i];
		for (int i = n - 1; i >= 0; --i) {
			if (i == n - 1 || a[i] > a[i + 1]) b[i] = i + 1;
			else b[i] = b[i + 1];
		}
		int g = 0, s = 0, br = 0;
		for (int i = 1; (3 * i + 2) * 2 <= n; ++i) {
			int k = b[i - 1];
			if (k != i) continue;
			int r = b[i + i];
			int l = b[r + i];
			if (l + l <= n && g == 0) {
				while (l + l <= n) {
					if (b[l] + b[l] > n) break;
					l = b[l];
				}
				g = i;
				s = r - i;
				br = l - g - s;
			}
		}
		cout << g << ' ' << s << ' ' << br << el;
	}
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}