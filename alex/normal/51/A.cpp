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

int n, a[1010][5];

bool eq(int x, int y)
{
	forn(i, 4)
	{
		bool res = true;
		forn(j, 4)
			if (a[x][j] != a[y][j]) res = false;
		if (res) return true;
		int tmp = a[x][0];
		forn(j, 3)
			a[x][j] = a[x][j + 1];
		a[x][3] = tmp;
	}
	return false;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n;
	forn(i, n)
	{
		char s[10];
		if (i) scanf("%s", s);
		scanf("%s", s);
		a[i][0] = s[0];
		a[i][1] = s[1];
		scanf("%s", s);
		a[i][3] = s[0];
		a[i][2] = s[1];
	}

	int ans = 0;
	forn(i, n)
	{
		int cnt = 1;
		forn(j, i)
			if (eq(i, j)) cnt = 0;
		ans += cnt;
	}
	cout << ans << endl;

	return 0;
}