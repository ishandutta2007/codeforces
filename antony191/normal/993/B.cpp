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
//#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
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

bool check(pair<int, int> a, pair<int, int> b) {
	return (a.x == b.x || a.x == b.y || a.y == b.x || a.y == b.y) && a != b;
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> a(n), b(m);
	forn(i, n) {
		cin >> a[i].x >> a[i].y;
		if (a[i].x > a[i].y) swap(a[i].x, a[i].y);
	}
	forn(i, m) {
		cin >> b[i].x >> b[i].y;
		if (b[i].x > b[i].y) swap(b[i].x, b[i].y);
	}
	set<int> ans;
	bool ok = 1;
	forn(i, n)
		forn(j, m) {
		if (!check(a[i], b[j])) continue;
		int c = (a[i].x == b[j].x || a[i].x == b[j].y) ? a[i].x : a[i].y;
		ans.insert(c);
		c = a[i].x + a[i].y - c;
		forn(k, m) {
			if ((b[k].x == c || b[k].y == c) && a[i] != b[k]) ok = 0;
		}
		c = a[i].x + a[i].y - c;
		c = b[j].x + b[j].y - c;
		forn(k, n) {
			if ((a[k].x == c || a[k].y == c) && a[k] != b[j]) ok = 0;
		}
	}
	if (ans.size() == 1) cout << *ans.begin();
	else {
		cout << (ok ? 0 : -1);
	}
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}