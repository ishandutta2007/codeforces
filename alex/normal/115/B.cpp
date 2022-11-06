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

const string name = "b";

const int NMAX = 151;

int n, m, ans;
char s[NMAX][NMAX];

int main()
{
	//freopen((name + ".in").data(), "r", stdin);
	//freopen((name + ".out").data(), "w", stdout);

	seta(s, 0);
	cin >> n >> m;
	forn(i, n)
		scanf("%s", s[i]);

	int x = 0, y = 0;
	ans = 0;
	forn(i, n)
	{
		int now = x;
		int dir = i & 1;
		int dx[2] = {1, -1}, need = x;

		while (now >= 0 && now < m)
		{
			if (s[i][now] == 'W' || s[i + 1][now] == 'W')
				need = now;
			now += dx[dir];
		}

		ans += abs(need - x);
		//cerr << x << " " << need << endl;
		x = need;

		int ok = 0;
		for (int xx = i + 1; xx < n; xx++)
			forn(yy, m)
				if (s[xx][yy] == 'W') ok = 1;
		ans += ok;
		if (!ok) break;
	}
	cout << ans << endl;

	return 0;
}