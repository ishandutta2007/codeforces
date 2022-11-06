#pragma comment(linker, "/STACK:600000000")
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
typedef pair <double, double> pdd;

#define y0 wwwwwww
#define y1 qqqqqqq
#define next NEXT
#define prev PREV
#define forn(i, n) for (int i = 0; i < (int) n; i++)
#define ford(i, n) for (int i = (int) n - 1; i >= 0; i--)
#define seta(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define last(a) a[a.size() - 1]
#define mp make_pair
#define fs first
#define sc second

template <class T> T sqr(T x) { return x * x; }

double const pi = 3.1415926535897932384626433832795;
int const inf = (int) 1e9;
int64 const inf64 = (int64) 4e18;
const string name = "a";

const int NMAX = 101010;

string ip[NMAX], ept[NMAX];
int n, k;

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n >> k;
	char c = ' ';
	forn(i, n)
	{
		ip[i] = "";
		while (c <= ' ') scanf("%c", &c);
		forn(j, 4)
		{
			int now = 0;
			while (c > ' ' && c != '.')
			{
				now = now * 10 + c - '0';
				if (scanf("%c", &c) <= 0) break;
			}
			scanf("%c", &c);
			string tmp = "";
			forn(j, 8)
			{
				tmp = (char) ('0' + (now & 1)) + tmp;
				now >>= 1;
			}
			ip[i] += tmp;
		}
	}

	forn(i, 33)
	{
		if (i == 0 || i == 32) continue;
		forn(j, n)
			ept[j] = ip[j].substr(0, i);
		sort(ept, ept + n);
		int now = unique(ept, ept + n) - ept;
		if (now == k) 
		{
			forn(j, 4)
			{
				int ans = 0;
				forn(f, 8)
					if (i > 0) ans += (1 << (7 - f)), i--;
				cout << ans;
				if (j < 3) cout << '.';
				else cout << endl;
			}
			return 0;
		}
	}
	cout << -1 << endl;

	return 0;
}