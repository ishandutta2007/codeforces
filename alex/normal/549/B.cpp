#pragma comment(linker, "/STACK:600000000")
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

const int NMAX = 210;

int n, now[NMAX], ept[NMAX];
char s[101010];
vector<int> ans;
int g[NMAX][NMAX];

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n;
	forn(i, n) {
		scanf("%s", s);
		forn(j, n)
			if (s[j] == '1')
				g[i][j] = 1;
			else
				g[i][j] = 0;
	}
	forn(i, n)
		cin >> ept[i];

	ans.clear();
	seta(now, 0);
	while (1) {
		int ok = 1;

		forn(i, n)
			if (now[i] == ept[i]) {
				forn(j, n)
					if (g[i][j])
						now[j] ++;
				ok = 0;
				ans.pb(i);
			}

		if (ok)
			break;
	}

	cout << ans.size() << endl;
	sort(all(ans));
	forn(i, ans.size())
		cout << ans[i] + 1 << " " ;

	return 0;
}