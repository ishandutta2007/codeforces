#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 5005;

int f[MAXN];
char a[MAXN][MAXN];
int p[MAXN];
int n, m;

int dfs(int x)
{
    if (f[x] == -1) return 0;

    if (f[x])
    {
        reverse(p, p + m);
        while (p[m - 1] != x) m--;

        reverse(p, p + m);
        for (int i = 2; i < m; i++)
            if (a[p[i]][p[0]] == '1')
            {
                printf("%d %d %d\n", p[0], p[i - 1], p[i]);
                exit(0);
            }
    }

    f[x] = 1;
    p[m++] = x;

    for (int i = 1; i <= n; i++)
        if (a[x][i] == '1')
            dfs(i);

    p[--m] = 0;
    f[x] = -1;
    return 0;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif

    scanf("%d\n", &n);
    for (int i = 1; i <= n; i++)
        gets(a[i] + 1);

    for (int i = 1; i <= n; i++)
        dfs(i);
    puts("-1");
    return 0;
}