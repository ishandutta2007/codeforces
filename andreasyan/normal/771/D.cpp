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
const int N = 80, INF = 1000000009;

int n;
char a[N];

int dp[N][N][N][3];

void solv()
{
    scanf("%d", &n);
    scanf(" %s", (a + 1));
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == 'V')
            a[i] = 0;
        else if (a[i] == 'K')
            a[i] = 1;
        else
            a[i] = 2;
    }
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            for (int k = 0; k < N; ++k)
            {
                for (int v = 0; v < 3; ++v)
                {
                    dp[i][j][k][v] = INF;
                }
            }
        }
    }
    dp[0][0][0][2] = 0;

    vector<int> ve[3];
    int q[3] = {};
    for (int i = 1; i <= n; ++i)
    {
        q[a[i]]++;
        ve[a[i]].push_back(i);
    }

    int i[3];
    for (i[0] = 0; i[0] <= q[0]; ++i[0])
    {
        for (i[1] = 0; i[1] <= q[1]; ++i[1])
        {
            for (i[2] = 0; i[2] <= q[2]; ++i[2])
            {
                for (int v = 0; v < 3; ++v)
                {
                    if (dp[i[0]][i[1]][i[2]][v] == INF)
                        continue;
                    for (int u = 0; u < 3; ++u)
                    {
                        if (v == 0 && u == 1)
                            continue;
                        if (i[u] + 1 > q[u])
                            continue;
                        int j = ve[u][i[u]];
                        int qq[3] = {};
                        for (int k = 1; k < j; ++k)
                        {
                            qq[a[k]]++;
                        }
                        int d = j - 1 - min(i[0], qq[0]) - min(i[1], qq[1]) - min(i[2], qq[2]);
                        if (u == 0)
                            dp[i[0] + 1][i[1]][i[2]][u] = min(dp[i[0] + 1][i[1]][i[2]][u], dp[i[0]][i[1]][i[2]][v] + d);
                        else if (u == 1)
                            dp[i[0]][i[1] + 1][i[2]][u] = min(dp[i[0]][i[1] + 1][i[2]][u], dp[i[0]][i[1]][i[2]][v] + d);
                        else if (u == 2)
                            dp[i[0]][i[1]][i[2] + 1][u] = min(dp[i[0]][i[1]][i[2] + 1][u], dp[i[0]][i[1]][i[2]][v] + d);
                    }
                }
            }
        }
    }
    printf("%d\n", min(min(dp[q[0]][q[1]][q[2]][0], dp[q[0]][q[1]][q[2]][1]), dp[q[0]][q[1]][q[2]][2]));
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}