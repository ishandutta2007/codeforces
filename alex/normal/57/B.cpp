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

int const NMAX = 100010;
int n, m, k, a[NMAX], b[NMAX], c[NMAX];

int64 calc()
{
	int x;
	int64 res = 0;
	cin >> x;
	forn(i, m)
		if (x >= a[i] && x <= b[i]) res += c[i] + (x - a[i]);
	return res;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	cin >> n >> m >> k;
	forn(i, m)
		scanf("%d%d%d", &a[i], &b[i], &c[i]);
	int64 sum = 0;
	forn(i, k)
	{
		sum += calc();
	}
	cout << sum << endl;

	return 0;
}