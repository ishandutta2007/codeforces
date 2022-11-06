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

vector <pii> ans;
int n, d[21];

void rec(int n, int x, int y, int z, bool rev)
{
	if (n == 0) return;
	int now = n - 1;
	while (now >= 0 && d[now] == d[n - 1])
		now--;
	if (now == -1)
	{
		if (rev)
			forn(i, n)
				ans.pb(mp(x, y));
		else
		{
			forn(i, n - 1)
				ans.pb(mp(x, z));
			ans.pb(mp(x, y));
			forn(i, n - 1)
				ans.pb(mp(z, y));
		}
		return;
	}

	if (now + 1 == n - 1)
	{
		rec(now + 1, x, z, y, 1);
		ans.pb(mp(x, y));
		rec(now + 1, z, y, x, 1);
	}
	else
	{
		if (!rev)
		{
			rec(now + 1, x, y, z, 1);
			forn(it, n - now - 1)
				ans.pb(mp(x, z));
			rec(now + 1, y, x, z, 1);
			forn(it, n - now - 1)
				ans.pb(mp(z, y));
			rec(now + 1, x, y, z, 0);
		}
		else
		{
			rec(now + 1, x, z, y, 1);
			forn(it, n - now - 1)
				ans.pb(mp(x, y));
			rec(now + 1, z, y, x, 1);
		}
	}
}

int main()
{
	//freopen((name + ".in").data(), "r", stdin);
	//freopen((name + ".out").data(), "w", stdout);

	cin >> n;
	forn(i, n)
		cin >> d[i];
	reverse(d, d + n);

	rec(n, 0, 2, 1, 0);
	cout << ans.size() << endl;
	forn(i, ans.size())
		printf("%d %d\n", ans[i].fs + 1, ans[i].sc + 1);

	return 0;
}