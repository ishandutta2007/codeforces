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

int lx = inf, ly = inf, rx = -inf, ry = -inf;
bool check(int x, int y) {
	return x >= lx && x <= rx && y >= ly && y <= ry;
}
int x2 = 0, y2 = 0, r;
bool ok(int x, int y) {
	return abs(x - x2) + abs(y - y2) <= r;
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<pair<int, int>> a;
	forn(i, 4) {
		int x, y;
		cin >> x >> y;
		a.emplace_back(x, y);
		uin(lx, x); uax(rx, x); uin(ly, y); uax(ry, y);
	}
	int xmn = inf, xmx = -inf;
	forn(i, 4) {
		int x, y;
		cin >> x >> y;
		a.emplace_back(x, y);
		x2 += x; y2 += y;
		uin(xmn, x); uax(xmx, x);
	}
	x2 /= 4; y2 /= 4;
	r = (xmx - xmn) / 2;
	bool good = 0;
	forn(i, 8) {
		if (i < 4) {
			if (ok(a[i].x, a[i].y)) good = 1;
		}
		else {
			if (check(a[i].x, a[i].y)) good = 1;
		}
	}
	if (check(x2, y2)) good = 1;
	cout << (good ? "YES" : "NO");
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}