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
#define seta(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define pii pair < int, int >
#define all(a) (a).begin(), (a).end()
#define mp make_pair
#define fs first
#define sc second
#define sqr(x) ((int64) x) * (x)

const string name = "b";

int n, k[3], t[3], a[100010];
multiset <int64> s[3];

int main()
{
	//freopen((name + ".in").data(), "r", stdin);
	//freopen((name + ".out").data(), "w", stdout);

	forn(i, 3)
		cin >> k[i];
	forn(i, 3)
		cin >> t[i];

	cin >> n;
	forn(i, 3)
		k[i] = min(k[i], n);
	forn(i, n)
		scanf("%d", &a[i]);
	sort(a, a + n);

	forn(i, 3)
	{
		s[i].clear();
		forn(j, k[i])
			s[i].insert(0);
	}
	int64 ans = 0;
	forn(i, n)
	{
		int64 now = a[i];
		forn(j, 3)
		{
			int64 tmp = *s[j].begin();
			s[j].erase(s[j].begin());
			now = max(now, tmp) + t[j];
			s[j].insert(now);
		}
		ans = max(ans, now - a[i]);
	}
	cout << ans << endl;

	return 0;
}