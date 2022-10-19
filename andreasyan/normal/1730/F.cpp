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
const int N = 5003;

int n, k;
int a[N];

int u[N];
int qq[N];
int q[N][N];

int dp[N][(1 << 8)];
void solv()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i <= n; ++i)
    {
        u[a[i]] = i;
        for (int j = 1; j <= n; ++j)
            q[a[i]][j] = qq[j];
        for (int j = a[i] + 1; j <= n; ++j)
            qq[j]++;
    }

    for (int f = 1; f <= n; ++f)
    {
        for (int x = 0; x < (1 << k); ++x)
            dp[f][x] = N * N;
    }
    int x = 0;
    for (int t = 0; 1 + 1 + t <= n && t < k; ++t)
        x |= (1 << t);
    dp[1][x] = 0;

    int ans = N * N;
    for (int i = 1; i <= n; ++i)
    {
        for (int f = max(1, i - k - 1); f <= i; ++f)
        {
            for (int x = 0; x < (1 << k); ++x)
            {
                if (dp[f][x] == N * N)
                    continue;
                int qt = f - 1;
                for (int t = 0; f + 1 + t <= n && t < k; ++t)
                {
                    if (!(x & (1 << t)))
                        ++qt;
                }
                if (qt != i - 1)
                    continue;
                int r = min(n, f + k);

                for (int t = 0; f + 1 + t <= n && t < k; ++t)
                {
                    if (!(x & (1 << t)))
                        continue;
                    int p = u[f + 1 + t] - 1 - q[f + 1 + t][f];
                    for (int t1 = 0; f + 1 + t1 <= n && t1 < k; ++t1)
                    {
                        if ((x & (1 << t1)))
                            continue;
                        if (u[f + 1 + t1] < u[f + 1 + t])
                            --p;
                    }
                    dp[f][(x ^ (1 << t))] = min(dp[f][(x ^ (1 << t))], dp[f][x] + p);
                }
                int p = u[f] - 1 - q[f][f];
                for (int t1 = 0; f + 1 + t1 <= n && t1 < k; ++t1)
                {
                    if ((x & (1 << t1)))
                        continue;
                    if (u[f + 1 + t1] < u[f])
                        --p;
                }
                int f1 = 0;
                for (int t = 0; f + 1 + t <= n && t < k; ++t)
                {
                    if ((x & (1 << t)))
                    {
                        f1 = f + 1 + t;
                        break;
                    }
                }
                if (!f1)
                {
                    if (r + 1 > n)
                        ans = min(ans, dp[f][x] + p);
                    else
                    {
                        f1 = r + 1;
                        int y = 0;
                        for (int t = 0; f1 + 1 + t <= n && t < k; ++t)
                        {
                            y |= (1 << t);
                        }
                        dp[f1][y] = min(dp[f1][y], dp[f][x] + p);
                    }
                }
                else
                {
                    int y = 0;
                    for (int t = 0; f1 + 1 + t <= n && t < k; ++t)
                    {
                        if (f1 + 1 + t <= r)
                        {
                            if ((x & (1 << (f1 + 1 + t - f - 1))))
                                y |= (1 << t);
                        }
                        else
                            y |= (1 << t);
                    }
                    dp[f1][y] = min(dp[f1][y], dp[f][x] + p);
                }
            }
        }
    }

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