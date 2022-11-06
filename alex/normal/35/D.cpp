#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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
#define pii pair < int, int >
#define mp make_pair
#define fs first
#define sc second

int n, a[1000], x;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> n >> x;
	forn(i, n)
	{
		cin >> a[i];
		a[i] *= (n - i);
	}
	sort(a, a + n);
	int ans = 0;
	forn(i, n)
		if (x >= a[i])
		{
			x-=a[i];
			ans++;
		}
	cout << ans << endl;

	return 0;
}