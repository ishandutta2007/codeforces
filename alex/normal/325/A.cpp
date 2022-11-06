#pragma comment(linker, "/STACK:600000000")
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
int const inf = (int) 1e9;
int64 const inf64 = (int64) 4e18;
const string name = "a";

const int NMAX = 1005;
const int dx[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
const int dy[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

int n, x1[NMAX], y1[NMAX], x2[NMAX], y2[NMAX];
int _minx, _maxx, _miny, _maxy;

void check(int x, int y)
{
	int ans1 = (x >= _minx && x <= _maxx && y >= _miny && y <= _maxy);
	int ans2 = 0;
	forn(i, n)
		if (x >= x1[i] && x <= x2[i] && y >= y1[i] && y <= y2[i]) ans2 = 1;
	if (ans1 != ans2)
	{
		cout << "NO" << endl;
		exit(0);
	}

}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n;
	_minx = inf, _maxx = -inf;
	_miny = inf, _maxy = -inf;
	forn(i, n)
	{
		cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
		x1[i] *= 2, y1[i] *= 2;
		x2[i] *= 2, y2[i] *= 2;
		_minx = min(_minx, min(x1[i], x2[i]));
		_maxx = max(_maxx, max(x1[i], x2[i]));
		_miny = min(_miny, min(y1[i], y2[i]));
		_maxy = max(_maxy, max(y1[i], y2[i]));
	}
	if (_maxx - _minx != _maxy - _miny)
	{
		cout << "NO" << endl;
		return 0;
	}

	forn(i, n)
		forn(j, 9)
		{
			check(x1[i] + dx[j], y1[i] + dy[j]);
			check(x1[i] + dx[j], y2[i] + dy[j]);
			check(x2[i] + dx[j], y1[i] + dy[j]);
			check(x2[i] + dx[j], y2[i] + dy[j]);
		}
	cout << "YES" << endl;

	return 0;
}