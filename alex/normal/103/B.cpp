#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <ctime>
#include <cmath>
#include <cassert>
#include <algorithm>

using namespace std;

typedef long double ldb;
typedef long long int64;

double const pi = 3.1415926535897932384626433832795;
int const inf = (int) 1e9;
int64 const inf64 = (int64) 2e18;

#define y1 qqqqqqq
#define forn(i, n) for (int i = 0; i < (int) n; i++)
#define ford(i, n) for (int i = (int) n - 1; i >= 0; i--)
#define seta(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define pii pair < int, int >
#define all(a) (a).begin(), (a).end()
#define mp make_pair
#define fs first
#define sc second
#define sqr(x) ((int64) x) * (x)
#define last(a) (a.size() - 1)

const string name = "b";

const int NMAX = 105;
int n, m, g[NMAX][NMAX], loop[NMAX][NMAX], used[NMAX], st[NMAX];

void dfs(int v)
{
	used[v] = 1;
	forn(i, n)
		if (!used[i] && g[v][i])
			dfs(i);
}

bool good()
{
	seta(used, 0);
	dfs(0);
	forn(i, n)
		if (!used[i]) return 0;
	return 1;
}

int main()
{
	//freopen((name + ".in").data(), "r", stdin);
	//freopen((name + ".out").data(), "w", stdout);

	cin >> n >> m;
	seta(st, 0);
	forn(i, m)
	{
		int x, y;
		cin >> x >> y;
		x--, y--;
		g[x][y] = 1;
		g[y][x] = 1;
	}

	if (!good())
	{
		cout << "NO" << endl;
		return 0;
	}

	int ok = 0;
	seta(loop, 0);
	forn(i, n)
		forn(j, i)
			if (g[i][j])
			{
				g[i][j] = g[j][i] = 0;
				if (good())
				{
					loop[i][j] = loop[j][i] = 1;
					st[i]++, st[j]++;
					ok = 1;
				}
				g[i][j] = g[j][i] = 1;
			}

	if (!ok) 
	{
		cout << "NO" << endl;
		return 0;
	}
	forn(i, n)
		if (st[i] != 0 && st[i] != 2)
		{
			cout << "NO" << endl;
			return 0;
		}

	seta(g, 0);
	forn(i, n)
		forn(j, n)
			g[i][j] = loop[i][j];
	int num = 0;
	seta(used, 0);
	forn(i, n)
		if (st[i] == 0) used[i] = 1;
	forn(i, n)
		if (!used[i])
		{
			dfs(i);
			num++;
		}
	if (num != 1)
	{
		cout << "NO" << endl;
		return 0;
	}
	cout << "FHTAGN!" << endl;
	
	return 0;
}