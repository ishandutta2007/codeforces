#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <set>
#include <ctime>
#include <cmath>
#include <algorithm>

using namespace std;

double const pi = 3.1415926535897932384626433832795;

#define y1 qqqqqqq
#define forn(i, n) for (int i = 0; i < (int) n; i++)
#define seta(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define pii pair < double, double >
#define mp make_pair
#define fs first
#define sc second

int const NMAX = 10001;

int n, m, used[NMAX], st[NMAX], cmp;
vector <int> g[NMAX], num[NMAX], ans;
bool fict, us_edge[NMAX];

void dfs(int v)
{
	used[v] = cmp;
	forn(i, g[v].size())
		if (used[g[v][i]] == -1) dfs(g[v][i]);
}

void eiler(int v, int e)
{
	forn(i, g[v].size())
		if (!us_edge[num[v][i]])
		{
			us_edge[num[v][i]] = true;
			eiler(g[v][i], num[v][i]);
		}
	if (e >= 0) ans.pb(e);
}

void solve(int v)
{
	eiler(v, -1);

	forn(i, ans.size())
		if (ans[i] == m)
		{
			cout << i << endl;
			forn(j, i)
				printf("%d ", ans[j] + 1);
			cout << endl;
			cout << ans.size() - i - 1 << endl;
			forn(j, ans.size())
				if (j > i) printf("%d ", ans[j] + 1);
			cout << endl;
			exit(0);
		}

	cout << ans.size() - 1 << endl;
	forn(j, ans.size() - 1)
		printf("%d ", ans[j] + 1);
	cout << endl;
	cout << 1 << endl;
	printf("%d ", ans[ans.size() - 1] + 1);
	cout << endl;
	exit(0);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	n = NMAX - 1;
	cin >> m;
	seta(st, 0);
	forn(i, m)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		x--,y--;
		st[x]++, st[y]++;
		g[x].pb(y);
		num[x].pb(i);
		g[y].pb(x);
		num[y].pb(i);
	}

	cmp = 0;
	seta(used, 255);
	forn(i, n)
		if (used[i] == -1 && g[i].size() > 0)
		{
			dfs(i);
			cmp++;
		}

	vector <int> interest;
	forn(i, n)
		if (st[i] % 2 == 1)
			interest.pb(i);
	forn(i, n)
	{
		bool flag = false;
		forn(j, interest.size())
			if (used[i] == used[interest[j]]) flag = true;
		if (used[i] >= 0 && !flag) interest.pb(i);
	}

	if (cmp > 2 || interest.size() > 4 || m <= 1)
	{
		cout << -1 << endl;
		return 0;
	}

	fict = false;
	bool may[4];
	seta(may, 1);
	forn(i, interest.size())
		forn(j, interest.size())
			if (used[interest[i]] != used[interest[j]] && !fict)
			{
				g[interest[i]].pb(interest[j]);
				num[interest[i]].pb(m);
				g[interest[j]].pb(interest[i]);
				num[interest[j]].pb(m);
				may[i] = may[j] = false;
				fict = true;
			}
	forn(i, interest.size())
		forn(j, interest.size())
			if (interest[i] != interest[j] && !fict && interest.size() > 2)
			{
				g[interest[i]].pb(interest[j]);
				num[interest[i]].pb(m);
				g[interest[j]].pb(interest[i]);
				num[interest[j]].pb(m);
				may[i] = may[j] = false;
				fict = true;
			}

	seta(us_edge, 0);
	forn(i, interest.size())
		if (may[i]) solve(interest[i]);
	solve(interest[0]);

	return 0;
}