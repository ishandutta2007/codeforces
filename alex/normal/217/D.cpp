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
const string name = "d";

const int NMAX = 63;
const int P = 1000000007;

int n, q, m, m2, used[NMAX], old[NMAX][NMAX], ans, cnt[NMAX];
pii precalc[NMAX][NMAX];

void rec(int now, int zn)
{
	if (zn == 0) return;
    if (now * 2 > m)
    {
        ans += zn;
        if (ans > P) ans -= P;
        return;
    }
    if (!used[now])
    {
        forn(i, m2)
			old[now][i] = used[i];
        forn(i, m2)
            if (old[now][i])
            {
                used[precalc[i][now].fs] = 1;
                used[precalc[i][now].sc] = 1;
            }
        used[now] = 1;
        rec(now + 1, ((int64) zn * cnt[now]) % P);
		forn(i, m2)
			used[i] = old[now][i];
    }
    rec(now + 1, zn);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen((name + ".in").data(), "r", stdin);
    freopen((name + ".out").data(), "w", stdout);
#endif

    cin >> n >> m >> q;
    seta(cnt, 0);
    forn(i, q)
    {
        int zn;
        cin >> zn;
        cnt[min(zn % m, m - zn % m)]++;
    }

    ans = 0;
    m2 = m / 2 + 1;
    forn(i, m2)
        forn(j, m2)
        {
            precalc[i][j].fs = min((i + j) % m, m - (i + j) % m);
            precalc[i][j].sc = min((i - j + m) % m, m - (i - j + m) % m);
        }

    seta(used, 0);
    rec(1, 1);
    cout << ans << endl;
    cerr << clock() << endl;

    return 0;
}