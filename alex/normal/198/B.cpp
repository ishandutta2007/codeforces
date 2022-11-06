#pragma comment(linker, "/STACK:60000000")
//#define _MY_OPT_MODE_
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>

#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <stack>
#include <list>

#include <ctime>
#include <cassert>

using namespace std;

typedef long double ldb;
typedef long long int64;
typedef pair <int, int> pii;
typedef pair <double, double> pdd;

#define y0 wwwwwww
#define y1 qqqqqqq
#define next NEXT
#define prev PREV
#define forn(i, n) for (int i = 0; i < (int) n; i++)
#define ford(i, n) for (int i = (int) n - 1; i >= 0; i--)
#define seta(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define last(a) a[a.size() - 1]
#define mp make_pair
#define fs first
#define sc second

template <class T> T sqr(T x) { return x * x; }

double const pi = 3.1415926535897932384626433832795;
int const inf = (int) 1e9;
int64 const inf64 = (int64) 4e18;
const string name = "b";

const int NMAX = 200100;

int n, k, may[2][NMAX], h, t;
char s[2][NMAX];
pair <pii, int> q[NMAX * 10];

void add(int x, int y, int st)
{
	if (may[x][y]) return;
	may[x][y] = 1;
	q[t++] = mp(mp(x, y), st);
}

void move(int x, int y, int st)
{
	if (st > y) return;
	if (y >= n) 
	{
		cout << "YES" << endl;
		exit(0);
	}
	if (y + 1 >= n || s[x][y + 1] == '-') add(x, y + 1, st + 1);
	if (y > 0 && s[x][y - 1] == '-') add(x, y - 1, st + 1);
	if (y + k >= n || s[x ^ 1][y + k] == '-') add(x ^ 1, y + k, st + 1);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n >> k >> s[0] >> s[1];
	seta(may, 0);
	h = 0, t = 0;
	q[t++] = mp(mp(0, 0), 0);
	while (h < t)
	{
		move(q[h].fs.fs, q[h].fs.sc, q[h].sc);
		h++;
	}
	cout << "NO" << endl;

	return 0;
}