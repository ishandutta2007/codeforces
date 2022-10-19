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
const int N = 105, K = 1003, M = 1000000007, NN = N * K * 4, Z = NN / 2;

int a, b, k, t;

int dp[NN];
int p[NN];

void solv()
{
    scanf("%d%d%d%d", &a, &b, &k, &t);
    dp[Z + a - b] = 1;
    k *= 2;
    while (t--)
    {
        for (int i = 1; i < NN; ++i)
            p[i] = (p[i - 1] + dp[i]) % M;
        memset(dp, 0, sizeof dp);

        int s = 0;
        for (int i = k + 2; i < NN - 2; ++i)
        {
            dp[i] = (dp[i] + s) % M;
            s -= (p[i] - p[i - k - 1] + M) % M;
            s = (s + M) % M;
            s += ((p[i + 1] - p[i] + M) % M * 1LL * (k + 1)) % M;
            s %= M;
        }
         s = 0;
        for (int i = NN - k - 2; i >= 2; --i)
        {
            dp[i] = (dp[i] + s) % M;
            s -= (p[i + k] - p[i - 1] + M) % M;
            s = (s + M) % M;
            s += ((p[i - 1] - p[i - 2] + M) % M * 1LL * (k + 1)) % M;
            s %= M;
        }
        for (int i = 1; i < NN; ++i)
            dp[i] = (dp[i] - ((p[i] - p[i - 1]) * 1LL * (k + 1)) % M + M) % M;
    }
    int ans = 0;
    for (int i = Z + 1; i < NN; ++i)
        ans = (ans + dp[i]) % M;
    printf("%d\n", ans);
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