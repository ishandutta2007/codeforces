#include <bits/stdc++.h>
using namespace std;
const int N = 400005;

long long gcd(long long x, long long y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}

int n;
long long a[N];

int main()
{
    scanf("%d", &n);
    long long g;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld", &a[i]);
        if (i == 1)
            g = a[i];
        else
            g = gcd(g, a[i]);
    }
    long long ans = 0;
    for (long long i = 1; i * i <= g; ++i)
    {
        if (g % i == 0)
        {
            ++ans;
            if (i != g / i)
                ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}