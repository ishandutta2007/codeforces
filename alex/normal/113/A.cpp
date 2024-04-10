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

const string name = "a";

string s;
char buf[100010];

int main()
{
	//freopen((name + ".in").data(), "r", stdin);
	//freopen((name + ".out").data(), "w", stdout);

	int cnt1 = 0, cnt2 = 0, cnt3 = 0, last = -1;
	int m = 0, w = 0;
	while (scanf("%s", buf) > 0)
	{
		s = buf;
		int ok = 0;
		if (s.length() >= 4 && s.substr(s.length() - 4, 4) == "lios")
		{
			if (last > 0)
			{
				cout << "NO" << endl;
				return 0;
			}
			ok = 1;
			cnt1++, m++, last = 0;
		}
		if (s.length() >= 5 && s.substr(s.length() - 5, 5) == "liala")
		{
			if (last > 0)
			{
				cout << "NO" << endl;
				return 0;
			}
			cnt1++, w++, last = 0;
			ok = 1;
		}
		if (s.length() >= 3 && s.substr(s.length() - 3, 3) == "etr")
		{
			if (last > 1)
			{
				cout << "NO" << endl;
				return 0;
			}
			cnt2++, m++, last = 1;
			ok = 1;
		}
		if (s.length() >= 4 && s.substr(s.length() - 4, 4) == "etra")
		{
			if (last > 1)
			{
				cout << "NO" << endl;
				return 0;
			}
			cnt2++, w++, last = 1;
			ok = 1;
		}
		if (s.length() >= 6 && s.substr(s.length() - 6, 6) == "initis")
		{
			if (last > 2)
			{
				cout << "NO" << endl;
				return 0;
			}
			cnt3++, m++, last = 2;
			ok = 1;
		}
		if (s.length() >= 6 && s.substr(s.length() - 6, 6) == "inites")
		{
			if (last > 2)
			{
				cout << "NO" << endl;
				return 0;
			}
			cnt3++, w++, last = 2;
			ok = 1;
		}
		if (!ok)
		{
			cout << "NO" << endl;
			return 0;
		}
	}
	if (cnt1 + cnt2 + cnt3 != 1 && ((m && w) || cnt2 != 1))
		cout << "NO" << endl;
	else
		cout << "YES" << endl;

	return 0;
}