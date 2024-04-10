#include <bits/stdc++.h>
using namespace std;
const int N = 300005, M = 9, INF = 1000000009;

int n, m;
int a[N][M];
int maxu[(1 << M)], maxi[(1 << M)];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int x = 0; x < (1 << m); ++x)
        {
            int minu = INF;
            for (int j = 0; j < m; ++j)
            {
                if ((x & (1 << j)))
                    minu = min(minu, a[i][j]);
            }
            if (minu >= maxu[x])
            {
                maxu[x] = minu;
                maxi[x] = i;
            }
        }
    }
    int ans = -1;
    int ansi, ansj;
    for (int x = 0; x < (1 << m); ++x)
    {
        int y = 0;
        for (int j = 0; j < m; ++j)
        {
            if (!(x & (1 << j)))
                y |= (1 << j);
        }
        if (min(maxu[x], maxu[y]) >= ans)
        {
            ans = min(maxu[x], maxu[y]);
            ansi = maxi[x];
            ansj = maxi[y];
        }
    }
    printf("%d %d\n", ansi, ansj);
    return 0;
}