/**
 *    author:  SPb ITMO University 1
 *    created: 27.10.2016 10:44:45       
**/
#define __USE_MINGW_ANSI_STDIO 0
#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define mp make_pair
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(),a.end()
#define pw(x) (1LL<<(x))

using namespace std;

typedef long long ll;
typedef double dbl;
typedef vector<int> vi;
typedef pair<int, int> pi;

const int inf = 1.01e9;
const dbl eps = 1e-9;

/* --- main part --- */

const int N = 110;

int a[N], b[N];

int d[N][N * N];


int main()
{
    #ifdef home
        assert(freopen("1.in", "r", stdin));
        assert(freopen("1.out", "w", stdout));
    #endif
    int n;
    scanf("%d", &n);
    forn(i, n) scanf("%d", a + i);
    forn(i, n) scanf("%d", b + i);
    memset(d, -1, sizeof d);
    d[0][0] = 0;
    int S = 0;
    int s = 0;
    forn(i, n)
    {
        for (int j = i; j >= 0; --j) forn(z, S + 1) if (d[j][z] != -1)
        {
            d[j + 1][z + b[i]] = max(d[j + 1][z + b[i]], d[j][z] + a[i]);
        }
        S += b[i];
        s += a[i];
    }
    sort(b, b + n);
    reverse(b, b + n);
    int k = 0;
    int ss =0;
    while (ss < s)
    {
        ss += b[k];
        k++;
    }


    int t = inf;
    for (int i = s; i < N * N; ++i) t = min(t, s - d[k][i]);
    printf("%d %d\n", k, t);
    #ifdef home
        eprintf("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}