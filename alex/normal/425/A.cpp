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
const string name = "a";

int n, k, a[10010];

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n >> k;
	forn(i, n)
		cin >> a[i];

	int ans = a[0];
	forn(r, n)
		forn(l, r + 1) {
			vector<int> a1, a2;
			for (int i = l; i <= r; ++i)
				a1.pb(a[i]);
			for (int i = 0; i < l; ++i)
				a2.pb(a[i]);
			for (int i = r + 1; i < n; ++i)
				a2.pb(a[i]);
			sort(all(a1));
			sort(all(a2));
			reverse(all(a2));
			int kk = k;
			kk = min(kk, (int) a1.size());
			kk = min(kk, (int) a2.size());
			forn(i, kk)
				if (a1[i] < a2[i]) swap(a1[i], a2[i]);
			int sum = 0;
			forn(i, a1.size())
				sum += a1[i];
			ans = max(ans, sum);
		}
	cout << ans << endl;

	return 0;
}