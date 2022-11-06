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

template <class T> T sqr(T x) { return x * x; }

double const pi = 3.1415926535897932384626433832795;
int const inf = (int) 1e9;
int64 const inf64 = (int64) 4e18;
const string name = "c";

const int NMAX = 101;
const int dx[5] = {1, 0, -1, 0, 0};
const int dy[5] = {0, 1, 0, -1, 0};

int n, m, k, best;
int x[NMAX], y[NMAX], num[NMAX][NMAX];

inline int64 modify(int64 msk, int v)
{
	forn(i, 5)
	{
		int xx = x[v] + dx[i], yy = y[v] + dy[i];
		if (xx >= 0 && xx < n && yy >= 0 && yy < m)
			msk |= (1LL << num[xx][yy]);
	}
	return msk;
}

void rec(int v, int now, int64 msk)
{
	if (now >= best) return;
	if (v == n * m)
	{
		best = now;
		return;
	}
	if (msk & (1LL << v)) rec(v + 1, now, msk);
	else
	{
		int64 zn = modify(msk, v);
		rec(v + 1, now + 1, zn);
		if (x[v] < n - 1)
		{
			zn = modify(msk, num[x[v] + 1][y[v]]);
			rec(v + 1, now + 1, zn);
		}
		if (y[v] < m - 1)
		{
			zn = modify(msk, num[x[v]][y[v] + 1]);
			rec(v + 1, now + 1, zn);
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n >> m;
	forn(i, n)
		forn(j, m)
		{
			x[k] = i, y[k] = j;
			num[i][j] = k++;
		}
	best = n * m;
	rec(0, 0, 0);
	cout << n * m - best << endl;

	return 0;
}