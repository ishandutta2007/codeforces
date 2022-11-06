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
int n, ans;
int s[NMAX], s1[NMAX], s2[NMAX], a[NMAX];

int main()
{
	//freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	cin >> n;
	forn(i, n)
		scanf("%d", &a[i]);
	if (n == 1)
	{
		cout << max(a[0], -a[0]);
		return 0;
	}

	s[0] = a[0];
	forn(i, n)
		if (i) s[i] = s[i - 1] + a[i];
	s1[0] = max(s[0], -s[0]);
	forn(i, n)
		if (i) s1[i] = max(s1[i - 1] + a[i], max(s[i], -s[i]));

	s[n] = 0;
	for (int i = n - 1; i >= 0; i--)
		s[i] = s[i + 1] + a[i];
	s2[n] = 0;
	for (int i = n - 1; i >= 0; i--)
		s2[i] = max(s2[i + 1] + a[i], max(s[i], -s[i]));

	ans = -2000000000;
	forn(i, n - 1)
		ans = max(ans, s1[i] + s2[i + 1]);
	cout << ans << endl;

	return 0;
}