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

int const NMAX = 1010;
int n, m, k, row[NMAX];

int main()
{
	//freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	cin >> n >> m >> k;
	forn(i, m)
		row[i] = 1000000000;
	forn(i, n)
	{
		int x, c;
		cin >> x >> c;
		row[x - 1] = min(row[x - 1], c);
	}
	int ans = 0;
	forn(i, m)
		ans += row[i];
	cout << min(k, ans) << endl;

	return 0;
}