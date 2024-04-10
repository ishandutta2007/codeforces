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
const int N = 503;

int n, M;

void ph(int& x, ll y)
{
    x = (x + y) % M;
}

int dp[N * N * 2][2];
int ndp[N * N * 2][2];

int p[N * N * 2][2];
int h[N * N * 2][2];

void solv()
{
    cin >> n >> M;

    dp[N * N][0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        memset(ndp, 0, sizeof ndp);

        memset(p, 0, sizeof p);
        memset(h, 0, sizeof h);

        for (int t = N * N - i * (i - 1) / 2; t <= N * N + i * (i - 1) / 2; ++t)
        {
            for (int z = 0; z < 2; ++z)
            {
                if (dp[t][z])
                {
                    ph(ndp[t][z], dp[t][z] * 1LL * i);

                    ph(p[t - i][0], dp[t][z]);
                    ph(p[t - 1][0], M - dp[t][z]);
                    ph(h[t - 1][0], dp[t][z] * 1LL * (i - 1));

                    ph(p[t + i][1], dp[t][z]);
                    ph(p[t + 1][1], M - dp[t][z]);
                    ph(h[t + 1][1], dp[t][z] * 1LL * (i - 1));

                    /*for (int x = 1; x <= i; ++x)
                    {
                        for (int y = 1; y <= i; ++y)
                        {
                            if (x < y)
                                ph(ndp[t + x - y][0], dp[t][z]);
                            else if (x == y)
                                ph(ndp[t + x - y][z], dp[t][z]);
                            else
                                ph(ndp[t + x - y][1], dp[t][z]);
                        }
                    }*/
                }
            }
        }

        int u = 0;
        int s = 0;
        for (int t = N * N - i * (i + 1) / 2; t <= N * N + i * (i + 1) / 2; ++t)
        {
            ph(s, u);

            ph(ndp[t][0], s);

            ph(u, p[t][0]);
            ph(s, M - h[t][0]);
        }

        u = 0;
        s = 0;
        for (int t = N * N + i * (i + 1) / 2; t >= N * N - i * (i + 1) / 2; --t)
        {
            ph(s, u);

            ph(ndp[t][1], s);

            ph(u, p[t][1]);
            ph(s, M - h[t][1]);
        }

        memcpy(dp, ndp, sizeof ndp);
    }

    int ans = 0;
    for (int t = N * N + 1; t < N * N * 2; ++t)
        ph(ans, dp[t][0]);

    cout << ans << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}