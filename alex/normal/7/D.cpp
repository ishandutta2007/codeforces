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
#define last(a) a[a.size() - 1];
#define mp make_pair
#define fs first
#define sc second

template <class T> T sqr(T x) { return x * x; }

double const pi = 3.1415926535897932384626433832795;
int const inf = (int) 1e9;
int64 const inf64 = (int64) 4e18;
const string name = "c";

const int NMAX = 5000010;

template <class T> class Thasher {
public:
	Thasher(T d, const char *s)
	{
		n = strlen(s);
		h = (T *) malloc((n + 1) * sizeof(T));
		st = (T *) malloc((n + 1) * sizeof(T));
		h[0] = 0, st[0] = 1;
		forn(i, n)
			h[i + 1] = h[i] * d + s[i], st[i + 1] = st[i] * d;
	}
	T calc(int l, int r)
	{
#ifndef _MY_OPT_MODE_
		if (l > r || l < 0 || r >= n) cerr << "ERROR! Thasher:calc() with wrong substring!" << endl;
#endif
		return h[r + 1] - h[l] * st[r - l + 1];
	}
	~Thasher() { free(h); free(st); }
	
private:
	T *h, *st;
	int n;
};

int n, ans, st[NMAX];
char s[NMAX];

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	gets(s);
	n = strlen(s);
	ans = 0;
	Thasher <int64> h1(239, s);
	reverse(s, s + n);
	Thasher <int64> h2(239, s);
	seta(st, 0);
	for (int i = 1; i <= n; ++i)
	{
		if (h1.calc(0, i - 1) == h2.calc(n - i, n - 1))
			st[i] = st[i >> 1] + 1;
		ans += st[i];
	}
	cout << ans << endl;

	return 0;
}