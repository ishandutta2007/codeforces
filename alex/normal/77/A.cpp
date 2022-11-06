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

const string names[7] = {"Anka", "Chapay", "Cleo", "Troll", "Dracul", "Snowy" ,"Hexadecimal"};

const int NMAX = 10;
int best, ans, n, c[3], gr[NMAX], num[NMAX];
string a, b;
map < pair <string, string>, int > M;

void rec(int now)
{
	if (now == 7)
	{
		if (num[0] == 0 || num[1] == 0 || num[2] == 0) return;
		int _min = 1e9, _max = -1e9, tmp = 0;
		forn(i, 3)
		{
			_min = min(_min, c[i] / num[i]);
			_max = max(_max, c[i] / num[i]);
		}
		forn(i, 7)
			forn(j, 7)
				if (gr[i] == gr[j] && M.count(mp(names[i], names[j])))
					tmp++;
		if (best > _max - _min || (best == _max - _min && tmp > ans))
		{
			best = _max - _min;
			ans = tmp;
		}
		return;
	}
	forn(i, 3)
	{
		num[i]++;
		gr[now] = i;
		rec(now + 1);
		num[i]--;
	}
}

int main()
{
	//freopen((name + ".in").data(), "r", stdin);
	//freopen((name + ".out").data(), "w", stdout);

	M.clear();
	cin >> n;
	forn(i, n)
	{
		string tmp;
		cin >> a >> tmp >> b;
		M[mp(a, b)] = 1;
	}
	cin >> c[0] >> c[1] >> c[2];

	best = 1e9, ans = 0;
	rec(0);
	cout << best << " " << ans << endl;

	return 0;
}