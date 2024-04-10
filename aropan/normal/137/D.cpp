#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 505;
const int INF = (int)1e+9;

int f[MAXN][MAXN];
int g[MAXN][MAXN];
int p[MAXN][MAXN];
char s[MAXN];
int n, m;

int rec(int i, int j)
{
    if (i == 0) return 0;
    rec(p[i][j], j - 1);
    if (p[i][j]) printf("+");

    for (int k = 0; k < i - p[i][j]; k++)
        printf("%c", (s[p[i][j] + 1 + k] != s[i - k] && p[i][j] + 1 + k < i - k)? s[i - k] : s[p[i][j] + 1 + k]);
    return 0;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif
    gets(s + 1);
    n = strlen(s + 1);

    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
        {
            f[i][j] = 0;
            for (int k = 0; k < (j - i + 1) / 2; k++)
                f[i][j] += s[i + k] != s[j - k];
        }
    scanf("%d", &m);

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            g[i][j] = INF;

    g[0][0] = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (g[i][j] < INF)
            {
                for (int k = i + 1; k <= n; k++)
                    if (g[i][j] + f[i + 1][k] < g[k][j + 1])
                    {
                        g[k][j + 1] = g[i][j] + f[i + 1][k];
                        p[k][j + 1] = i;
                    }
            }
    int x = 0;
    for (int i = 1; i <= m; i++)
        if (g[n][i] < g[n][x])
            x = i;
    printf("%d\n", g[n][x]);
    rec(n, x);
    printf("\n");
    return 0;
}