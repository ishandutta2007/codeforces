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

const int NMAX = 1010;
int n, lvl, next[NMAX], prev[NMAX], next_w[NMAX], prev_w[NMAX], m;
vector <pair<pii, int> > ans;

int rec(int v)
{
	if (next[v] == -1) return v;
	lvl = min(lvl, next_w[v]);
	return rec(next[v]);
}

int main()
{
	//freopen((name + ".in").data(), "r", stdin);
	//freopen((name + ".out").data(), "w", stdout);

	seta(prev, 255);
	seta(next, 255);
	cin >> n >> m;
	forn(i, m)
	{
		int x, y, z;
		cin >> x >> y >> z;
		x--, y--;
		next[x] = y;
		next_w[x] = z;
		prev[y] = x;
		prev_w[y] = z;
	}

	forn(i, n)
		if (prev[i] == -1 && next[i] != -1)
		{
			lvl = next_w[i];
			int v = rec(i);
			ans.pb(mp(mp(i, v), lvl));
		}

	cout << ans.size() << endl;
	forn(i, ans.size())
		cout << ans[i].fs.fs + 1 << " " << ans[i].fs.sc + 1 << " " << ans[i].sc << endl;

	return 0;
}