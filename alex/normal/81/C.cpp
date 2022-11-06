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

const string name = "c";

const int NMAX = 200010;
int n, a, b;
int zn[NMAX], acnt[10], bcnt[10];
pii q[NMAX];

int main()
{
	//freopen((name + ".in").data(), "r", stdin);
	//freopen((name + ".out").data(), "w", stdout);

	cin >> n >> a >> b;
	if (a == b)
	{
		forn(i, a)
			printf("1 ");
		forn(i, a)
			printf("2 ");
		return 0;
	}
	forn(i, n)
	{
		int x;
		scanf("%d", &x);
		q[i] = mp(x, i);
		zn[i] = x;
	}

	sort(q, q + n);
	seta(acnt, 0);
	forn(i, a)
		if (a < b) acnt[q[n - i - 1].fs]++;
		else acnt[q[i].fs]++;
	seta(bcnt, 0);
	forn(i, b)
		if (a < b) bcnt[q[i].fs]++;
		else bcnt[q[n - i - 1].fs]++;

	forn(i, n)
	{
		if (acnt[zn[i]])
		{
			printf("1 ");
			acnt[zn[i]]--;
		}
		else if (bcnt[zn[i]])
		{
			printf("2 ");
			bcnt[zn[i]]--;
		}
	}

	return 0;
}