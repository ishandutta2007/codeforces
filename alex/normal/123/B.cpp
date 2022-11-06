#pragma comment(linker, "/STACK:60000000")
//#define _MY_OPT_MODE_
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>

#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <stack>
#include <list>

#include <ctime>
#include <cassert>

using namespace std;

typedef long double ldb;
typedef long long int64;
typedef pair <int, int> pii;

#define y0 wwwwwww
#define y1 qqqqqqq
#define next NEXT
#define prev PREV
#define forn(i, n) for (int i = 0; i < (int) n; i++)
#define ford(i, n) for (int i = (int) n - 1; i >= 0; i--)
#define seta(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define last(a) a[a.size() - 1];
#define mp make_pair
#define fs first
#define sc second
#define I (int)

template <class T> T sqr(T x) { return x * x; }

double const pi = 3.1415926535897932384626433832795;
int const inf = (1 << 30) - 1;
int64 const inf64 = (1LL << 62) - 1;
const string name = "b";

int64 a, b, x1, y1, x2, y2, x, y;

int64 calc(int64 l, int64 r, int64 zn)
{
	if (l > r) swap(l, r);
	l += (int64) (zn * 2e9);
	r += (int64) (zn * 2e9);
	return r / zn - l / zn;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> a >> b;
	a *= 2, b *= 2;
	cin >> x >> y;
	x1 = x + y, y1 = x - y;
	cin >> x >> y;
	x2 = x + y, y2 = x - y;

	cout << max(calc(x1, x2, a), calc(y1, y2, b)) << endl;

	return 0;
}