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
const int N = 4000006;

int n, M;

int dp[N];
int p[N];

void solv()
{
    cin >> n >> M;

    int s = 0;
    int u = 0;
    for (int i = 1; i <= n; ++i)
    {
        u = (u + p[i]) % M;
        dp[i] = (dp[i] + u) % M;

        if (i == 1)
            dp[i] = 1;
        else
            dp[i] = (dp[i] + s) % M;
        s = (s + dp[i]) % M;

        for (int x = 2; ; ++x)
        {
            if (i * x > n)
                break;
            p[i * x] = (p[i * x] + dp[i]) % M;
            if (i * x + x <= n)
                p[i * x + x] = (p[i * x + x] - dp[i] + M) % M;
        }
    }

    cout << dp[n] << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    /*ll ans = 0;
    for (int i = 1; i < N; ++i)
    {
        for (int x = 2; ; ++x)
        {
            if (i * x >= N)
                break;
            ++ans;
        }
    }
    cout << ans << "\n";
    return 0;*/

    int tt = 1;
    //cin >> tt;
    while (tt--)
        solv();
    return 0;
}