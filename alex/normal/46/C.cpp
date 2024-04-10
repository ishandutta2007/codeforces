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

const string task = "";

int n, ans;
char s[1010];

void solve(char x)
{
	for (int i = n; i > 0; i--)
		s[i] = s[i - 1];
	s[0] = s[n];

	int cnt = 0;
	forn(i, n)
		if (s[i] == x) cnt++;

	int now1 = 0, now2 = 0;
	forn(i, n)
	{
		char tmp = x;
		if (i >= cnt) tmp = 'H' + 'T' - x;
		if (s[i] != tmp)
		{
			if (i < cnt) now1++;
			else now2++;
		}
	}
	ans = min(ans, max(now1, now2));
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	cin >> n >> s;
	ans = n + 1;
	forn(i, n)
		solve('T');
	forn(i, n)
		solve('H');
	cout << ans << endl;

	return 0;
}