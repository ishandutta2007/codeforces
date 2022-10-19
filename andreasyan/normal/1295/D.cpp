#include <bits/stdc++.h>
using namespace std;
long long gcd(long long x, long long y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}

long long a, m;

long long solv0()
{
    long long ans = 0;
    for (long long x = 0; x < m; ++x)
    {
        if (gcd(a, m) == gcd(a + x, m))
            ++ans;
    }
    return ans;
}

long long solv()
{
    long long g = gcd(a, m);
    long long l = (a / g);
    long long r = ((a + m - 1) / g);
    long long ans = (r - l + 1);
    long long x = m / g;
    vector<long long> v;
    for (long long i = 2; i * i <= x; ++i)
    {
        if (x % i == 0)
        {
            v.push_back(i);
            while (x % i == 0)
                x /= i;
        }
    }
    if (x > 1)
        v.push_back(x);
    for (int x = 1; x < (1 << v.size()); ++x)
    {
        long long u = 1;
        int q = 0;
        for (int i = 0; i < v.size(); ++i)
        {
            if ((x & (1 << i)))
            {
                ++q;
                u *= v[i];
            }
        }
        if (q % 2 == 1)
            ans -= ((r / u) - ((l - 1) / u));
        else
            ans += ((r / u) - ((l - 1) / u));
    }
    return ans;
}

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        scanf("%lld%lld", &a, &m);
        printf("%lld\n", solv());
        /*a = (rand() % 100) + 1;
        m = a + (rand() % 100) + 1;
        if (solv() != solv0())
        {
            printf("WA\n");
            solv();
        }*/
    }
    return 0;
}