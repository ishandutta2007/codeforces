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

const int NMAX = 20000;

int l, r, ans, s, num;
int prime[NMAX], block[NMAX];

int main()
{
	//freopen((name + ".in").data(), "r", stdin);
	//freopen((name + ".out").data(), "w", stdout);

	cin >> l >> r;
	ans = 0;
	s = (int) sqrt(r + 0.) + 1;
	int j;

	num = 0;
	seta(prime, 1);
	prime[0] = prime[1] = 0;
	forn(i, s + 1)
		if (prime[i])
		{
			if (l <= i && i <= r && (i == 2 || (i & 3) == 1))
				ans++;
			j = 2 * i;
			prime[num++] = i;
			while (j < s + 1)
				prime[j] = 0, j += i;
		}

	forn(k, r / s + 1)
		if (k)
		{
			int st = k * s, fin = (k + 1) * s;
			seta(block, 1);
			forn(i, num)
			{
				j = ((st - 1) / prime[i] + 1) * prime[i];
				while (j < fin)
					block[j - st] = 0, j += prime[i];
			}
			for (int i = st; i < fin; ++i)
				if (block[i - st] && l <= i && i <= r && (i == 2 || (i & 3) == 1))
					ans++;
		}
	cout << ans << endl;
	cerr << clock() << endl;

	return 0;
}