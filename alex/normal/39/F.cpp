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

int const NMAX = 1010;
int n, m, k, p[NMAX], d[NMAX];
vector <int> ans;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	cin >> n >> m >> k;
	forn(i, m)
		cin >> d[i];
	forn(i, k)
		cin >> p[i];

	int best = inf;
	ans.clear();
	forn(i, m)
	{
		int now = 0;
		forn(j, k)
			if ((p[j]) % d[i] == 0) now++;
		if (now < best)
		{
			ans.clear();
			best = now;
		}
		if (best == now) ans.pb(i + 1);
	}

	cout << ans.size() << endl;
	forn(i, ans.size())
		cout << ans[i] << " ";

	return 0;
}