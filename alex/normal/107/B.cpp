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

int n, m, s, num[1010];

void answer(double ans)
{
	printf("%.10lf\n", ans);
	exit(0);
}

int main()
{
	//freopen((name + ".in").data(), "r", stdin);
	//freopen((name + ".out").data(), "w", stdout);

	cin >> n >> m >> s;
	s--;
	int sum = -1;
	forn(i, m)
	{
		cin >> num[i];
		sum += num[i];
	}
	num[s]--;

	if (sum < n - 1) answer(-1);
	else
	{
		double p = 1;
		int x = num[s], y = sum - num[s];
		forn(i, n - 1)
		{
			p *= (double) y / (x + y);
			y--;
		}
		answer(1 - p);
	}

	return 0;
}