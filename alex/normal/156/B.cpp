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
const string name = "b";

const int NMAX = 100100;
int n, m, GLOB, ans[NMAX];
vector <int> g[2][NMAX];

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n >> m;
	GLOB = 0;
	int minus = 0;
	forn(i, n)
	{
		char ch = ' ';
		while (ch != '+' && ch != '-')
			scanf("%c", &ch);
		int x;
		scanf("%d", &x);
		x--;
		if (ch == '+') g[0][x].pb(i);
		else
		{
			g[1][x].pb(i);
			minus++;
		}
	}

	seta(ans, 0);
	forn(i, n)
	{
		int now = g[0][i].size() + (minus - g[1][i].size());
		if (now == m)
		{
			forn(j, g[0][i].size())
				ans[g[0][i][j]] = 1;
			forn(j, g[1][i].size())
				ans[g[1][i][j]] = -1;
			GLOB++;
		}
		else
		{
			forn(j, g[0][i].size())
				ans[g[0][i][j]] = -2;
			forn(j, g[1][i].size())
				ans[g[1][i][j]] = 2;
		}
	}
	forn(i, n)
	{
		if (ans[i] == 1 && GLOB == 1) printf("Truth\n");
		else if (ans[i] == 2) printf("Truth\n");
		else if (ans[i] == -1 && GLOB == 1) printf("Lie\n");
		else if (ans[i] == -2) printf("Lie\n");
		else printf("Not defined\n");
	}

	return 0;
}