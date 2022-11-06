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
#define last(a) a[a.size() - 1]
#define mp make_pair
#define fs first
#define sc second
#define I (int)

template <class T> T sqr(T x) { return x * x; }

double const pi = 3.1415926535897932384626433832795;
int const inf = (1 << 30) - 1;
int64 const inf64 = (1LL << 62) - 1;
const string name = "a";

int const NMAX = 8;
const int dx[9] = {-1, -1, -1, 1, 1, 1, 0, 0, 0};
const int dy[9] = {-1, 0, 1, -1, 0, 1, -1, 1, 0};

char s[NMAX][NMAX];
int n, xs, ys, xf, yf, used[20][NMAX][NMAX];
int zn[22][NMAX][NMAX], q1[NMAX * NMAX * 20],  q2[NMAX * NMAX * 20],  q3[NMAX * NMAX * 20];

int good(int x, int y)
{
	return (x >= 0 && x < 8 && y >= 0 && y < 8);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	n = 8;
	forn(i, n)
		cin >> s[i];
	forn(i, n)
		forn(j, n)
		{
			if (s[i][j] == 'M') xs = i, ys = j;
			if (s[i][j] == 'A') xf = i, yf = j;
		}
	seta(zn, 0);
	forn(i, 20)
	{
		forn(x, n)
			forn(y, n)
				if (s[x][y] == 'S' && x + i < 8) zn[i][x + i][y] = 1;
	}

	int h = 0, t = 1;
	q1[0] = 0, q2[0] = xs, q3[0] = ys;
	seta(used, 0);
	used[0][xs][ys] = 1;
	while (h < t)
	{
		int tt = q1[h], x = q2[h], y = q3[h];
		h++;
		if (tt >= 18) continue;
		forn(i, 9)
			if (good(x + dx[i], y + dy[i]) && !used[tt + 1][x + dx[i]][y + dy[i]] &&!zn[tt][x + dx[i]][y + dy[i]] && (!zn[tt + 1][x + dx[i]][y + dy[i]] || (x + dx[i] == xf && y + dy[i] == yf)))
			{
				used[tt + 1][x + dx[i]][y + dy[i]] = 1;
				q1[t] = tt + 1;
				q2[t] = x + dx[i];
				q3[t] = y + dy[i];
				t++;
			}
	}
	forn(i, 20)
		if (used[i][xf][yf])
		{
			cout << "WIN" << endl;
			return 0;
		}
	cout << "LOSE" << endl;

	return 0;
}