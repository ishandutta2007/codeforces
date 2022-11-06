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
#include <deque>

#include <ctime>
#include <cassert>

using namespace std;

typedef long double ldb;
typedef long long int64;
typedef pair <int, int> pii;
typedef pair <double, double> pdd;

#define left L
#define right R
#define up U
#define down D
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
#define x first
#define y second

template <class T> T sqr(T x) { return x * x; }

double const pi = 3.1415926535897932384626433832795;
int const inf = (int) 1e9;
int64 const inf64 = (int64) 4e18;
const string name = "a";

pii up, left, down, right;
int n;

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n;
	up = left = right = down = mp(0, 0);
	forn(i, n)
	{
		char buf[6];
		scanf("%s", buf);
		string s = buf;
		if (s.length() == 4)
			up.y++, down.y--, left.x--, right.x++;
		else
		{
			if (s == "UR") up.y++, left.y++, down.x++, right.x++;
			if (s == "UL") up.y++, left.x--, down.x--, right.y++;
			if (s == "DL") up.x--, left.x--, down.y--, right.y--;
			if (s == "DR") up.x++, left.y--, down.y--, right.x++;
		}
	}
	//cerr << up.x << " " << up.y << endl;
	//cerr << left.x << " " << left.y << endl;
	int64 a = abs(up.x - left.x) + 1;
	int64 b = abs(up.x - right.x) + 1;
	cout << a * b  << endl;

	return 0;
}