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
const string name = "c";

long long l1, r1, l2, r2;
vector <long long> v1, v2;

long long check(long long m1, long long m2, long long zn)
{
	return min(zn, min(m1 - l1, m2 - l2)) + min(zn, min(r1 - m1, r2 - m2)) + 1;
}

long long calc(long long l, long long r, long long zn, vector <long long> &res)
{
	res.clear();
	zn = 1LL << zn;
	long long num = ((l - zn / 2) + zn - 1) / zn * zn + zn / 2;
	if (num <= r) res.pb(num);
	if (num + zn <= r) res.pb(num + zn);
	return res.size();
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> l1 >> r1 >> l2 >> r2;
	long long ans = 0, cnt1 = 0, cnt2 = 0;
	ford(i, 32)
		if (i > 0)
		{
			if (calc(l1, r1, i, v1) > 0 && calc(l2, r2, i, v2) > 0)
			{
				forn(ii, v1.size())
					forn(jj, v2.size())
						ans = max(check(v1[ii], v2[jj], (1LL << i) / 2 - 1), ans);
			}
			cnt1 += calc(l1, r1, i, v1);
			cnt2 += calc(l2, r2, i, v2);
			if (calc(l1, r1, i, v1) >= 2 && cnt2 == 0)
				ans = max(ans, r2 - l2 + 1);
			if (calc(l2, r2, i, v2) >= 2 && cnt1 == 0)
				ans = max(ans, r1 - l1 + 1);
		}
	cout << ans << endl;

	return 0;
}