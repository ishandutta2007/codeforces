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

int maxx, maxy, w, calc[100010], pal[100010];
vector <int> ans[100010], qqq[100010];

int rev(int n)
{
	int res = 0;
	while (n > 0)
	{
		res = res * 10 + n % 10;
		n /= 10;
	}
	return res;
}

int find(int w)
{
	int d = 2, ww = calc[w];
	while (d * d <= w)
	{
		while (w % d == 0)
		{
			if (ww % d == 0) ww /= d;
			w /= d;
		}
		d++;
	}
	if (ww % w == 0) ww /= w;
	return ww;
}

int main()
{
	//freopen((name + ".in").data(), "r", stdin);
	//freopen((name + ".out").data(), "w", stdout);

	cin >> maxx >> maxy >> w;
	forn(i, max(maxx, maxy) + 1)
		calc[i] = rev(i);
	seta(pal, 0);
	forn(i, max(maxx, maxy) + 1)
		if (calc[i] == i) pal[i] = 1;

	int now, st;
	for (int i = 1; i <= maxx; ++i)
	{
		st = find(i);
		now = st;
		while (now <= maxy)
		{
			if ((int64) i * now == (int64) calc[i] * calc[now])
				ans[i].pb(now), qqq[now].pb(i);
			now += st;
		}
	}

	int64 ansx = 100001, ansy = 100001, lvl = 1;
	now = 0;
	for (int i = maxx; i >= 1; i--)
	{
		while (lvl <= maxy && now < w)
			now += qqq[lvl++].size();
		if (now >= w && (int64) i * (lvl - 1) < ansx * ansy)
			ansx = i, ansy = lvl - 1;

		forn(j, ans[i].size())
		{
			if (ans[i][j] < lvl) now--;
			qqq[ans[i][j]].resize(qqq[ans[i][j]].size() - 1);
		}
	}

	if (ansx > maxx) cout << -1 << endl;
	else cout << ansx << " " << ansy << endl;
	//cerr << clock() << endl;

	return 0;
}