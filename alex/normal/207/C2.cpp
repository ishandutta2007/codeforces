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
typedef pair <double, double> pdd;

#define y0 wwwwwww
#define y1 qqqqqqq
#define left LEFT
#define right RIGHT
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

template <class T> T sqr(T x) { return x * x; }

double const pi = 3.1415926535897932384626433832795;
int const inf = (int) 1e9;
int64 const inf64 = (int64) 4e18;
const string name = "c";

const int NMAX = 7010;

int64 ans;
int n, m1, m2, cnt;
int idx[NMAX], num1[NMAX], num2[NMAX];
pair <int, char> prev[NMAX];
int nxt[NMAX][30];
pii save[NMAX];

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n;
	seta(num1, 0);
	idx[0] = 0;
	num1[0] = 1;
	seta(num2, 0);
	num2[0] = 1;
	seta(nxt, 255);
	m1 = 1, m2 = 1, cnt = 1;
	prev[0] = mp(-1, -1);
	forn(i, n)
	{
		int op, x;
		char c, buf[4];
		scanf("%d%d%s", &op, &x, buf);
		c = buf[0];
		x--;
		if (op == 2)
		{
			prev[m2] = mp(x, c);
			int now2 = m2++, now1 = 0;
			while (now1 >= 0 && now2 >= 0)
			{
				num2[now1]++;
				if (nxt[now1][prev[now2].sc - 'a'] == -1) break;
				now1 = nxt[now1][prev[now2].sc - 'a'];
				now2 = prev[now2].fs;
			}
			save[m2 - 1] = mp(now1, now2);
		}
		else
		{
			int now1 = idx[x];
			if (nxt[now1][c - 'a'] == -1)
			{
				nxt[now1][c - 'a'] = cnt++;
				forn(j, m2)
					if (save[j].fs == now1 && prev[save[j].sc].sc == c)
					{
						num2[cnt - 1]++;
						save[j] = mp(cnt - 1, prev[save[j].sc].fs);
					}
			}
			num1[nxt[now1][c - 'a']]++;
			idx[m1++] = nxt[now1][c - 'a'];
		}

		ans = 0;
		forn(i, cnt)
			ans += num1[i] * num2[i];
		printf("%d\n", ans);
	}

	return 0;
}