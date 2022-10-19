#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n;
char aa[N], a[N];

bool stg(int d)
{
    int x = 0;
    for (int i = 0; i <= x; ++i)
    {
        if (i <= n && a[i] == 'R')
            x = max(x, min(n + 1, i + d));
    }
    return (x == n + 1);
}

void solv()
{
    scanf(" %s", aa);
    n = strlen(aa);
    for (int i = 1; i <= n; ++i)
        a[i] = aa[i - 1];
    a[0] = 'R';
    int l = 1, r = n + 1;
    int ans;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (stg(m))
        {
            ans = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }
    printf("%d\n", ans);
}

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        solv();
    }
    return 0;
}