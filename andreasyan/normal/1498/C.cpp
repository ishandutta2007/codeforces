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

int n, k;
int dp[N][N];

void solv()
{
    cin >> n >> k;
    for (int i = 1; i <= n + 1; ++i)
        dp[i][1] = 1;
    for (int j = 2; j <= k; ++j)
    {
        dp[n + 1][j] = 1;
        for (int i = n; i >= 1; --i)
        {
            dp[i][j] = (dp[i + 1][j] + dp[n - i + 2][j - 1]) % M;
        }
    }
    cout << dp[1][k] << "\n";
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