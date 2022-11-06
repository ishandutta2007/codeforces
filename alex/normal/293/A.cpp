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

int n;
char a[2001010], b[2000100];

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n;
	scanf("%s", a);
	scanf("%s",b);
	int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
	forn(i, 2 * n)
	{
		if (a[i] == '1' && b[i] == '1') cnt1++;
		if (a[i] == '1' && b[i] == '0') cnt2++;
		if (a[i] == '0' && b[i] == '1') cnt3++;
		if (a[i] == '0' && b[i] == '0') cnt4++;
	}
	int zn1 = 0, zn2 = 0;
	if (cnt1 % 2 == 0)
	{
		zn1 = cnt1 / 2, zn2 = cnt1 / 2;
		if (cnt2 > cnt3) cout << "First" << endl;
		else if (cnt2 < cnt3 - 1) cout << "Second" << endl;
		else cout << "Draw" << endl;
		return 0;
	}
	else
	{
		zn1 = cnt1 / 2 + 1, zn2 = cnt1 / 2;
		if (cnt3 == 0)
		{
			cout << "First" << endl;
			return 0;
		}
		cnt3--, zn2++;
		if (cnt2 > cnt3) cout << "First" << endl;
		else if (cnt2 < cnt3 - 1) cout << "Second" << endl;
		else cout << "Draw" << endl;
		return 0;
	}

	return 0;
}