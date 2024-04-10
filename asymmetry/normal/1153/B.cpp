#include <bits/stdc++.h>

using namespace std;

int n, m, h;
int f[101];
int l[101];
int g[101][101];

int main()
{
    scanf("%d%d%d", &n, &m, &h);
    for(int i=1; i<=m; ++i)
    {
        scanf("%d", &f[i]);
    }
    for(int i=1; i<=n; ++i)
    {
        scanf("%d", &l[i]);
    }
    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=m; ++j)
        {
            scanf("%d", &g[i][j]);
        }
    }
    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=m; ++j)
        {
            if(g[i][j])
            {
                g[i][j]=min(l[i], f[j]);
            }
        }
    }
    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=m; ++j)
        {
            printf("%d ", g[i][j]);
        }
        printf("\n");
    }
    return 0;
}