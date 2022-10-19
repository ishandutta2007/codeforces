#include <bits/stdc++.h>
using namespace std;
const int N = 200005, INF = 1000000009;
struct ban
{
    int i;
    int x;
};
bool operator<(const ban& a, const ban& b)
{
    return a.x < b.x;
}

int n;
ban a[N];

int dp[N];
int p[N];

int minu[N];
int mini[N];

int u;
int ans[N];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        a[i].i = i;
        scanf("%d", &a[i].x);
    }
    sort(a + 1, a + n + 1);
    for (int i = 0; i <= n; ++i)
    {
        if (0 < i && i < 3)
        {
            dp[i] = INF;
            p[i] = -1;
        }
        else if (i >= 3)
        {
            dp[i] = a[i].x + minu[i - 3];
            p[i] = mini[i - 3];
        }
        if (!i || dp[i] - a[i + 1].x < minu[i - 1])
        {
            minu[i] = dp[i] - a[i + 1].x;
            mini[i] = i;
        }
        else
        {
            minu[i] = minu[i - 1];
            mini[i] = mini[i - 1];
        }
    }
    int x = n;
    while (1)
    {
        if (x == 0)
            break;
        ++u;
        for (int i = p[x] + 1; i <= x; ++i)
            ans[a[i].i] = u;
        x = p[x];
    }
    printf("%d %d\n", dp[n], u);
    for (int i = 1; i <= n; ++i)
        printf("%d ", ans[i]);
    printf("\n");
    return 0;
}