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
const int N = 202, M = 998244353;

int c[N][N];
void pre()
{
    for (int i = 0; i < N; ++i)
    {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % M;
    }
}

int n;
int dp[N][3];

void solv()
{
    cin >> n;

    dp[1][1] = 1;
    dp[1][2] = 0;
    dp[1][0] = 1;
    for (int i = 2; i <= n / 2; ++i)
    {
        dp[i][1] = c[2 * i - 1][i];
        dp[i][2] = c[2 * i - 2][i];
        dp[i][0] = 0;

        dp[i][1] = (dp[i][1] + dp[i - 1][2]) % M;
        dp[i][2] = (dp[i][2] + dp[i - 1][1]) % M;
        dp[i][0] = (dp[i][0] + dp[i - 1][0]) % M;
    }

    cout << dp[n / 2][1] << ' ' << dp[n / 2][2] << ' ' << dp[n / 2][0] << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    pre();

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}