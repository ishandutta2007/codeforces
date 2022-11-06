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

int const NMAX = 1001;
int n, k;
int b[NMAX];
int used[NMAX];

int main()
{
	//freopen((name + ".in").data(), "r", stdin);
	//freopen((name + ".out").data(), "w", stdout);

	cin >> n >> k;
	forn(i, n)
	{
		scanf("%d", &b[i]);
	}

	seta(used, 0);
	forn(i, n)
	{
		int now = -1;
		forn(j, n)
			if (!used[j] && b[j] == 0)
			{
				now = j;
				break;
			}
		printf("%d ", now + 1);
		used[now] = true;
		forn(j, now - k + 1)
			if (!used[j]) b[j]--;
	}

	return 0;
}