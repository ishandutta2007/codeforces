#pragma comment(linker, "/STACK:60000000")
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <sstream>
#include <iomanip>
#include <complex>
#include <queue>
#include <functional>

using namespace std;

#define next NEXT
#define prev PREV
#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define seta(a,x) memset (a, x, sizeof (a))
#define I (int)
#define y1 botva

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;

template <class T> T sqr (T x) {return x * x;}

const int NMAX = 1005;
const int P = 1000000007;

int n, m, k;
int64 f[NMAX * NMAX], power[NMAX * NMAX], pre_calc[2 * NMAX];

int64 Fpower(int64 x, int64 st)
{
    int64 res = 1;
    while (st > 0)
    {
        if (st & 1) res = (res * x) % P;
        st >>= 1;
        x = (x * x) % P;
    }
    return res;
}

int64 C(int n, int m)
{
    if (n < m) return 0;
    return (f[n] * ((power[m] * power[n - m]) % P)) % P;
}

int64 /*D[NMAX][NMAX], */c[NMAX][NMAX], D2[NMAX][NMAX];

int main ()
{
    //freopen ("input.txt", "r", stdin);
    //freopen ("output.txt", "w", stdout);

	cin >> m >> n >> k;
	if (n == 1)
    {
        cout << Fpower(k, m) << endl;
        return 0;
    }
    f[0] = 1;
    forn(i, max(n * m, k))
		f[i + 1] = (f[i] * (i + 1)) % P;
	forn(i, max(n * m, k) + 1)
		if (i <= 2000 || i >= k - 2000) power[i] = Fpower(f[i], P - 2);

    forn(i, m + 1)
    {
        c[i][0] = 1;
        forn(j, i)
			c[i][j + 1] = (c[i - 1][j + 1] + c[i - 1][j]) % P;
    }

    cerr << clock() << endl;
/*    forn(i, m + 1)
        forn(j, m + 1)
        {
            if (i == 0) D[i][j] = 1;
            else if (j == 0) D[i][j] = 0;
            else
            {
                D[i][j] = 0;
                for (int f = 1; f <= i - j + 1; ++f)
                    D[i][j] = (D[i][j] + D[i - f][j - 1] * c[i][f]) % P;
            }
        }*/

	seta(D2, 0);
	D2[1][1] = 1;
    forn(i, m + 1)
        forn(j, i + 1)
			if (D2[i][j] > 0)
			{
				D2[i + 1][j] = (D2[i + 1][j] + D2[i][j] * j) % P;
				D2[i + 1][j + 1] = (D2[i + 1][j + 1] + D2[i][j]) % P;
				D2[i][j] = (D2[i][j] * f[j]) % P;
			}

//	forn(i, m + 1)
//		forn(j, m + 1)
//			if (i && j) assert(D2[i][j] == D[i][j]);
    cerr << clock() << endl;

	forn(i, 2000)
		pre_calc[i] = Fpower(i, (n - 2) * m);
	int64 ans = 0;
	forn(i, min(k, m) + 1)
		if (i)
		{
			forn(j, i + 1)
			{
				int64 res = pre_calc[j];
				res = (res * D2[m][i]) % P;
				res = (res * D2[m][i]) % P;
				int64 now = (C(k - i,i - j) * ((C(k,j) * C(k - j,i - j)) % P)) % P;
				ans = (ans + (res * now)) % P;
			}
		}
	cout << ans << endl;
	cerr << clock() << endl;

	return 0;
}