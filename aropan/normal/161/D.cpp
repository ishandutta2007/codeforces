#include <cstdio>
#include <algorithm>
#include <iostream>
#include <ctime>

using namespace std;

const int MAXN = 50007;
const int MAXM = 503;

int f[MAXN][MAXM];
long long ans;
int last[MAXN];
int next[MAXN << 1], dest[MAXN << 1];
int n, m;


void dfs(int x, int p)
{
    f[x][0] = 1;
    for (int i = last[x]; i; i = next[i])
    {
        int y = dest[i];
        if (y == p) continue;
        dfs(y, x);

        for (int j = 0; j < m; j++)
            ans += f[x][j] * (long long)f[y][m - j - 1];

        for (int j = 1; j <= m; j++)
            f[x][j] += f[y][j - 1];
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen(".in", "r", stdin);
        freopen(".out", "w", stdout);
    #endif
    scanf("%d %d", &n, &m);
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

    ans = 0;
    dfs(1, -1);
    cout << ans << endl;

    fprintf(stderr, "Time execute: %.3lf\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}