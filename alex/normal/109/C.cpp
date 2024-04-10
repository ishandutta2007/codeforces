#pragma comment(linker, "/STACK:60000000")
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <sstream>
#include <iomanip>
#include <complex>
#include <queue>
#include <functional>

using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define seta(a,x) memset (a, x, sizeof (a))
#define I (int)
#define next NEXT
#define prev PREV
#define y1 dksj

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;

template <class T> T sqr (T x) {return x * x;}

const int NMAX = 100010;
int n, num, used[NMAX], cnt[NMAX], color[NMAX];
vector <int> g[NMAX];

void dfs(int v)
{
	used[v] = 1;
	color[v] = num;
	cnt[num]++;
	forn(i, g[v].size())
		if (!used[g[v][i]])
			dfs(g[v][i]);
}

int main ()
{
	//freopen ("input.txt", "r", stdin);
	//freopen ("output.txt", "w", stdout);

	cin >> n;
	forn(i, n - 1)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		x--, y--;
		int ok = 1;
		while (z > 0)
		{
			if (z % 10 != 4 && z % 10 != 7) ok = 0;
			z/=10;
		}
		if (!ok)
		{
			g[x].pb(y);
			g[y].pb(x);
		}
	}

	seta(used, 0);
	seta(cnt, 0);
	forn(i, n)
		if (!used[i])
		{
			dfs(i);
			num++;
		}

	int64 ans = 0;
	forn(i, n)
		ans += (int64) (n - cnt[color[i]]) * (n - cnt[color[i]] - 1);
	cout << ans << endl;

	return 0;
}