/**
 *    author:  SPb ITMO University 1
 *    created: 27.10.2016 10:33:05       
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

const int N = 1010;

char s[N][N];
char r[N];
int a[N];
int len[N];

int main()
{
    #ifdef home
        assert(freopen("1.in", "r", stdin));
        assert(freopen("1.out", "w", stdout));
    #endif
    int n, m;
    scanf("%d%d", &n, &m);
    forn(i, n) scanf("%s", s[i]);
    forn(i, m) scanf("%d", a + i);
    forn(i, m) a[i]--;
    forn(i, n) len[i] = strlen(s[i]);
    int todel = len[a[0]];
    forn(i, todel) r[i] = s[a[0]][i];
    int ok = 1;
    forn(i, m)
    {
        if (todel != len[a[i]])
        {
            ok = 0;
            break;
        }
        forn(j, todel)
        {
            if (r[j] != s[a[i]][j]) r[j] = '?';
        }
    }
    eprintf("r = %s\n", r);
    int cnt = 0;
    forn(i, n)
    {
        if (todel != len[i]) continue;
        int oak = 1;
        forn(j, todel) if (s[i][j] != r[j] && r[j] != '?') oak = 0;
        cnt += oak;
    }
    if (cnt != m) ok = 0;
    if (ok) printf("Yes\n%s\n", r);
    else printf("No\n");


    
    #ifdef home
        eprintf("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}