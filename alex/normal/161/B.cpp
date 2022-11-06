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

const int NMAX = 100010;

int n, k;
vector <pii> a, b;
vector <int> ans[NMAX];

void answer(double sum)
{
	printf("%.1lf\n", sum);
	forn(i, k)
	{
		cout << ans[i].size();
		forn(j, ans[i].size())
			cout << " " << ans[i][j] + 1;
		cout << endl;
	}
	exit(0);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n >> k;
	forn(i, n)
	{
		int x, y;
		cin >> x >> y;
		if (y == 1) a.pb(mp(x, i));
		else b.pb(mp(x, i));
	}
	sort(all(a));
	sort(all(b));
	if ((int) a.size() < k)
	{
		double sum = 0;
		forn(i, a.size())
			sum += a[i].fs / 2.;
		forn(i, b.size())
			sum += b[i].fs;

		forn(i, a.size())
			ans[i].pb(a[i].sc);
		forn(i, (k - a.size()))
			ans[i + a.size()].pb(b[i].sc);
		for (int i = k - (int) a.size(); i < (int) b.size(); ++i)
			ans[k - 1].pb(b[i].sc);
		answer(sum);
	}
	
	double sum = 0;
	forn(i, a.size())
		sum += a[i].fs;
	forn(i, b.size())
		sum += b[i].fs;
	forn(i, k - 1)
		sum -= a[a.size() - i - 1].fs / 2.;
	if (a.size() == 0) sum -= b[0].fs / 2.;
	else if (b.size() == 0) sum -= a[0].fs / 2.;
	else sum -= min(a[0].fs, b[0].fs) / 2.;

	forn(i, k)
		ans[i].pb(a[a.size() - i - 1].sc);
	forn(i, a.size() - k)
		ans[k - 1].pb(a[i].sc);
	forn(i, b.size())
		ans[k - 1].pb(b[i].sc);
	answer(sum);

	return 0;
}