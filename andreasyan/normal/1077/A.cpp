#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        int a, b, k;
        scanf("%d%d%d", &a, &b, &k);
        long long ans = (a * 1LL * (k - (k / 2))) - (b * 1LL * (k / 2));
        printf("%lld\n", ans);
    }
    return 0;
}