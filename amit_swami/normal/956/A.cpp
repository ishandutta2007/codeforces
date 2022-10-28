#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < (n); i++)
#define err(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
typedef long long ll;

const int N = 55;

char s[N][N];

int main()
{
    #ifdef amit_swami
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif
    int n, m;
    scanf("%d%d", &n, &m);
    forn(i, n) scanf("%s", s[i]);
    int ok = 1;
    forn(i, n) forn(j, i)
    {
        int ok2 = 0;
        int ok1 = 0;
        forn(k, m)
        {
            if (s[i][k] == '#' && s[j][k] == '#') ok2 = 1;
            else if (s[i][k] == '#' || s[j][k] == '#') ok1 = 1;
        }
        if (ok1 && ok2) ok = 0;
    }
    if (ok) printf("Yes\n");
    else printf("No\n");
    
    return 0;
}