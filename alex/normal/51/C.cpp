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
//int const inf = (int) 1e9;
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

int n;
int64 x[200001], p[4];

bool may(int64 r)
{
	int64 last = (int64) -1e15;
	int cnt = 0;
	forn(i, n)
		if (last + r < x[i]) last = x[i] + r, p[cnt++] = x[i] + r;
	while (cnt < 3)
	{
		p[cnt + 1] = p[cnt];
		cnt++;
	}
	if (cnt <= 3)
		return true;
	else
		return false;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	cin >> n;
	forn(i, n)
	{
		int tmp;
		scanf("%d", &tmp);
		x[i] = (int64) tmp * 2;
	}
	sort(x, x + n);
	int64 l = 0, r = (int64) 1e10;
	while (r - l > 1)
	{
		int64 m = (l + r) / 2;
		if (may(m)) r = m;
		else l = m;
	}
	int64 ans;
	if (may(l)) ans = l;
	else
	{
		may(r);
		ans = r;
	}
	printf("%.6lf\n", (double) ans / 2);
	forn(i, 3)
		printf("%.6lf ", (double) p[i] / 2);

	return 0;
}