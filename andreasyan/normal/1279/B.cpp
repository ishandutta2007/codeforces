#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n, s;
int a[N];

long long p[N];

void solv()
{
    scanf("%d%d", &n, &s);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
        p[i] = p[i - 1] + a[i];
    int maxi = 0;
    int maxu = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (p[i] <= s)
        {
            maxu = i;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (p[i - 1] > s)
            continue;
        int l = i + 1, r = n;
        int ans = i;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (p[i - 1] + p[m] - p[i] <= s)
            {
                l = m + 1;
                ans = m;
            }
            else
                r = m - 1;
        }
        if (i - 1 + ans - i > maxu)
        {
            maxu = i - 1 + ans - i;
            maxi = i;
        }
    }
    printf("%d\n", maxi);
}

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}