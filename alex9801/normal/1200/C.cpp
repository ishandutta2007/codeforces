#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    long long n, m;
    int q, i;
    scanf("%lld%lld%d", &n, &m, &q);

    long long g = gcd(n, m);

    for(i = 0; i < q; i++)
    {
        long long x, y, z, w;
        scanf("%lld%lld%lld%lld", &x, &y, &z, &w);

        long long u, v;
        if(x == 1)
            u = (y - 1) / (n / g);
        else
            u = (y - 1) / (m / g);

        if(z == 1)
            v = (w - 1) / (n / g);
        else
            v = (w - 1) / (m / g);

        if(u == v)
            puts("yes");
        else
            puts("no");
    }

    return 0;
}