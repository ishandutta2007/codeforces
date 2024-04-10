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

const string name = "c";

int64 ax, ay, bx, by, cx, cy;

void rotate(int64 &x, int64 &y)
{
	int64 xx = -y, yy = x;
	x = xx, y = yy;
}

void answer()
{
	cout << "YES" << endl;
	exit(0);
}

void solve(int64 x, int64 y)
{
	if (cx == 0 && cy == 0)
	{
		if (x == 0 && y == 0) answer();
		return;
	}

	if (cx == 0 || cy == 0)
	{
		int64 zn = cx + cy;
		if (zn < 0) zn = -zn;
		if (x % zn == 0 && y % zn == 0)
			answer();
		return;
	}

	if ((x * cy - y * cx) % (cx * cx + cy * cy) == 0
		&& (y * cy + x * cx) % (cx * cx + cy * cy) == 0)
		answer();
}

int main()
{
	//freopen((name + ".in").data(), "r", stdin);
	//freopen((name + ".out").data(), "w", stdout);

	cin >> ax >> ay;
	cin >> bx >> by;
	cin >> cx >> cy;

	forn(i, 4)
	{
		forn(j, 4)
		{
			solve(bx - ax, by - ay);
			rotate(bx, by);
		}
		rotate(ax, ay);
	}
	cout << "NO" << endl;

	return 0;
}