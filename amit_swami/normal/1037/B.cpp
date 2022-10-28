#include <bits/stdc++.h>
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define err(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
using namespace std;
typedef long long ll;

const int N = 2e5;

int a[N];

int main()
{
    #ifdef amit
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif
    int n, s;
    scanf("%d%d", &n, &s);
    forn(i, n) scanf("%d", &a[i]);
    sort(a, a + n);
    if (a[n / 2] < s) {
        ll r = 0;
        for (int i = n / 2; i < n; i++) if (a[i] < s) {
            r += s - a[i];
        }
        printf("%lld\n", r);
    } else {
        ll r = 0;
        for (int i = n / 2; i >= 0; i--) if (a[i] > s) {
            r += a[i] - s;
        }
        printf("%lld\n", r);
    }

    
    return 0;
}