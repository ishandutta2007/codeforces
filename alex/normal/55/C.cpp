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
int const inf = (int) 1e9;

#define y1 qqqqqqq
#define forn(i, n) for (int i = 0; i < (int) n; i++)
#define seta(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define pii pair < int, int >
#define all(a) (a).begin(), (a).end()
#define mp make_pair
#define fs first
#define sc second

int n, m, k;
int const NMAX = 101;
bool ans[NMAX][NMAX][NMAX];

bool solve()
{
	int x, y;
	cin >> x >> y;
	x--, y--;
	int d = min(min(x, n - x - 1), min(y, m - y - 1));
	if (d <= 4) return true;
	else return false;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	cin >> n >> m >> k;
	bool win = false;
	forn(i, k)
		if (solve()) win = true;
	if (win) cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}