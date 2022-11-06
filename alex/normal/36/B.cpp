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

int n, k, m;
char s[5][5];
char ans[900][900], tmp[900][900];

void next()
{
	memcpy(tmp, ans, sizeof(tmp));
	forn(i, m)
		forn(j, m)
			forn(ii, n)
				forn(jj, n)
					if (tmp[i][j] == '*')
						ans[i * n + ii][j * n + jj] = '*';
					else
						ans[i * n + ii][j * n + jj] = s[ii][jj];
	m *= n;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> n >> k;
	forn(i, n)
	{
		cin >> s[i];
		memcpy(ans[i], s[i], n);
	}

	m = n;
	forn(i, k - 1)
		next();

	forn(i, m)
	{
		forn(j, m)
			printf("%c", ans[i][j]);
		printf("\n");
	}

	return 0;
}