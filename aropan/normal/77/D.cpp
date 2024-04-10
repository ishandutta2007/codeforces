#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 255;
const int MOD = 1000000007;

int n, m;

char s[MAXN * 5][MAXN * 5];

char d[3][3];
int a[MAXN][MAXN];
int t[MAXN][MAXN];

long long g[MAXN][2];
long long f[MAXN];

          
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "rt", stdin);
        freopen("out", "wt", stdout);
    #endif
    scanf("%d %d\n", &n, &m);
    for (int i = 0; i <= 4 * n; i++)
        gets(s[i]);


    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            a[i][j] = 0;
            for (int x = 0; x < 3; x++)
                for (int y = 0; y < 3; y++)
                {
                    d[x][y] = s[i * 4 + 1 + x][j * 4 + 1 + y];
                    a[i][j] += d[x][y] == 'O';
                }
            t[i][j] = 3;

            if (a[i][j] == 2 || a[i][j] == 3 || a[i][j] == 6)
            {
                t[i][j] = 1 << (int)(
                    a[i][j] == 2 && d[0][2] == 'O' ||
                    a[i][j] == 3 && d[0][2] == 'O' ||
                    a[i][j] == 6 && d[1][0] == 'O'
                );
            }
        }

    for (int j = 0; j < m; j++)
    {
        g[j][0] = (n & 1) == 0;
        for (int i = 0; i < n; i++)
            if ((t[i][j] & 2) == 0)
            {
                g[j][0] = 0;
                break;
            }
    }

    for (int j = 0; j < m; j++)
    {
        long long f[MAXN];
        memset(f, 0, sizeof(f));

        f[0] = 1;
        for (int i = 0; i <= n; i++)
        {
            f[i] %= MOD;
            if ((t[i][j] & 1) && (t[i][j + 1] & 1))
                f[i + 1] += f[i];

            if ((t[i][j] & 2) && (t[i + 1][j] & 2) && (t[i][j + 1] & 2) && (t[i + 1][j + 1] & 2))
                f[i + 2] += f[i];
        }
        g[j][1] = (f[n] - (g[j][0] & g[j + 1][0]) + MOD) % MOD;
    }


    memset(f, 0, sizeof(f));
    f[0] = 1;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < 2; j++)
            f[i + j + 1] = (f[i + j + 1] + f[i] * g[i][j]) % MOD;

    printf("%d\n", (int)f[m]);
/*
    for (int i = 0; i < n; i++, printf("\n"))
        for (int j = 0; j < m; j++)
            printf("%d" , t[i][j]);
    printf("\n");

    for (int i = 0; i < 2; i++, printf("\n"))
        for (int j = 0; j < m; j++)
            printf("%d" , (int)g[j][i]);
    printf("\n");
//*/
    return 0;
}