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

const string name = "a";

const int NMAX = 2010;
int n, ans, p[NMAX], used[NMAX];
vector <int> g[NMAX];

int dfs(int v)
{
	used[v] = 1;
	int res = 0;
	forn(i, g[v].size())
		if (!used[g[v][i]])
			res = max(res, dfs(g[v][i]));
	return res + 1;
}

int main()
{
	//freopen((name + ".in").data(), "r", stdin);
	//freopen((name + ".out").data(), "w", stdout);

	cin >> n;
	forn(i, n)
	{
		scanf("%d", &p[i]);
		if (p[i] >= 0) p[i]--;
		if (p[i] >= 0)
			g[p[i]].pb(i);
	}
	seta(used, 0);
	ans = 0;
	forn(i, n)
		if (p[i] == -1 && !used[i]) ans = max(ans, dfs(i));
	cout << ans << endl;

	return 0;
}