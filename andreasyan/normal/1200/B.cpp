#include <bits/stdc++.h>
using namespace std;
const int N = 102;

int n, m, k;
int a[N];
bool solv()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i < n; ++i)
    {
        m += a[i] - max(a[i + 1] - k, 0);
        if (m < 0)
            return false;
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