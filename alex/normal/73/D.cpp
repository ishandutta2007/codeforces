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
#define seta(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define pii pair < int, int >
#define all(a) (a).begin(), (a).end()
#define mp make_pair
#define fs first
#define sc second
#define sqr(x) ((int64) x) * (x)

const string name = "d";

const int NMAX = 1000010;
int n, m, k, used[NMAX], num, cnt[NMAX], may[NMAX];
vector <int> g[NMAX];

void dfs(int v)
{
	used[v] = 1;
	cnt[num]++;
	forn(i, g[v].size())
		if (!used[g[v][i]])
			dfs(g[v][i]);
}

int main()
{
	//freopen((name + ".in").data(), "r", stdin);
	//freopen((name + ".out").data(), "w", stdout);

	cin >> n >> m >> k;
	forn(i, m)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		x--, y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	seta(used, 0);
	num = 0;
	seta(cnt, 0);
	forn(i, n)
		if (!used[i])
		{
			dfs(i);
			num++;
		}

	if (k == 1)
	{
		cout << max(0, num - 2) << endl;
		return 0;
	}

	sort(cnt, cnt + num);
	reverse(cnt, cnt + num);
	forn(i, num)
		may[i] = min(k, cnt[i]);

	int now = may[0], ans = 0;
	forn(i, num)
		if (i)
		{
			if (now > 0)
				now += may[i] - 2;
			else
			{
				ans++;
				now++;
			}
		}
	cout << ans << endl;

	return 0;
}