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

const int NMAX = 100010;
int n, num, tmp[NMAX];
vector <int> g[NMAX], w[NMAX];
map <pii, int> edges, rank;
pair <double, pii> q[NMAX];
vector <int> ans;
bool used[NMAX];
int64 best;
int lvl, www;

void dfs(int v)
{
	used[v] = 1;
	forn(i, g[v].size())
		if (!used[g[v][i]] && w[v][i] <= lvl)
			dfs(g[v][i]);
	www++;
}

void solve(int x, int y)
{
	lvl = 0;
	seta(used, 0);
	used[x] = used[y] = 1;
	forn(i, g[x].size())
		if (g[x][i] == y)
		{
			lvl = w[x][i];
			break;
		}
	int cnt1, cnt2;
	www = 0; dfs(x); cnt1 = www;
	www = 0; dfs(y); cnt2 = www;
	int64 cnt = (int64) cnt1 * cnt2;
	if (cnt > best)
	{
		best = cnt;
		ans.clear();
	}
	if (cnt == best) ans.pb(edges[mp(x, y)]);
}

int rec(int v, int p)
{
	int now = 1;
	used[v] = true;
	forn(i, g[v].size())
		if (!used[g[v][i]])
			now += rec(g[v][i], v);
	if (v != 0)
		q[num++] = mp((int64) now * (n - now) / (double) rank[mp(v, p)], mp(v, p));
	return now;
}

int main()
{
	//freopen((name + ".in").data(), "r", stdin);
	//freopen((name + ".out").data(), "w", stdout);

	cin >> n;
	num = 0;
	forn(i, n - 1)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		x--, y--;
		g[x].pb(y);
		w[x].pb(z);
		g[y].pb(x);
		w[y].pb(z);
		edges[mp(x, y)] = i + 1;
		edges[mp(y, x)] = i + 1;
		tmp[i] = z;
	}
	forn(i, n)
		if (g[i].size() == n - 1)
		{
			int best = -1;
			forn(j, g[i].size())
				best = max(best, w[i][j]);
			cout << 2 * (n - 1) << " ";
			int cnt = 0;
			forn(j, g[i].size())
				if (best == w[i][j]) cnt++;
			cout << cnt << endl;
			forn(j, g[i].size())
				if (best == w[i][j]) printf("%d ", edges[mp(i, g[i][j])]);
			exit(0);
		}

	sort(tmp, tmp + n - 1);
	forn(i, n)
		forn(j, g[i].size())
			rank[mp(i, g[i][j])] = lower_bound(tmp, tmp + n - 1, w[i][j]) - tmp + 1;

	rec(0, 0);
	best = -1;
	sort(q, q + num);
	reverse(q, q + num);
	forn(i, num)
	{
		if ((i & 7) == 0 && clock() > 1500)
		{
			cout << 2 * best << " " << ans.size() << endl;
			sort(all(ans));
			forn(j, ans.size())
				printf("%d ", ans[j]);
//			cerr << clock() << " " << i << endl;
			exit(0);
		}
		solve(q[i].sc.fs, q[i].sc.sc);
	}
	cout << 2 * best << " " << ans.size() << endl;
	sort(all(ans));
	forn(j, ans.size())
		printf("%d ", ans[j]);

	return 0;
}