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

struct rect {
	int lx, rx, ly, ry;
};
vector<rect> a;
bool c1(const rect & a, const rect & b) {
	return a.lx < b.lx || a.lx == b.lx && a.rx < b.rx;
}
bool c2(const rect & a, const rect & b) {
	return a.ly < b.ly || a.ly == b.ly && a.ry < b.ry;
}
bool solve2(int l, int r);
bool solve1(int l, int r) {
	if (l + 1 == r) return true;
	vector<int> tmp(1, l);
	sort(a.begin() + l, a.begin() + r, &c1);
	int mx = 0;
	for (int i = l; i < r; ++i) {
		if (i > l && a[i].lx >= mx) {
			tmp.push_back(i);
		}
		uax(mx, a[i].rx);
	}
	tmp.push_back(r);
	if (tmp.size() == 2) return false;
	bool ok = 1;
	firn(i, tmp.size()) ok &= solve2(tmp[i - 1], tmp[i]);
	return ok;
}
bool solve2(int l, int r) {
	if (l + 1 == r) return true;
	vector<int> tmp(1, l);
	sort(a.begin() + l, a.begin() + r, &c2);
	int mx = 0;
	for (int i = l; i < r; ++i) {
		if (i > l && a[i].ly >= mx) {
			tmp.push_back(i);
		}
		uax(mx, a[i].ry);
	}
	tmp.push_back(r);
	if (tmp.size() == 2) return false;
	bool ok = 1;
	firn(i, tmp.size()) ok &= solve1(tmp[i - 1], tmp[i]);
	return ok;
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	a.resize(n);
	forn(i, n) {
		cin >> a[i].lx >> a[i].ly >> a[i].rx >> a[i].ry;
	}
	cout << ((solve1(0, n) || solve2(0, n)) ? "YES" : "NO") << el;
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}