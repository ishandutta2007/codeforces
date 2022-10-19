#include <bits/stdc++.h>
using namespace std;

long long a, b, c, d, e, f;

int main()
{
    scanf("%lld%lld%lld%lld%lld%lld", &a, &b, &c, &d, &e, &f);
    b = min(b, c);
    long long ans = 0;
    for (long long i = 0; i <= d; ++i)
    {
        ans = max(ans, min(a, i) * e + min(b, (d - i)) * f);
    }
    printf("%lld\n", ans);
    return 0;
}