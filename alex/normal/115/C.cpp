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

const int NMAX = 500010;

int n, m, now[NMAX], tmp;
char buf[NMAX];
string s[NMAX];

int calc()
{
	int cnt[2];
	cnt[0] = cnt[1] = 0;
	forn(i, tmp + 1)
		if (now[i]) cnt[i & 1]++;
	if (cnt[0] == 0 && cnt[1] == 0) return 2;
	if (cnt[0] == 0 || cnt[1] == 0) return 1;
	return 0;
}

int main()
{
	//freopen((name + ".in").data(), "r", stdin);
	//freopen((name + ".out").data(), "w", stdout);

	cin >> n >> m;
	forn(i, n)
	{
		scanf("%s", buf);
		s[i] = buf;
	}
	cerr << clock() << endl;
	int ans = 1;
	tmp = m;
	forn(i, n)
	{
		forn(j, m + 1)
			now[j] = 0;
		forn(j, m)
		{
			if (s[i][j] == '1') now[j] = 1;
			if (s[i][j] == '2') now[j] = 1;
			if (s[i][j] == '3') now[j + 1] = 1;
			if (s[i][j] == '4') now[j + 1] = 1;
		}
		ans = (ans * calc()) % 1000003;
	}
	cerr << clock() << endl;
	tmp = n;
	forn(i, m)
	{
		forn(j, n + 1)
			now[j] = 0;
		forn(j, n)
		{
			if (s[j][i] == '1') now[j] = 1;
			if (s[j][i] == '2') now[j + 1] = 1;
			if (s[j][i] == '3') now[j + 1] = 1;
			if (s[j][i] == '4') now[j] = 1;
		}
		ans = (ans * calc()) % 1000003;
	}
	cerr << clock() << endl;
	cout << ans << endl;

	return 0;
}