#pragma comment(linker, "/STACK:60000000")
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <sstream>
#include <iomanip>
#include <complex>
#include <queue>
#include <functional>

using namespace std;

#define next NEXT
#define prev PREV
#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define seta(a,x) memset (a, x, sizeof (a))
#define I (int)
#define y1 botva

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;

template <class T> T sqr (T x) {return x * x;}

int const NMAX = 100010;

int n, used[NMAX];

int main ()
{
  //  freopen ("input.txt", "r", stdin);
  //  freopen ("output.txt", "w", stdout);

	cin >> n;
	seta(used, 255);
	forn(i, n)
	{
		int x, y, ans = 0;
		scanf("%d%d", &x, &y);
		for (int j = 1; j * j <= x; ++j)
			if (x % j == 0)
			{
				if (-1 == used[j] ||used[j] < i - y) ans++;
				if (j * j != x && (-1 == used[x / j] || used[x / j] < i - y)) ans++;
			}
		for (int j = 1; j * j <= x; ++j)
			if (x % j == 0)
				used[j] = i, used[x / j] = i;
		printf("%d\n", ans);
	}

	return 0;
}