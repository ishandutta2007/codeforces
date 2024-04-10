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
const int N = 2003, INF = 1000000009;

int n, k;
int a[N];

int dp[N][N];

void solv()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            dp[i][j] = -INF;
        }
    }

    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            if (i - j == a[i])
                dp[i][j] = max(dp[i][j], dp[i - 1][j] + 1);
            else
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            if (j > 0)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
        }
    }

    for (int j = 0; j <= n; ++j)
    {
        if (dp[n][j] >= k)
        {
            cout << j << "\n";
            return;
        }
    }
    cout << "-1\n";
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