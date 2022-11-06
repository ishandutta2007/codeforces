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

const string name = "a";

const int NMAX = 1010;
int n, ans[NMAX];
char s[NMAX];

bool may(int sum, int num)
{
	if (num > 0 && s[num - 1] == 'R' && ans[num - 1] >= sum) return false;
	if (num < n - 1 && s[num] == 'L' && ans[num + 1] >= sum) return false;
	return true;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n >> s;
	forn(i, n)
		ans[i] = n + 1;
	for (int i = 1; i <= n; ++i)
	{
		int j = 0;
		while (j < n)
		{
			int f = j;
			while (j < n - 1 && s[j] == '=') j++;
			int ok = 1;
			for (int now = f; now <= j; ++now)
				if (!may(i, now)) ok = 0;
			if (ok)
				for (int now = f; now <= j; ++now)
					ans[now] = min(ans[now], i);
			j++;
		}
	}
	forn(i, n)
		cout << ans[i] << " ";

	return 0;
}