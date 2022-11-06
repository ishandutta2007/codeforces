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

const int NMAX = 100010;
int n, ans[NMAX], step[NMAX], used[1000];

void solve(int n)
{
	step[n] = n + 1;
	seta(used, 0);
	for (int i = 2; i * (i + 1) <= 2 * n; ++i)
		if ((n - i * (i + 1) / 2) % i == 0)
		{
			int now = 0, zn = 1 + (n - i * (i + 1) / 2) / i;
			forn(j, i)
				now ^= ans[zn + j];
			if (now < 1000) used[now] = 1;
			if (now == 0)
				step[n] = min(step[n], i);
		}
	forn(i, 1000)
		if (!used[i])
		{
			ans[n] = i;
			break;
		}
}

int main()
{
	//freopen((name + ".in").data(), "r", stdin);
	//freopen((name + ".out").data(), "w", stdout);

	cin >> n;
	ans[0] = ans[1] = ans[2];
	step[0] = 1, step[1] = 2, step[2] = 3;
	for (int i = 3; i <= n; ++i)
		solve(i);
	if (step[n] == n + 1) cout << -1 << endl;
	else cout << step[n] << endl;

	return 0;
}