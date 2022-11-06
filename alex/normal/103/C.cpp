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

int64 n, k;
int q;

char solve(int64 n, int64 k, int64 p)
{
	int64 now = 0;
	if (p & 1) now += n / 2;
	now += p / 2 + 1;
	if (now <= n - k) return '.';
	else return 'X';
}

int main()
{
	//freopen((name + ".in").data(), "r", stdin);
	//freopen((name + ".out").data(), "w", stdout);

	cin >> n >> k >> q;
	forn(i, q)
	{
		int64 x;
		cin >> x;
		x--;

		if (n & 1)
		{
			if (k == 0)
				cout << '.';
			else
				if (x == n - 1)
					cout << 'X';
				else
					cout << solve(n - 1, k - 1, x);
		}
		else cout << solve(n, k, x);
	}
	cout << endl;

	return 0;
}