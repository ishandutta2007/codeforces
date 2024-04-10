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
#define pii pair < int, int >
#define mp make_pair
#define fs first
#define sc second

int const NMAX = 1010;
int n, h, r;
int d[NMAX], p[NMAX];
vector <pii> ans;
bool used[NMAX];

int main()
{
	//freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	cin >> n >> h >> r;
	forn(i, n)
		cin >> p[i] >> d[i];

	ans.clear();
	int cnt = 0;
	seta(used, 0);
	int now = h;
	while (cnt <= 100000)
	{
		forn(i, n)
			if (used[i]) now -= d[i];

		now += r;
		now = min(now, h);
		if (now <= 0) break;

		int num = -1;
		forn(i, n)
			if (!used[i] && h * p[i] >= now * 100 && (num == -1 || d[num] < d[i])) num = i;
		
		if (num >= 0)
		{
			used[num] = true;
			ans.pb(mp(cnt, num + 1));
		}
		cnt++;
	}

	if (cnt > 100000) cout << "NO" << endl;
	else
	{
		cout << "YES" << endl;
		cout << cnt << " " << ans.size() << endl;
		forn(i, ans.size())
			cout << ans[i].fs << " " << ans[i].sc << endl;
	}

	return 0;
}