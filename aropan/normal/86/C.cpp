#include <cstdio>
#include <queue>
#include <cstring>


const int MAXN = 1112;
const int MAXM = 12;
const int MAXL = 12;
const int MAXT = MAXM * MAXL;
const int MOD = 1000000009;

using namespace std;

int a[MAXT][4];
int p[MAXT];
int g[MAXT];
int d[MAXT];
int l[MAXT];
char s[MAXL];
int n, m, k;

int f[MAXN][MAXT][MAXL];

queue <int> q;

int chtox(char c)
{
    if (c == 'A') return 0;
    if (c == 'C') return 1;
    if (c == 'G') return 2;
    if (c == 'T') return 3;
    return -1;
}

int add(int &x, int y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "rt", stdin);
        freopen("out", "wt", stdout);
    #endif

    scanf("%d %d\n", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int x = 0;
        gets(s);
        if (strlen(s) > n) continue;
        for (int j = 0; s[j]; j++)
        {
            int t = chtox(s[j]);
            if (a[x][t] == 0)
            {
                ++k;
                a[x][t] = k;
                d[k] = 0;
                p[k] = x;
                l[k] = t;
            }
            x = a[x][t];
        }
        d[x] = strlen(s);
    }

    q.push(0);
    while (q.size())
    {
        int
            x = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
            if (a[x][i])
                q.push(a[x][i]);
                
        if (x == 0) continue;

        g[x] = p[x] == 0? 0 : a[g[p[x]]][l[x]];
        d[x] = max(d[x], d[g[x]]);

        for (int i = 0; i < 4; i++)
            if (a[x][i] == 0)
                a[x][i] = a[g[x]][i];

/*
        for (int i = 0; i < 4; i++)
            printf("%d %d\n", x, a[x][i]);
//*/
    }

    f[0][0][0] = 1;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
            for (int l = MAXL - 2; l >= 0; l--)
                if (f[i][j][l])
                {
//                    printf("f[%d][%d][%d] = %d\n", i, j, l, f[i][j][l]);
                    if (l && l <= d[j])
                        add(f[i][j][0], f[i][j][l]);
                    else
                        for (int z = 0; z < 4; z++)
                            if (a[j][z])
                                add(f[i + 1][a[j][z]][l + 1], f[i][j][l]);
                }
    }
    int ans = 0;
    for (int i = 0; i <= k; i++)
        add(ans, f[n][i][0]);
    printf("%d\n", ans);
    return 0;
}