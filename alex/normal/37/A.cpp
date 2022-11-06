#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <ctime>
#include <cmath>
#include <algorithm>

using namespace std;

double const pi = 3.1415926535897932384626433832795;

#define y1 qqqqqqq
#define forn(i, n) for (int i = 0; i < (int) n; i++)
#define seta(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define pii pair < double, double >
#define mp make_pair
#define fs first
#define sc second

int n, a[2000], cnt[2000];

int main()
{
	//freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	cin >> n;
	seta(cnt, 0);
	int ans1 = 0, ans2 = 0;
	forn(i, n)
	{
		int x;
		cin >> x;
		cnt[x]++;
	}
	forn(i, 1001)
	{
		if (cnt[i]) ans2 ++;
		ans1 = max(ans1, cnt[i]);
	}
	cout << ans1 << " " << ans2 << endl;

	return 0;
}