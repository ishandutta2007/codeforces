#pragma comment(linker, "/STACK:60000000")
//#define _MY_OPT_MODE_
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>

#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <stack>
#include <list>

#include <ctime>
#include <cassert>

using namespace std;

typedef long double ldb;
typedef long long int64;
typedef pair <int, int> pii;

#define y0 wwwwwww
#define y1 qqqqqqq
#define next NEXT
#define prev PREV
#define forn(i, n) for (int i = 0; i < (int) n; i++)
#define ford(i, n) for (int i = (int) n - 1; i >= 0; i--)
#define seta(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define last(a) a[a.size() - 1]
#define mp make_pair
#define fs first
#define sc second
#define I (int)

template <class T> T sqr(T x) { return x * x; }

double const pi = 3.1415926535897932384626433832795;
int const inf = (1 << 30) - 1;
int64 const inf64 = (1LL << 62) - 1;
const string name = "c";

const int NMAX = 300100;
int n, used[NMAX];
char s[NMAX], now[NMAX];
int x, y, xx, yy, xxx, yyy, cnt[2];
vector <string> ans;

void solve()
{
	int xx = x, yy = y;
	seta(used, 0);
	char buf[3];
	int tmp = 0;
	forn(i, n)
	{
		if (now[i] == '0' && xx > 0) used[i] = 1, xx--; 
		if (now[i] == '1' && yy > 0) used[i] = 1, yy--;
		if (used[i] == 0) buf[tmp++] = now[i];
		if (tmp > 2) tmp = 2;
	}
	buf[2] = '\0';
	string res = buf;
	ans.pb(res);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	scanf("%s", s);
	n = strlen(s);
	x = (n - 2) / 2;
	y = n - 2 - x;

	seta(cnt, 0);
	forn(i, n)
		cnt[s[i] - '0']++;
	xx = cnt[0], yy = cnt[1];

	ans.clear();
	forn(i, n)
	{
		now[i] = s[i];
		if (now[i] == '?') now[i] = '1';
	}
	solve();
	forn(i, n)
	{
		now[i] = s[i];
		if (now[i] == '?') now[i] = '0';
	}
	solve();

	xxx = n / 2;
	yyy = n - xxx;
	if (xxx >= xx && yyy >= yy)
	{
		xxx -= xx, yyy -= yy;
		forn(i, n)
		{
			now[i] = s[i];
			if (now[i] == '?' && xxx > 0) now[i] = '0', xxx--;
			else if (now[i] == '?') now[i] = '1';
		}
		solve();
		forn(i, n)
		{
			now[i] = s[i];
			if (now[i] == '?' && yyy > 0) now[i] = '1', yyy--;
			else if (now[i] == '?') now[i] = '0';
		}
		solve();
	}

	sort(all(ans));
	ans.resize(unique(all(ans)) - ans.begin());
	forn(i, ans.size())
		cout << ans[i].data() << endl;

	return 0;
}