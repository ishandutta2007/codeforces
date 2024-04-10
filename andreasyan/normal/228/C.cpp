#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 503;
const int xx[4] = {0, 0, 1, 1};
const int yy[4] = {0, 1, 0, 1};

int n, m;
char a[N][N];

int f[N][N][10];

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf(" %s", (a[i] + 1));
    for (int k = 1; k < 10; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                f[i][j][k] = -1;
                if (i + (1 << k) - 1 > n || j + (1 << k) - 1 > m)
                    continue;
                if (i == 3 && j == 1)
                    cout << "";
                if (k == 1)
                {
                    int x = 0;
                    for (int u = 0; u < 4; ++u)
                    {
                        if (a[i + xx[u]][j + yy[u]] == '*')
                            x |= (1 << u);
                    }
                    f[i][j][k] = x;
                }
                else
                {
                    for (int x = 0; x < (1 << 4); ++x)
                    {
                        bool z = true;
                        for (int u = 0; u < 4; ++u)
                        {
                            if ((x & (1 << u)))
                            {
                                if (f[i + xx[u] * (1 << (k - 1))][j + yy[u] * (1 << (k - 1))][k - 1] != (1 << 4) - 1)
                                {
                                    z = false;
                                    break;
                                }
                            }
                            else
                            {
                                if (f[i + xx[u] * (1 << (k - 1))][j + yy[u] * (1 << (k - 1))][k - 1] != x)
                                {
                                    z = false;
                                    break;
                                }
                            }
                        }
                        if (z)
                        {
                            f[i][j][k] = x;
                            break;
                        }
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            for (int k = 2; k < 10; ++k)
            {
                if (f[i][j][k] != -1)
                    ++ans;
            }
        }
    }
    printf("%d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}