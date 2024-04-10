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
const int N = 2003, M = 1000000007;

int ast(int x, int n)
{
    int ans = 1;
    while (n)
    {
        if (n % 2 == 1)
            ans = (ans * 1LL * x) % M;
        x = (x * 1LL * x) % M;
        n /= 2;
    }
    return ans;
}

int n, m, k;
int dp[N][N];

void solv()
{
    cin >> n >> m >> k;
    m = n - m;

    int r2 = ast(2, M - 2);

    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            if (j == 0)
                dp[i][j] = (k * 1LL * i) % M;
            else
                dp[i][j] = ((dp[i - 1][j - 1] + dp[i - 1][j]) * 1LL * r2) % M;

            /*if (j == 0)
                dp[i][j] = k * i;
            else
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) / 2;*/
        }
    }

    cout << (dp[n][m] + M) % M << "\n";
    //cout << dp[n][m] << "\n";
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