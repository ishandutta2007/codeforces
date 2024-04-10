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
const int N = 1003, M = 1000000007;

int n;
ll l, r, z;

void ph(int& x, int y)
{
    x = (x + y) % M;
}

int dp[N * 2][2];
int ndp[N * 2][2];
int P(ll x)
{
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    for (int i = 59; i >= 0; --i)
    {
        if ((x & (1LL << i)))
        {
            ph(dp[n * 2][0], dp[n * 2 - 1][0]);
            ph(dp[n * 2][1], dp[n * 2 - 1][1]);
            for (int j = n * 2 - 1; j >= 1; --j)
            {
                dp[j][0] = dp[j - 1][0];
                dp[j][1] = dp[j - 1][1];
            }
            dp[0][0] = 0;
            dp[0][1] = 0;
        }

        for (int ii = 1; ii <= n; ++ii)
        {
            for (int j = 1; j <= n * 2; ++j)
            {
                ph(dp[j - 1][0], dp[j][1]);
                ph(dp[j - 1][1], dp[j][0]);
            }
        }

        if ((z & (1LL << i)))
        {
            for (int j = 0; j <= n * 2; ++j)
            {
                dp[j][0] = 0;
            }
        }
        else
        {
            for (int j = 0; j <= n * 2; ++j)
            {
                dp[j][1] = 0;
            }
        }

        memset(ndp, 0, sizeof ndp);
        for (int j = 0; j <= n * 2; ++j)
        {
            ph(ndp[min(j * 2, n * 2)][0], dp[j][0]);
            ph(ndp[min(j * 2, n * 2)][0], dp[j][1]);
        }
        memcpy(dp, ndp, sizeof ndp);
    }

    int ans = 0;
    for (int j = 0; j <= n * 2; ++j)
    {
        ph(ans, dp[j][0]);
        ph(ans, dp[j][1]);
    }

    return ans;
}

void solv()
{
    cin >> n >> l >> r >> z;

    cout << (P(r) - P(l - 1) + M) % M << "\n";
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