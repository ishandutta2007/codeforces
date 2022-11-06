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
const string name = "a";

const int NMAX = 200010;

int n, k[2], answer;
int zn[2][NMAX];
vector <pii> ans;

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n;
	forn(i, n)
	{
		int a, x, y, m;
		scanf("%d%d%d%d%d", &k[i], &a, &x, &y, &m);
		zn[i][0] = a;
		for (int j = 1; j < k[i]; ++j)
			zn[i][j] = ((int64) zn[i][j - 1] * x + y + m) % m;
	}

	answer = 0;
	ans.clear();
	int l = 0, r = 0;
	while (l < k[0] || r < k[1])
	{
		int lst = l++;
		while (l < k[0] && zn[0][l] >= zn[0][l - 1])
			l++;
		if (l > k[0]) l--;
		int rst = r++;
		while (r < k[1] && zn[1][r] >= zn[1][r - 1])
			r++;
		if (r > k[1]) r--;
		while (l > lst || r > rst)
			if (l == lst || (r > rst && zn[0][lst] > zn[1][rst]))
				ans.pb(mp(1, zn[1][rst++]));
			else 
				ans.pb(mp(0, zn[0][lst++]));

		if (l < k[0] || r < k[1]) answer++;
	}
	cout << answer << endl;
	if (ans.size() > 200000) return 0;
	forn(i, ans.size())
		printf("%d %d\n", ans[i].sc, ans[i].fs + 1);

	return 0;
}