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
#include <deque>

#include <ctime>
#include <cassert>

using namespace std;

typedef long double ldb;
typedef long long int64;
typedef pair <int, int> pii;
typedef pair <double, double> pdd;

#define y0 wwwwwww
#define y1 qqqqqqq
#define next NEXT
#define prev PREV
#define forn(i, n) for (int i = 0; i < (int) n; i++)
#define ford(i, n) for (int i = (int) n - 1; i >= 0; i--)
#define seta(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define last(a) a[a.size() - 1]
#define mp make_pair
#define fs first
#define sc second

template <class T> T sqr(T x) { return x * x; }

double const pi = 3.1415926535897932384626433832795;
int64 const inf64 = (int64) 4e18;
const string name = "c";

int n, m, x1, y1, x2, y2;

void answer(int zn)
{
	if (zn == 0) cout << "Second" << endl;
	else cout << "First" << endl;
	exit(0);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n >> m >> x1 >> y1 >> x2 >> y2;
	n = abs(x2 - x1) + 1;
	m = abs(y2 - y1) + 1;
	if (n > m) swap(n, m);
	if (n == 1) answer(m <= 5);
	if (n == 2) answer(m <= 5);
	if (n == 3) answer(m <= 5);
	if (n == 4) answer(m <= 4);
	answer(0);

	return 0;
}