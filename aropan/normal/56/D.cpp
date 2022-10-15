#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 1111;
const int INF = (int)2e+9;

char a[MAXN];
char b[MAXN];
int f[MAXN][MAXN];
int n, m;

int rec(int n, int m)
{
    if (n == 0 && m == 0)
        return 0;

    if (n && f[n - 1][m] + 1 == f[n][m])
    {
        int l = rec(n - 1, m);
        printf("DELETE %d\n", l + 1);
        return l;
    }

    if (m && f[n][m - 1] + 1 == f[n][m])
    {
        int l = rec(n, m - 1) + 1;
        printf("INSERT %d %c\n", l, b[m - 1]);
        return l;
    }

    int l = rec(n - 1, m - 1) + 1;
    if (a[n - 1] != b[m - 1])
        printf("REPLACE %d %c\n", l, b[m - 1]);
    return l;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif

    gets(a);
    gets(b);
    n = strlen(a);
    m = strlen(b);

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            f[i][j] = INF;

    f[0][0] = 0;

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
        {
            f[i + 1][j] = min(f[i + 1][j], f[i][j] + 1);
            f[i][j + 1] = min(f[i][j + 1], f[i][j] + 1);
            f[i + 1][j + 1] = min(f[i + 1][j + 1], f[i][j] + (a[i] != b[j]));
        }
    printf("%d\n", f[n][m]);
    rec(n, m);
    return 0;
}