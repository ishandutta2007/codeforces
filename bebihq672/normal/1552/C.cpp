#include<bits/stdc++.h>
using namespace std;

int x[202], y[202];

int its(int x1, int y1, int x2, int y2)
{
    int ret = 0;
    if(x1 > y1)
        swap(x1, y1);
    ret = (x1 < x2 && x2 < y1) ^ (x1 < y2 && y2 < y1);
    return ret;
}

bool vis[202];

int  main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        memset(vis, 0, sizeof(vis));
        int n, k;
        scanf("%d%d", &n, &k);
        for(int i = 1; i <= k; i++)
        {
            scanf("%d%d", &x[i], &y[i]);
            vis[x[i]] = 1;
            vis[y[i]] = 1;
        }
        for(int i = 1; i <= 2 * n; i++)
        if(vis[i] == 0)
        {
            int cnt = 0;
            for(int j = i + 1;;j = j % (2 * n) + 1)
            if(vis[j] == 0)
            {
                cnt++;
                if(cnt == n - k)
                {
                    k++;
                    x[k] = i;
                    y[k] = j;
                    vis[i] = 1;
                    vis[j] = 1;
                    break;
                }
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++)
            for(int j = i + 1; j <= n; j++)
                ans = ans + its(x[i], y[i], x[j], y[j]);
    
        printf("%d\n", ans);
    }
    return 0;
}