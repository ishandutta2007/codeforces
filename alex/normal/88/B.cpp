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

const int NMAX = 40;
int n, m, k, x, ans, need[256];
char s[NMAX][NMAX];
string q;

void solve(int p)
{
	if (need[q[p]] == -1)
	{
		cout << -1 << endl;
		exit(0);
	}
	ans += need[q[p]];
}

int main()
{
	//freopen((name + ".in").data(), "r", stdin);
	//freopen((name + ".out").data(), "w", stdout);

	cin >> n >> m >> x;
	forn(i, n)
		cin >> s[i];
	bool exist = 0;
	forn(i, n)
		forn(j, m)
			if (s[i][j] == 'S')
				exist = 1;

	seta(need, 255);
	forn(i, n)
		forn(j, m)
			if (s[i][j] != 'S')
			{
				need[s[i][j]] = 0;
				if (exist && need[s[i][j] + 'A' - 'a'] == -1) need[s[i][j] + 'A' - 'a'] = 1;
				forn(ii, n)
					forn(jj, m)
						if (s[ii][jj] == 'S' && x * x >= (i - ii) * (i - ii) + (j - jj) * (j - jj))
							need[s[i][j] + 'A' - 'a'] = 0;
			}

	cin >> k;
	cin >> q;

	ans = 0;
	forn(i, k)
		solve(i);
	cout << ans << endl;

	return 0;
}