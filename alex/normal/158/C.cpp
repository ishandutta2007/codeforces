#pragma comment(linker, "/STACK:60000000")
//#define _MY_OPT_MODE_
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>

#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <stack>
#include <list>

#include <ctime>
#include <cassert>

using namespace std;

typedef long double ldb;
typedef long long int64;
typedef pair <int, int> pii;

#define y0 wwwwwww
#define y1 qqqqqqq
#define next NEXT
#define prev PREV
#define forn(i, n) for (int i = 0; i < (int) n; i++)
#define ford(i, n) for (int i = (int) n - 1; i >= 0; i--)
#define seta(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define last(a) a[a.size() - 1];
#define mp make_pair
#define fs first
#define sc second

template <class T> T sqr(T x) { return x * x; }

double const pi = 3.1415926535897932384626433832795;
int const inf = (int) 1e9;
int64 const inf64 = (int64) 4e18;
const string name = "c";

int n, num;
vector <string> now;
char buf[300];

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n;
	gets(buf);
	forn(i, n)
	{
		string s;
		gets(buf);
		s = buf;

		if (s == "pwd")
		{
			cout << "/";
			forn(j, now.size())
				cout << now[j] << "/";
			cout << endl;
		}
		else
		{
			int yl;
			if (s[3] == '/')
			{
				yl = 4;
				now.clear();
			}
			else yl = 3;

			while (yl < (int) s.length())
			{
				int tmp = yl;
				while (tmp < (int) s.length() && s[tmp] != '/')
					tmp++;
				string zn = s.substr(yl, tmp - yl);
				yl = tmp + 1;
				if (zn == "..") now.pop_back();
				else now.push_back(zn);
			}
		}
	}

	return 0;
}