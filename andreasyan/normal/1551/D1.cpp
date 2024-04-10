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
const int N = 102;

bool dp[N][N][N * N];
void pre()
{
    for (int i = 0; i < N; ++i)
        dp[i][0][0] = dp[0][i][0] = true;
    for (int n = 1; n < N; ++n)
    {
        for (int m = 1; m < N; ++m)
        {
            for (int k = 0; k <= n * m / 2; ++k)
            {
                int kk = n * m / 2 - k;

                if (m % 2 == 0 && k >= m / 2)
                    dp[n][m][k] |= dp[n - 1][m][k - m / 2];
                if (n % 2 == 0 && kk >= n / 2)
                    dp[n][m][k] |= dp[n][m - 1][k];
                if (n % 2 + m % 2 == 1 && k >= m / 2 && kk >= n / 2)
                    dp[n][m][k] |= dp[n - 1][m - 1][k - m / 2];
            }
        }
    }
}

int n, m, k;

void solv()
{
    cin >> n >> m >> k;

    if (dp[n][m][k])
        cout << "YES\n";
    else
        cout << "NO\n";
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