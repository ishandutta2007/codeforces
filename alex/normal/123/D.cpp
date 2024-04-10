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
const string name = "d";

const int NMAX = 100010;
const int64 D = 239017;

int n, suf[NMAX];
int64 ans, h[NMAX], st[NMAX];
char s[NMAX];
vector <pii> stack;

inline int64 hash(int x, int d)
{
	return h[x + d] - h[x] * st[d];
}

bool myless(int x, int y)
{
	int l = 0, r = min(n - x, n - y);
	while (l < r - 1)
	{
		int m = (l + r) >> 1;
		if (hash(x, m) == hash(y, m)) l = m;
		else r = m;
	}
	int d;
	if (hash(x, r) == hash(y, r)) d = r;
	else d = l;
	if (n - x == d) return 1;
	if (n - y == d) return 0;
	return s[x + d] < s[y + d];
}

inline int64 calc(int64 x)
{
	return (x + 1) * x / 2;
}

vector <string> zn;

int64 triv()
{
	int64 res = 0;
	string now = s;
	forn(i, n)
		forn(j, i + 1)
			zn.pb(now.substr(j, i - j + 1));
	sort(all(zn));
	zn.resize(unique(all(zn)) - zn.begin());
	forn(i, zn.size())
	{
		int tmp = 0;
		forn(j, n - (int) zn[i].length() + 1)
			if (zn[i] == now.substr(j, zn[i].length())) tmp++;
		res += calc(tmp);
	}
	return res;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	/*forn(i, 100000)
		cout << (char) ('a' + rand()%26);
	cout << endl;
	return 0;*/

	scanf("%s", s);
	n = strlen(s);
	st[0] = 1, h[0] = 0;
	forn(i, n)
	{
		h[i + 1] = h[i] * D + s[i];
		st[i + 1] = st[i] * D;
	}

	forn(i, n)
		suf[i] = i;
	sort(suf, suf + n, myless);
	suf[n] = n;

	ans = 0;
	stack.clear();
	stack.pb(mp(n - suf[0], 0));
	forn(i, n + 1)
		if (i)
		{
			int x = suf[i], y = suf[i - 1];
			int l = 0, r = min(n - x, n - y);
			while (l < r - 1)
			{
				int m = (l + r) >> 1;
				if (hash(x, m) == hash(y, m)) l = m;
				else r = m;
			}
			int d;
			if (hash(x, r) == hash(y, r)) d = r;
			else d = l;
			while (stack.size() > 0 && last(stack).fs > d)
			{
				int tmp = d;
				if (stack.size() > 1) tmp = max(tmp, stack[stack.size() - 2].fs);
				ans += calc(i - last(stack).sc) * (last(stack).fs - tmp);
				if ((stack.size() > 1 && stack[stack.size() - 2].fs >= d) || d == 0) stack.pop_back();
				else last(stack).fs = d;
			}
			if (stack.size() == 0 || n - x > last(stack).fs) stack.pb(mp(n - x, i));
		}
	//cerr << ans << " " << triv() << endl;
	//assert(ans == triv());
	cout << ans << endl;

	cerr << clock() << endl;

	return 0;
}