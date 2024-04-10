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
const int N = 102, INF = 1000000009;

int n;
int a[N];
int b[N];

int dp[N][N * N];

void minh(int& x, int y)
{
    x = min(x, y);
}

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        cin >> b[i];

    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j < N * N; ++j)
            dp[i][j] = INF;
    }

    dp[0][0] = 0;
    int s = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < N * N; ++j)
        {
            if (dp[i][j] == INF)
                continue;
            minh(dp[i + 1][j + a[i + 1]], dp[i][j] + a[i + 1] * 2 * j + b[i + 1] * 2 * (s - j));
            minh(dp[i + 1][j + b[i + 1]], dp[i][j] + b[i + 1] * 2 * j + a[i + 1] * 2 * (s - j));
        }

        s += a[i + 1];
        s += b[i + 1];
    }

    int ans = INF;
    for (int j = 0; j < N * N; ++j)
        ans = min(ans, dp[n][j]);

    s = 0;
    for (int i = 1; i <= n; ++i)
    {
        ans += s;
        ans += (i - 1) * a[i] * a[i];
        s += a[i] * a[i];
    }

    s = 0;
    for (int i = 1; i <= n; ++i)
    {
        ans += s;
        ans += (i - 1) * b[i] * b[i];
        s += b[i] * b[i];
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
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}