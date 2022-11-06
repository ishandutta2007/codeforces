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

const string name = "a";

int p[10];
set <string> S;
int n;
string s;

void rotate(string &now, int x)
{
	string tmp = now;
	if (x == 0)
	{
		tmp[0] = now[1];
		tmp[1] = now[2];
		tmp[2] = now[3];
		tmp[3] = now[0];
	}
	if (x == 1)
	{
		tmp[1] = now[4];
		tmp[5] = now[1];
		tmp[3] = now[5];
		tmp[4] = now[3];
	}
	if (x == 2)
	{
		tmp[0] = now[5];
		tmp[4] = now[0];
		tmp[2] = now[4];
		tmp[5] = now[2];
	}
	now = tmp;
}

void solve()
{
	string now = "";
	forn(i, n)
		now += s[p[i]];
	string ans = now;
	forn(i, 4)
	{
		rotate(now, 0);
		forn(j, 4)
		{
			rotate(now, 1);
			forn(f, 4)
			{
				ans = min(ans, now);
				rotate(now, 2);
			}
		}
	}
	S.insert(ans);
}

int main()
{
	//freopen((name + ".in").data(), "r", stdin);
	//freopen((name + ".out").data(), "w", stdout);

	n = 6;
	cin >> s;
	forn(i, n)
		p[i] = i;
	solve();
	while (next_permutation(p, p + n))
		solve();
	cout << S.size() << endl;

	return 0;
}