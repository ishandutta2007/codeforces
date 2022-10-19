#include <bits/stdc++.h>
using namespace std;
const int N = 1003;

int n, m;
int a[N][N];

int v[N];

int zt[N], zs[N];
int t[N][N], s[N][N];

map<int, int> mp;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        mp.clear();
        for (int j = 1; j <= m; ++j)
            v[j] = a[i][j];
        sort(v + 1, v + m + 1);
        for (int j = 1; j <= m; ++j)
        {
            if (v[j] != v[j - 1])
                mp[v[j]] = ++zt[i];
        }
        for (int j = 1; j <= m; ++j)
            t[i][j] = mp[a[i][j]];
    }
    for (int j = 1; j <= m; ++j)
    {
        mp.clear();
        for (int i = 1; i <= n; ++i)
            v[i] = a[i][j];
        sort(v + 1, v + n + 1);
        for (int i = 1; i <= n; ++i)
        {
            if (v[i] != v[i - 1])
                mp[v[i]] = ++zs[j];
        }
        for (int i = 1; i <= n; ++i)
            s[i][j] = mp[a[i][j]];
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            int ans = max(s[i][j], t[i][j]) + max(zs[j] - s[i][j], zt[i] - t[i][j]);
            printf("%d ", ans);
        }
        printf("\n");
    }
    return 0;
}