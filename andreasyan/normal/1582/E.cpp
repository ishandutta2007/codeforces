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
const int N = 100005, K = 500;
const ll INF = 1000000009000000009;

int n;
int a[N];

ll p[N];

ll dp[N][K];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i <= n; ++i)
        p[i] = p[i - 1] + a[i];

    for (int i = 1; i <= n + 1; ++i)
    {
        for (int j = 0; j < K; ++j)
            dp[i][j] = -INF;
    }

    dp[n + 1][0] = INF;

    for (int i = n; i >= 1; --i)
    {
        for (int j = 0; j < K; ++j)
            dp[i][j] = dp[i + 1][j];
        for (int j = 0; j < K - 1; ++j)
        {
            if (i + (j + 1) - 1 <= n)
            {
                if (p[i + (j + 1) - 1] - p[i - 1] < dp[i + (j + 1)][j])
                {
                    dp[i][j + 1] = max(dp[i][j + 1], p[i + (j + 1) - 1] - p[i - 1]);
                }
            }
        }
    }

    for (int k = K - 1; k >= 0; --k)
    {
        if (dp[1][k] != -INF)
        {
            cout << k << "\n";
            return;
        }
    }
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
        solv();
    return 0;
}