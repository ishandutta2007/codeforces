#include <cstdio>

using namespace std;

const int MAXN = 111111;

int n, st, fn;
int last[MAXN];
int next[MAXN], yy[MAXN];
int ans[MAXN];


int dfs(int x, int prev = 0)
{
    ans[x] = prev;
    int i = last[x];

    while (i)
    {
        if (yy[i] != prev) dfs(yy[i], x);
        i = next[i];
    }

    return 0;
}


int main()
{
/*
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
//*/
    scanf("%d %d %d", &n, &st, &fn);
    for (int i = 1; i <= n; i++)
    {
        if (i == st) continue;
        int x;
        scanf("%d", &x);

        yy[i] = i;
        next[i] = last[x];
        last[x] = i;

        yy[i + n] = x;
        next[i + n] = last[i];
        last[i] = i + n;
    }

    dfs(fn);
    for (int i = 1; i <= n; i++)
    {
        if (i == fn) continue;
        printf("%d ", ans[i]);
    }
    printf("\n");


    return 0;
}