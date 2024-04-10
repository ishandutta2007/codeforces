#include <cstdio>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <iostream>

using namespace std;

const int MAXN = 111;
const int MAXM = 2 * MAXN;

int last[MAXN];
int next[MAXM], dest[MAXM];
int deep[MAXN];
int n, m;

int dfs(int x, int p)
{
    deep[x] = deep[p] + 1;
    int res = x;

    for (int i = last[x]; i; i = next[i])
        if (dest[i] != p)
        {
            int y = dfs(dest[i], x);
            if (deep[y] > deep[res]) res = y;
        }
    return res;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    int ans = 0;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            last[i] = 0;

        for (int i = 1; i < n; i++)
        {
            int x, y;
            scanf("%d %d", &x, &y);

            dest[i] = y;
            next[i] = last[x];
            last[x] = i;

            dest[i + n] = x;
            next[i + n] = last[y];
            last[y] = i + n;
        }

        ans += deep[dfs(dfs(1, 0), 0)] - 1;
    }
    printf("%d\n", ans);

    fprintf(stderr, "Time of execution: %.3lf sec.\n", (double)clock()/CLOCKS_PER_SEC);
    return 0;
}