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

const string name = "a";

int64 x, y, z, k, xx, yy, zz;

int main()
{
	//freopen((name + ".in").data(), "r", stdin);
	//freopen((name + ".out").data(), "w", stdout);

	cin >> x >> y >> z >> k;
	if (x > y) swap(x, y);
	if (x > z) swap(x, z);
	if (y > z) swap(y, z);
	xx = min(x - 1, k / 3);
	k -= xx;
	yy = min(y - 1, k / 2);
	k -= yy;
	zz = min(z - 1, k);
	cout << (xx + 1) * (yy + 1) * (zz + 1) << endl;

	return 0;
}