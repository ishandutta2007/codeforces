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

const string name = "b";

int n;
double k, a[10010];

bool may(double lvl)
{
	double now = 0;
	forn(i, n)
	{
		if (a[i] > lvl)
			now += (a[i] - lvl) * k;
		else
			now -= lvl - a[i];
	}
	if (now > 0) return true;
	else return false;
}

int main()
{
	//freopen((name + ".in").data(), "r", stdin);
	//freopen((name + ".out").data(), "w", stdout);

	cin >> n >> k;
	k = (1 - k / 100);
	forn(i, n)
		cin >> a[i];
	may(2);

	double l = 0, r = 1000;
	while (fabs(r - l) > 1e-7)
	{
		double m = (l + r) / 2;
		if (may(m)) l = m;
		else r = m;
	}

	printf("%.7lf\n", (l + r) / 2);

	return 0;
}