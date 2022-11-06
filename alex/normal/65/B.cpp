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
#define fs first
#define sc second
#define x first
#define y second
#define sqr(x) ((int64) x) * (x)

const string name = "b";

int n, t[2011], ans[2011];

void try_(int ind, int &now)
{
	ans[ind] = 10000;

	int d = t[ind] % 10;
	forn(i, 10)
	{
		int tmp = t[ind] - d + i;
		if (tmp >= now) ans[ind] = min(ans[ind], tmp);
	}

	d = (t[ind] / 10) % 10;
	forn(i, 10)
	{
		int tmp = t[ind] - 10 * d + 10 * i;
		if (tmp >= now) ans[ind] = min(ans[ind], tmp);
	}

	d = (t[ind] / 100) % 10;
	forn(i, 10)
	{
		int tmp = t[ind] - 100 * d + 100 * i;
		if (tmp >= now) ans[ind] = min(ans[ind], tmp);
	}

	d = (t[ind] / 1000) % 10;
	forn(i, 10)
	if (i)
	{
		int tmp = t[ind] - 1000 * d + 1000 * i;
		if (tmp >= now) ans[ind] = min(ans[ind], tmp);
	}

	if (ans[ind] > 2011)
	{
		cout << "No solution" << endl;
		exit(0);
	}
	now = ans[ind];
}

int main()
{
	//freopen((name + ".in").data(), "r", stdin);
	//freopen((name + ".out").data(), "w", stdout);

	cin >> n;
	forn(i, n)
		cin >> t[i];

	int now = 1000;
	forn(i, n)
		try_(i, now);
//	cout << n << endl;
	forn(i, n)
		cout << ans[i] << endl;

	return 0;
}