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
#define pii pair < int64, int64 >
#define all(a) (a).begin(), (a).end()
#define mp make_pair
#define fs first
#define sc second
#define sqr(x) ((int64) x) * (x)

const string name = "a";

int64 x, y;
pii q[2000010];

int main()
{
//	freopen((name + ".in").data(), "r", stdin);
//	freopen((name + ".out").data(), "w", stdout);

	cin >> x >> y;
	forn(i, y)
		q[i] = mp((i + 1) * x, -x);
	forn(i, x)
		q[i + y] = mp((i + 1) * y, -y);
	sort(q, q + x + y);

	int64 now = 0, cntx = 0, cnty = 0;
	forn(i, x + y)
	{
		if (q[i].sc == -x) cntx += q[i].fs - now;
		else cnty += q[i].fs - now;
		now = q[i].fs;
	}
	if (cntx < cnty) cout << "Masha" << endl;
	if (cntx > cnty) cout << "Dasha" << endl;
	if (cntx == cnty) cout << "Equal" << endl;

	return 0;
}