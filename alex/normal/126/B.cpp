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
#define I (int)

template <class T> T sqr(T x) { return x * x; }

double const pi = 3.1415926535897932384626433832795;
int const inf = (1 << 30) - 1;
int64 const inf64 = (1LL << 62) - 1;
const string name = "b";

int n, p[1000100], cnt[1001000];
char s[1001000];

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	scanf("%s", s);
	n = strlen(s);
	p[1] = 0;
	int j = 0;
	seta(cnt, 0);
	for (int i = 2; i <= n; ++i)
	{
		while (j > 0 && s[i - 1] != s[j])
			j = p[j];
		if (s[i - 1] == s[j]) j++;
		p[i] = j;
		cnt[j]++;
	}
	ford(i, n + 1)
		cnt[i] += cnt[i + 1];

	int now = p[n];
	while (now > 0)
	{
		if (cnt[now] > 1)
		{
			forn(j, now)
				printf("%c", s[j]);
			return 0;
		}
		now = p[now];
	}
	cout << "Just a legend" << endl;

	return 0;
}