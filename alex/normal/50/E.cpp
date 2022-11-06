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
#include <algorithm>

using namespace std;

typedef long double ldb;
typedef long long int64;

#define y1 qqqqqqq
#define forn(i, n) for (int i = 0; i < (int) n; i++)
#define seta(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define pii pair < int, int >
#define all(a) (a).begin(), (a).end()
#define mp make_pair
#define fs first
#define sc second

int const NMAX = 100010;
double const eps = 1e-5;
double const g = 9.8;
double const pi = 3.141592653589;

int const shift = 20000001;

bool used[2 * shift];
int n, m;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	cin >> n >> m;
	seta(used, 0);
	long long ans = 0;
	for (int i = 1; i <= n; i++)
	{
		long long b2 = (long long) 4 * i * i, now = 2 * i - 1, num = b2 - 4 * m;
		ans += 2 * max(0LL, (b2 - max(1LL, num)) >> 2);

		while (now > 0 && now * now >= num)
		{
			if (((b2 - now * now) & 3) == 0)
			{
				ans -= 2;
				used[shift - 2 * i - now] = true;
				used[shift - 2 * i + now] = true;
			}
			now--;
		}

		if ((b2 & 3) == 0 && num <= 0)
		{
			used[shift - 2 * i] = true;
		}
	}

	forn(i, 2 * shift)
		if (used[i]) ans++;
	cout << ans << endl;

	cerr << clock() << endl;

	return 0;
}