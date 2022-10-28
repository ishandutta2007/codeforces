#include <bits/stdc++.h>
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define err(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
using namespace std;
typedef long long ll;


int main()
{
    #ifdef amit
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif
    int x;
    scanf("%d", &x);
    int k = 1, r = 1;
    while (k < x) {
        k = 2 * k + 1;
        r += 1;
    }
    printf("%d\n", r);        
    return 0;
}