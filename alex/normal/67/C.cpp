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

const int NMAX = 4011;
int ti, td, ts, tc, n1, n2;
char s1[NMAX], s2[NMAX];
int ans[NMAX][NMAX];
int last1[150], exist1[NMAX][150];
int last2[150], exist2[NMAX][150];

inline void update(int x, int y, int xx, int yy, int s)
{
	ans[xx][yy] = min(ans[xx][yy], ans[x][y] + s);
}

int main()
{
	//freopen((name + ".in").data(), "r", stdin);
	//freopen((name + ".out").data(), "w", stdout);

	cin >> ti >> td >> tc >> ts;
	cin >> s1 >> s2;
	n1 = strlen(s1);
	n2 = strlen(s2);
	s2[n2] = '@';
	s2[n2 + 1] = '\0';

	seta(exist1, 255);
	seta(last1, 255);
	for (int i = n1 - 1; i >= 0; --i)
	{
		for (char ch = 'a'; ch <= 'z'; ch++)
			exist1[i][ch] = last1[ch];
		last1[s1[i]] = i;
	}

	seta(exist2, 255);
	seta(last2, 255);
	for (int i = n2 - 1; i >= 0; --i)
	{
		for (char ch = 'a'; ch <= 'z'; ch++)
			exist2[i][ch] = last2[ch];
		last2[s2[i]] = i;
	}

	forn(i, n1 + 1)
		forn(j, n2 + 1)
			ans[i][j] = inf;
	ans[0][0] = 0;

	int x, y;
	forn(i, n1 + 1)
		forn(j, n2 + 1)
				if (ans[i][j] < inf)
				{
					if (i < n1)
						update(i, j, i + 1, j, td);
					if (j < n2)
						update(i, j, i, j + 1, ti);
					if (i < n1 && j < n2)
					{
						if (s1[i] == s2[j])
							update(i, j, i + 1, j + 1, 0);
						else
							update(i, j, i + 1, j + 1, tc);
					}

					if (i < n1 && j < n2)
					{
						x = exist1[i][s2[j]];
						y = exist2[j][s1[i]];
						if (x > -1 && y > -1) update(i, j, x + 1, y + 1, ts + (y - j - 1) * ti + (x - i - 1) * td);
					}
				}

	cout << ans[n1][n2] << endl;

	return 0;
}