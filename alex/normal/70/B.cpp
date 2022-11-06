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

int n, m;
char s[100000];

int main()
{
	//freopen((name + ".in").data(), "r", stdin);
	//freopen((name + ".out").data(), "w", stdout);

	cin >> n;
	gets(s);
	gets(s);
	m = strlen(s);
	int first = 0, now = 0, ans = 0, blank = 0;
	while (first < m && s[first] == ' ')
		first++;
	blank = first;
	forn(i, m)
		if (s[i] == '.' || s[i] == '!' || s[i] == '?')
		{
			if (i - first + 1 > n)
			{
				cout << "Impossible" << endl;
				return 0;
			}

			if (now + i - blank + 1 > n)
			{
				ans++, now = i - first + 1;
			}
			else now += i - blank + 1;

			first = i + 1;
			blank = first;
			while (first < m && s[first] == ' ')
				first++;
		}
	if (now > 0) ans++;
	cout << ans << endl;

	return 0;
}