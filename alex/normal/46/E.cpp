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

const string task = "";

int const NMAX = 1501;
int n, m, a[NMAX][NMAX], sum[NMAX];
long long d[NMAX][NMAX];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	cin >> n >> m;
	forn(i, n)
		forn(j, m)
			scanf("%d", &a[i][j]);

	{
		int sum = 0;
		forn(i, m)
		{
			sum += a[0][i];
			d[0][i] = sum;
		}
	}
	forn(i, n)
		if (i)
		{
			sum[0] = a[i][0];
			forn(j, m)
				if (j) sum[j] = sum[j - 1] + a[i][j];
			long long now = -(1LL << 40);
			if (i & 1)
				for (int j = m - 1; j >= 0; j--)
				{
					d[i][j] = now + sum[j];
					now = max(now, d[i - 1][j]);
				}
			else
				forn(j, m)
				{
					d[i][j] = now + sum[j];
					now = max(now, d[i - 1][j]);
				}
		}

	long long ans = -(1LL << 40);
	forn(i, m)
		ans = max(ans, d[n - 1][i]);
	cout << ans << endl;

	return 0;
}