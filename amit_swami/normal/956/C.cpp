#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < (n); i++)
#define err(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
typedef long long ll;

const int N = 110000;

int a[N];
int b[N];

int main()
{
    #ifdef amit_swami
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif
    int n;
    scanf("%d", &n);
    forn(i, n) scanf("%d", &a[i]);
    for (int i = n - 1; i >= 0; --i) b[i] = max(1, max(b[i + 1] - 1, a[i] + 1));
    int cur = 0;
    ll res = 0;
    forn(i, n)
    {
        if (b[i] > cur)
        {
            cur++;
        }
        res += cur - a[i] - 1;
    }
    printf("%lld\n", res);
    return 0;
}