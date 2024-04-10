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

#define int ll
int gcd(int a, int b) {
	while (b > 0) {
		a %= b;
		swap(a, b);
	}
	return a;
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		vector<int> a(n);
		forn(i, n) cin >> a[i];
		sort(all(a)); reverse(all(a));
		int x, c, y, d;
		cin >> x >> c >> y >> d;
		if (x < y) swap(x, y), swap(c, d);
		int t = c / gcd(c, d) * d;
		int l = 0, r = n + 1, k;
		cin >> k;
		while (r - l > 1) {
			int m = (l + r) >> 1, ans = 0;
			for (int i = 0; i < (m / t); ++i) ans += (a[i] / 100) * (x + y);
			for (int i = (m / t); i < m / c; ++i) ans += (a[i] / 100) * x;
			for (int i = (m / c); i < (m / d) + (m / c) - (m / t); ++i) ans += (a[i] / 100) * y;
			if (ans >= k)
				r = m;
			else l = m;
		}
		cout << (r <= n ? r : -1) << el;
	}
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}