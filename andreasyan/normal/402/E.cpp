#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 2003;

int n;
int a[N][N];
int b[N][N];

bool c[N];
void dfs(int x, int a[][N])
{
    c[x] = true;
    for (int h = 1; h <= n; ++h)
    {
        if (a[x][h] && !c[h])
            dfs(h, a);
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            scanf("%d", &a[i][j]);
            b[j][i] = a[i][j];
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (a[i][i])
        {
            memset(c, false, sizeof c);
            dfs(i, a);
            for (int i = 1; i <= n; ++i)
            {
                if (!c[i])
                {
                    printf("NO\n");
                    return 0;
                }
            }
            memset(c, false, sizeof c);
            dfs(i, b);
            for (int i = 1; i <= n; ++i)
            {
                if (!c[i])
                {
                    printf("NO\n");
                    return 0;
                }
            }
            printf("YES\n");
            return 0;
        }
    }
    return 0;
}