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

const string name = "c";

const int NMAX = 100010;

int n, a[NMAX], s;
vector <int> g[NMAX];
vector < pair <int64, int > > ch[NMAX];
bool used[NMAX];
int64 ans[NMAX];

void dfs(int v)
{
	used[v] = true;
	forn(i, g[v].size())
		if (!used[g[v][i]])
		{
			ch[v].pb(mp(0, g[v][i]));
			dfs(g[v][i]);
		}
	forn(i, ch[v].size())
		ch[v][i].fs = -ans[ch[v][i].sc];
	sort(all(ch[v]));
	int64 sum = 0;
	a[v]--;
	int tmp = min(a[v], (int) ch[v].size());
	forn(i, tmp)
		if (ch[v][i].fs < 0)
		{
			a[v]--;
			a[ch[v][i].sc]--;
			sum += 2 - ch[v][i].fs;
		}
	forn(i, ch[v].size()) 
		if (a[v] > 0 && a[ch[v][i].sc] > 0)
		{
			int d = min(a[v], a[ch[v][i].sc]);
			a[v] -= d;
			a[ch[v][i].sc] -= d;
			sum += 2 * d;
		}
	ans[v] = sum;
	a[v]++;
}

int main()
{
	//freopen((name + ".in").data(), "r", stdin);
	//freopen((name + ".out").data(), "w", stdout);

	cin >> n;
	forn(i, n)
		scanf("%d", &a[i]);
	forn(i, n - 1)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		x--, y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	cin >> s;
	s--;
	a[s]++;

	seta(used, 0);
	dfs(s);

	cout << max(0LL, ans[s]) << endl;

	return 0;
}