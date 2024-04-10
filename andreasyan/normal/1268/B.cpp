#include <bits/stdc++.h>
using namespace std;
const int N = 300005;

int n;
int a[N];

long long dp[N][2];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    long long w = 0, b = 0;
    for (int i = 1; i <= n; ++i)
    {
        w += a[i] / 2;
        b += a[i] / 2;
        if (a[i] % 2 == 1)
        {
            if (i % 2 == 1)
            {
                ++b;
            }
            else
            {
                ++w;
            }
        }
    }
    printf("%lld\n", min(b, w));
    return 0;
}