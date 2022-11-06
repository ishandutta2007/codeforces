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

int const NMAX = 100010;
int const inf = (int) 1e9;
char s[NMAX], s1[NMAX], s2[NMAX];
int n, m, g[300][300];

int get(char ch1, char ch2, char &ch)
{
	ch = 0;
	int best = inf;

	forn(i, 300)
		if (g[ch1][i] + g[ch2][i] < best)
		{
			best = g[ch1][i] + g[ch2][i];
			ch = i;
		}
	return best;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%s%s", s1, s2);
	if (strlen(s1) != strlen(s2))
	{
		cout << -1 << endl;
		return 0;
	}
	n = strlen(s1);

	cin >> m;
	forn(i, 300)
		forn(j, 300)
			if (i == j) g[i][j] = 0;
			else g[i][j] = inf;
	forn(i, m)
	{
		char sim1[3], sim2[3];
		int w;
		scanf("%s%s%d", sim1, sim2, &w);
		g[sim1[0]][sim2[0]] = min(g[sim1[0]][sim2[0]], w);
	}

	forn(k, 300)
		forn(i, 300)
			forn(j, 300)
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);

	int ans = 0;
	forn(i, n)
		if (get(s1[i], s2[i], s[i]) >= inf)
		{
			cout << -1 << endl;
			return 0;
		}
		else ans += get(s1[i], s2[i], s[i]);

	s[n] = '\0';
	cout << ans << endl;
	printf("%s", s);

	return 0;
}