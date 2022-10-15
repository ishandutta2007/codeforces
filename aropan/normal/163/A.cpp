#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 5005;
const int MOD = (int)1e+9 + 7;


char a[MAXN];
char b[MAXN];
int f[MAXN][MAXN];
int prev[MAXN][26];
int next[MAXN][26];
int n, m;

inline void add(int &x, int d)
{
    x += d;
    if (x >= MOD) x -= MOD;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen(".in", "r", stdin);
        freopen(".out", "w", stdout);
    #endif
    scanf("%s", a + 1);
    n = strlen(a + 1);
    scanf("%s", b + 1);
    m = strlen(b + 1);

    for (int i = 1; i <= n; i++) a[i] -= 'a';
    for (int i = 1; i <= m; i++) b[i] -= 'a';

    for (int i = 0; i < 26; i++) prev[1][i] = 0;
    for (int i = 2; i <= m + 1; i++)
    {
        memmove(prev[i], prev[i - 1], sizeof(prev[i]));
        prev[i][b[i - 1]] = i - 1;
    }

    for (int i = 0; i < 26; i++) next[m][i] = m + 1;
    for (int i = m - 1; i >= 0; i--)
    {
        memmove(next[i], next[i + 1], sizeof(next[i]));
        next[i][b[i + 1]] = i + 1;
    }

    for (int i = 1; i <= n; i++)
        f[i][0] = 1;

    for (int i = 1; i <= n + 1; i++)
        for (int j = 0; j <= m; j++)
        {
            if (j && prev[j][b[j]]) add(f[i][j], f[i][prev[j][b[j]]]);
            if (f[i][j] == 0) continue;
//            printf("f[%d][%d] = %d\n", i, j, f[i][j]);
/*
            int x = j;
            while ((x = next[x][a[i]]) <= m)
                add(f[i + 1][x], f[i][j]);
/*/
            if (i <= n)
                add(f[i + 1][next[j][a[i]]], f[i][j]);
//*/
        }
    int ans = 0;
    for (int i = 1; i <= n + 1; i++)
        for (int j = 1; j <= m; j++)
            add(ans, f[i][j]);
    printf("%d\n", ans);
    return 0;
}