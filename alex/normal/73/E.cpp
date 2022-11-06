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

const string name = "e";

const int NMAX = 100010;
int x, n, a[NMAX];
int used[10000010];

int main()
{
	//freopen((name + ".in").data(), "r", stdin);
	//freopen((name + ".out").data(), "w", stdout);

	cin >> n >> x;
	if (x == 2)
	{
		cout << 0 << endl;
		return 0;
	}
	forn(i, n)
		scanf("%d", &a[i]);
	sort(a,  a + n);
	if (a[0] == 1)
	{
		cout << 1 << endl;
		return 0;
	}

	if (x > 10000000)
	{
		cout << -1 << endl;
		return 0;
	}

	seta(used, 1);
	int cnt = 0;
	used[0] = used[1] = 0;
	forn(i, x)
		if (used[i])
		{
			cnt++;
			int j = 2 * i;
			while (j <= x)
			{
				used[j] = 0;
				j += i;
			}
		}

	int ans = cnt;
	forn(i, n)
		if (a[i] < x && used[a[i]])
		{
			cnt--;
			used[a[i]] = 0;
		}
	if (cnt == 0) cout << ans << endl;
	else cout << -1 << endl;

	return 0;
}