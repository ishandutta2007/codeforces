#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < (n); i++)
#define err(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
typedef long long ll;



int main() {
#ifdef amit_swami
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    forn(_, n)
    {
        ll p, q, b;
        scanf("%lld%lld%lld", &p, &q, &b);
        ll g = __gcd(p, q);
        q /= g;
        b = __gcd(b, q);
        while (1)
        {
            g = __gcd(b, q);
            if (g == 1) break;
            q /= g;
        }
        if (q == 1) printf("Finite\n");
        else printf("Infinite\n");
    }


    return 0;
}