#include <bits/stdc++.h>
using namespace std;
const int N = 1000006, m = 20;

int n;
char a[N];

bool c[1 << m];

int dp[1 << m];
int main()
{
    scanf(" %s", a);
    n = strlen(a);
    for (int i = 0; i < n; ++i)
    {
        int x = 0;
        for (int j = i; j < n; ++j)
        {
            if ((x & (1 << (a[j] - 'a'))))
                break;
            x |= (1 << (a[j] - 'a'));
            c[x] = true;
        }
    }
    for (int x = 0; x < (1 << m); ++x)
    {
        int q = 0;
        for (int i = 0; i < m; ++i)
        {
            if ((x & (1 << i)))
                ++q;
        }
        if (c[x])
        {
            dp[x] = q;
            continue;
        }
        for (int i = 0; i < m; ++i)
        {
            if ((x & (1 << i)))
            {
                dp[x] = max(dp[x], dp[(x ^ (1 << i))]);
            }
        }
    }
    int ans = 0;
    for (int x = 0; x < (1 << m); ++x)
    {
        if (!c[x])
            continue;
        int y = 0;
        for (int i = 0; i < m; ++i)
        {
            if (!(x & (1 << i)))
                y |= (1 << i);
        }
        ans = max(ans, dp[x] + dp[y]);
    }
    cout << ans << endl;
    return 0;
}