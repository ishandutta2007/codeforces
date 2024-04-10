#pragma comment(linker, "/STACK:600000000")
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
typedef pair <double, double> pdd;

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

template <class T> T sqr(T x) { return x * x; }

double const pi = 3.1415926535897932384626433832795;
int const inf = (int) 1e9;
int64 const inf64 = (int64) 4e18;
const string name = "c";

const int NMAX = 200010;

int used[NMAX], n, m;
vector<int> g[NMAX], now[NMAX];
vector<pair<pii, int > > ans;
set<pii> kill;

int dfs(int v, int p) {
	used[v] = 1;
	forn(i, g[v].size()) {
		if (kill.find(mp(v, g[v][i])) != kill.end()) continue; 
		kill.insert(mp(v, g[v][i]));
		kill.insert(mp(g[v][i], v));
		if (used[g[v][i]]) now[v].pb(g[v][i]);
		else {
			int newson = dfs(g[v][i], v);
			if (newson == -1) now[v].pb(g[v][i]);
			else {
				//cerr << v << " " << g[v][i] << " " << newson << endl;
				ans.pb(mp(mp(v, g[v][i]), newson));
			}
		}
	}
	forn(i, now[v].size() / 2) {
		//cerr << now[v][2 * i] << " " << v << " " << now[v][2 * i + 1] << endl;
		ans.pb(mp(mp(now[v][2 * i], v), now[v][2 * i + 1]));
	}
	if (now[v].size() % 2 == 1)
		return now[v][now[v].size() - 1];
	else
		return -1;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n >> m;
	forn(i, m) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--, y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	seta(used, 0);
	ans.clear();
	if (dfs(0, -1) >= 0) cout << "No solution" << endl;
	else {
		forn(i, ans.size())
			printf("%d %d %d\n", ans[i].fs.fs + 1, ans[i].fs.sc + 1, ans[i].sc + 1);
	}

	return 0;
}