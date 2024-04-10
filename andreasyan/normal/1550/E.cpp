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
const int N = 200005, K = 18, INF = 1000000009;

int n, k;
char a[N];

int p[N][K];

int u[N][K];

int dp[(1 << K)];
bool stg(int d)
{
    for (int j = 0; j < k; ++j)
        u[n + 1][j] = INF;
    for (int i = n; i >= 1; --i)
    {
        for (int j = 0; j < k; ++j)
        {
            u[i][j] = u[i + 1][j];
            if (i + d - 1 <= n)
            {
                if (p[i + d - 1][j] - p[i - 1][j] == 0)
                    u[i][j] = i;
            }
        }
    }

    for (int x = 0; x < (1 << k); ++x)
    {
        dp[x] = INF;
    }

    dp[0] = 1;
    for (int x = 1; x < (1 << k); ++x)
    {
        for (int i = 0; i < k; ++i)
        {
            if ((x & (1 << i)))
            {
                int y = (x ^ (1 << i));
                if (dp[y] != INF)
                    dp[x] = min(dp[x], u[dp[y]][i] + d);
            }
        }
    }

    return (dp[(1 << k) - 1] != INF);
}

void solv()
{
    cin >> n >> k;
    cin >> (a + 1);

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < k; ++j)
        {
            p[i][j] = p[i - 1][j];
        }
        if (a[i] == '?')
            continue;
        for (int j = 0; j < k; ++j)
        {
            if (j == a[i] - 'a')
                continue;
            p[i][j]++;
        }
    }

    int l = 1, r = n;
    int ans = 0;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (stg(m))
        {
            ans = m;
            l = m + 1;
        }
        else
            r = m - 1;
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