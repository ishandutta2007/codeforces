#include <bits/stdc++.h>
using namespace std;
const int N = 33;

int n, k;
long long a[N];

bool c[60];

bool solv()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    memset(c, false, sizeof c);
    for (int i = 1; i <= n; ++i)
    {
        int u = 0;
        while (a[i])
        {
            if (a[i] % k > 1)
                return false;
            if (a[i] % k == 1)
            {
                if (c[u])
                    return false;
                c[u] = true;
            }
            a[i] /= k;
            ++u;
        }
    }
    return true;
}

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        if (solv())
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}