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
const string name = "b";

int n, x, err;
string ans;
char now[1000100];

void solve(int x, int y)
{
	int sum = 0, yl = 0;
	while (1)
	{
		if (x == 0 && y == 1) break;
		if (x == 0 || y == 0) return;
		if (x >= y) { x -= y; if (yl > 0 && now[yl - 1] == 'T') sum++; now[yl++] = 'T'; }
		else { y -= x; if (yl > 0 && now[yl - 1] == 'B') sum++; now[yl++] = 'B'; }
	}
	if (yl != n || now[yl - 1] == 'B') return;
	now[yl] = '\0';
	if (err > sum)
		err = sum, ans = now;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n >> x;
	err = inf;
	ans = "";
	forn(i, x + 1)
	{
		solve(i, x);
		solve(x, i);
	}
	reverse(ans.begin(), ans.end());
	if (err == inf) cout << "IMPOSSIBLE" << endl;
	else cout << err << endl << ans.data() << endl;

	return 0;
}