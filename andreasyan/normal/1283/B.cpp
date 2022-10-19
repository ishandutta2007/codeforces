#include <bits/stdc++.h>
using namespace std;

int n, k;

void solv()
{
    scanf("%d%d", &n, &k);
    int ans = (n / k) * k;
    if ((n % k) <= (k / 2))
        ans += (n % k);
    else
        ans += (k / 2);
    printf("%d\n", ans);
}

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}