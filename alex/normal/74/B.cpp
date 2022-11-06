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

const int NMAX = 300;
char s[NMAX];
int ans[NMAX][NMAX];
int n, x, y, m, zn;

void update(int x, int y)
{
	if (y >= 0 && y < n)
		ans[x][y] = 1;
}

int main()
{
	//freopen((name + ".in").data(), "r", stdin);
	//freopen((name + ".out").data(), "w", stdout);

	cin >> n >> y >> x;
	if (x == y)
	{
		cout << 0 << endl;
		return 0;
	}

	x--, y--;
	gets(s);
	gets(s);
	if (s[3] == 'h') zn = -1;
	else if (s[3] == 't') zn = 1;
	else return 0;
	cin >> s;
	m = strlen(s);

	seta(ans, 0);
	ans[0][y] = 1;
	forn(i, m)
	{
		forn(j, n)
			if (ans[i][j])
			{
				if (j == x)
				{
					ans[i][j] = false;
					continue;
				}
				if (s[i] == '0')
				{
					if (j - 1 != x) update(i + 1, j - 1);
					if (j != x) update(i + 1, j);
					if (j + 1 != x) update(i + 1, j + 1);
				}
				else
					forn(f, n)
						update(i + 1, f);
			}
		x += zn;
		if (x < 0)
		{
			x = 1;
			zn = 1;
		}
		if (x >= n)
		{
			x = n - 2;
			zn = -1;
		}
	}

	int ok = 0;
	forn(i, n)
		if (ans[m][i])
		{
			cout << "Stowaway" << endl;
			return 0;
		}
	forn(i, m)
		forn(j, n)
			if (ans[i][j])
				ok = i;
	cout << "Controller " << ok + 1 << endl;

	return 0;
}