#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <stdlib.h>

std::vector<int> arr[100001];

int down[100001];
int up[100001];

int par[100001];
int col[100001];

void dfs(int x)
{
    int c = col[x];
    for (int y : arr[x])
    {
        if (y == par[x])
            continue;

        par[y] = x;
        dfs(y);

        if (down[y] != c)
            c = -1;
    }
    down[x] = c;
}

void dfs2(int x)
{
    bool u = 1;
    if (up[x] == -1)
        u = 0;
    else
    {
        for (int y : arr[x])
        {
            if (y == par[x])
                continue;
            if (down[y] == -1)
            {
                u = 0;
                break;
            }
        }
    }

    if (u)
    {
        printf("YES\n%d", x);
        exit(0);
    }
    int k1 = 0, k2 = 0;
    if (up[x] != col[x])
    {
        k1 = k2 = 1;
    }
    else
    {
        for (int y : arr[x])
        {
            if (y == par[x])
                continue;

            if (down[y] != up[x])
            {
                if (!k1)
                    k1 = y;
                else
                {
                    k2 = y;
                    break;
                }
            }
        }
    }

    for (int y : arr[x])
    {
        if (y == par[x])
            continue;

        if (k2)
            up[y] = -1;
        else if (k1)
        {
            if (k1 == y)
                up[y] = col[x];
            else
                up[y] = -1;
        }
        else
            up[y] = col[x];
    }

    for (int y : arr[x])
    {
        if (y == par[x])
            continue;
        dfs2(y);
    }
}

int main()
{
    int n, x, y, i;
    scanf("%d", &n);
    for (i = 0; i < n - 1; i++)
    {
        scanf("%d%d", &x, &y);
        arr[x].push_back(y);
        arr[y].push_back(x);
    }
    for (i = 1; i <= n; i++)
        scanf("%d", &col[i]);

    up[1] = col[1];

    dfs(1);
    dfs2(1);

    printf("NO");
    return 0;
}