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

using namespace std;

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

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;
const string task = "e";

template <class T> T sqr (T x) {return x * x;}

int const NMAX = 1010;
int n, m, k, p, a[NMAX][NMAX];

int main ()
{
//	freopen ((task + ".in").data(), "r", stdin);
//	freopen ((task + ".out").data(), "w", stdout);

	cin >> n >> m >> k;
	if (n % 2 != m % 2)
	{
		cout << 0 << endl;
		return 0;
	}

	seta(a, 0);
	forn(i, k)
	{
		int x, y, c;
		scanf("%d%d%d", &x, &y, &c);
		x--, y--;
		a[x][y] = c;
	}
	cin >> p;

	int cnt = 0;
	forn(i, n)
	{
		int now = 1;
		forn(j, m)
			now *= a[i][j];
		if (now == 1)
		{
			cout << 0 << endl;
			return 0;
		}
		if (now == -1) cnt++;
	}

	forn(i, m)
	{
		int now = 1;
		forn(j, n)
			now *= a[j][i];
		if (now == 1)
		{
			cout << 0 << endl;
			return 0;
		}
		if (now == -1) cnt++;
	}

	int ans = 1;
	forn(i, n * m - n - m - k + 1 + cnt)
	{
		ans += ans;
		if (ans >= p) ans -= p;
	}
	cout << ans << endl;

	return 0;
}