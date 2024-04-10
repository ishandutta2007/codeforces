#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 402, M = 998244353;

int n;

int dp[N][N][4][4];
int ndp[N][N][4][4];
int dp1[N][N][3][3];
int dp2[N][2][2];

void ph(int& x, int y)
{
    x = (x + y) % M;
}

void pre()
{
    dp[0][0][0][0] = 1;
    for (int i = 0; i < n; ++i)
    {
        memset(ndp, 0, sizeof ndp);
        int u = min(i, (i / 2) + 2);
        for (int q1 = 0; q1 <= u; ++q1)
        {
            for (int q2 = 0; q2 <= u; ++q2)
            {
                for (int nv = 0; nv < 4; ++nv)
                {
                    for (int v = 0; v < 4; ++v)
                    {
                        {
                            if (nv != 1)
                            {
                                ph(ndp[q1 + 1][q2][v][1], dp[q1][q2][nv][v]);
                            }
                        }
                        {
                            if (nv != 2)
                            {
                                ph(ndp[q1][q2 + 1][v][2], dp[q1][q2][nv][v]);
                            }
                        }
                        {
                            if (nv != 3)
                            {
                                ph(ndp[q1][q2][v][3], dp[q1][q2][nv][v] * 24LL % M);
                            }
                            else
                            {
                                ph(ndp[q1][q2][v][3], dp[q1][q2][nv][v] * 23LL % M);
                            }
                        }
                    }
                }
            }
        }
        memcpy(dp, ndp, sizeof ndp);
    }

    dp1[0][0][0][0] = 1;
    for (int i = 0; i < n; ++i)
    {
        for (int q1 = 0; q1 <= i; ++q1)
        {
            for (int nv = 0; nv < 3; ++nv)
            {
                for (int v = 0; v < 3; ++v)
                {
                    {
                        if (nv != 1)
                        {
                            ph(dp1[i + 1][q1 + 1][v][1], dp1[i][q1][nv][v]);
                        }
                    }
                    {
                        if (nv != 2)
                        {
                            ph(dp1[i + 1][q1][v][2], dp1[i][q1][nv][v] * 25LL % M);
                        }
                        else
                        {
                            ph(dp1[i + 1][q1][v][2], dp1[i][q1][nv][v] * 24LL % M);
                        }
                    }
                }
            }
        }
    }

    dp2[0][0][0] = 1;
    for (int i = 0; i < n; ++i)
    {
        for (int nv = 0; nv < 2; ++nv)
        {
            for (int v = 0; v < 2; ++v)
            {
                {
                    if (nv != 1)
                    {
                        ph(dp2[i + 1][v][1], dp2[i][nv][v] * 26LL % M);
                    }
                    else
                    {
                        ph(dp2[i + 1][v][1], dp2[i][nv][v] * 25LL % M);
                    }
                }
            }
        }
    }
}

int q[30];

int ans2[30][30];
int ans1[30];
int ans0;

int p[N][N];
void solv()
{
    scanf("%d", &n);
    pre();

    for (int i = 1; i <= 26; ++i)
        scanf("%d", &q[i]);

    for (int q1 = (n / 3) + 1; q1 <= n; ++q1)
    {
        for (int q2 = (n / 3) + 1; q2 <= n; ++q2)
        {
            ph(p[q1][q2], p[q1 - 1][q2]);
            ph(p[q1][q2], p[q1][q2 - 1]);
            ph(p[q1][q2], (M - p[q1 - 1][q2 - 1]) % M);
            for (int nv = 0; nv < 4; ++nv)
            {
                for (int v = 0; v < 4; ++v)
                {
                    ph(p[q1][q2], dp[q1][q2][nv][v]);
                }
            }
        }
    }

    for (int i = 1; i <= 26; ++i)
    {
        for (int j = 1; j <= 26; ++j)
        {
            if (i == j)
                continue;
            /*for (int q1 = (n / 3) + 1; q1 <= q[i]; ++q1)
            {
                for (int q2 = (n / 3) + 1; q2 <= q[j]; ++q2)
                {
                    for (int nv = 0; nv < 4; ++nv)
                    {
                        for (int v = 0; v < 4; ++v)
                        {
                            ph(ans2[i][j], dp[q1][q2][nv][v]);
                        }
                    }
                }
            }*/
            ans2[i][j] = p[q[i]][q[j]];
        }
    }

    for (int i = 1; i <= 26; ++i)
    {
        for (int q1 = (n / 3) + 1; q1 <= q[i]; ++q1)
        {
            for (int nv = 0; nv < 3; ++nv)
            {
                for (int v = 0; v < 3; ++v)
                {
                    ph(ans1[i], dp1[n][q1][nv][v]);
                }
            }
        }
        int s = 0;
        //for (int j = 1; j <= 26; ++j)
        {
            //if (i == j)
            //    continue;
            for (int q1 = (n / 3) + 1; q1 <= q[i]; ++q1)
            {
                for (int q2 = (n / 3) + 1; q2 <= n; ++q2)
                {
                    for (int nv = 0; nv < 4; ++nv)
                    {
                        for (int v = 0; v < 4; ++v)
                        {
                            ph(s, (M - dp[q1][q2][nv][v]) % M);
                        }
                    }
                }
            }
        }
        ph(ans1[i], s * 25LL % M);
    }

    for (int nv = 0; nv < 2; ++nv)
        for (int v = 0; v < 2; ++v)
            ph(ans0, dp2[n][nv][v]);
    for (int i = 1; i <= 26; ++i)
    {
        for (int q1 = n / 3 + 1; q1 <= n; ++q1)
        {
            for (int nv = 0; nv < 3; ++nv)
            {
                for (int v = 0; v < 3; ++v)
                {
                    ph(ans0, (M - dp1[n][q1][nv][v]) % M);
                }
            }
        }
    }
    for (int i = 1; i <= 26; ++i)
    {
        for (int j = i + 1; j <= 26; ++j)
        {
            for (int q1 = n / 3 + 1; q1 <= n; ++q1)
            {
                for (int q2 = n / 3 + 1; q2 <= n; ++q2)
                {
                    for (int nv = 0; nv < 4; ++nv)
                    {
                        for (int v = 0; v < 4; ++v)
                        {
                            ph(ans0, dp[q1][q2][nv][v]);
                        }
                    }
                }
            }
        }
    }

    int ans = ans0;
    for (int i = 1; i <= 26; ++i)
        ph(ans, ans1[i]);
    for (int i = 1; i <= 26; ++i)
    {
        for (int j = i + 1; j <= 26; ++j)
        {
            ph(ans, ans2[i][j]);
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
    //ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    //scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}