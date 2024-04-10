#include <bits/stdc++.h>
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define err(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
using namespace std;
typedef long long ll;

const int N = 2e6;

char s[N];
char t[N];
int a[N];

int main()
{
    #ifdef amit
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif
    int n;
    scanf("%d%s%s", &n, s, t);
    forn(i, n) a[i] = s[i] != t[i];
    int r = 0;
    forn(i, n) if (a[i]) {
        if (i + 1 < n && a[i + 1] && s[i] != s[i + 1]) {
            r += 1;
            i += 1;
        } else {
            r += 1;
        }
    }
    printf("%d\n", r);                    
    return 0;
}