#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;


const int MAXN = 16;
const int MAXK = 1 << MAXN;

int n, k;
int c[MAXK];
int v[MAXN][MAXN];
int e[MAXN], a[MAXN], d[MAXN];
long long f[MAXK];
long long m;

bool debug;

long long F(int I, int J)
{
    memset(f, 0, sizeof(f));
    f[(1 << I) - 1] = 1;
    for (int i = 0; i < (1 << n); i++)
    {
        if (f[i] == 0) continue;

        int x = c[i] - I;
        if (x >= J) x++;
        x = d[x];

        for (int j = I; j < n; j++)
            if ((i & (1 << j)) == 0)
            {
                if ((e[j] & i) & ((1 << n) - (1 << I))) continue;

                bool flag = true;
                for (int k = 0; k < I; k++)
                    if (v[k][j] && a[k] > x || v[j][k] && x > a[k])
                    {
                        flag = false;
                        break;
                    }

                if (!flag) continue;
                f[i | (1 << j)] += f[i];
            }
    }
    return f[(1 << n) - 1];
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        v[a][b] = 1;
        e[a] |= 1 << b;
    }

    for (int i = 1; i < MAXK; i++)
        c[i] = c[i >> 1] + (i & 1);

    m -= 2000;

    if (F(0, -1) < m)
    {
        puts("The times have changed");
        return 0;
    }


    for (int i = 0; i < n; i++)
        d[i] = i + 1;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - i; j++)
        {
            a[i] = d[j];

            bool flag = true;
            for (int k = 0; k < i; k++)
                if (v[k][i] && a[k] > a[i] || v[i][k] && a[i] > a[k])
                {
                    flag = false;
                    break;
                }
            if (!flag) continue;

            long long x = F(i + 1, j);
            if (x >= m)
            {
                for (int k = j + 1; k < n - i; k++)
                    d[k - 1] = d[k];
                break;
            }
            m -= x;
        }

    for (int i = 0; i < n; i++)
    {
        if (i) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");

    return 0;
}