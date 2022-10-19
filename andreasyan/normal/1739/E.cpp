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
const int N = 200005;

int n;
char a[2][N];

int u[2][N];

int dp[2][N][3];
void solv()
{
    cin >> n;
    for (int i = 0; i < 2; ++i)
        cin >> a[i];

    u[0][n] = u[1][n] = N;
    for (int j = n - 1; j >= 0; --j)
    {
        for (int i = 0; i < 2; ++i)
        {
            u[i][j] = u[i][j + 1];
            if (a[i][j] == '1')
                u[i][j] = j;
        }
    }

    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            for (int z = 0; z < 3; ++z)
                dp[i][j][z] = N * 2;
        }
    }

    int ans = N * 2;
    dp[0][0][0] = 0;
    for (int j = 0; j < n; ++j)
    {
        for (int z = 0; z < 3; ++z)
        {
            for (int i = 0; i < 2; ++i)
            {
                if (dp[i][j][z] == N * 2)
                    continue;
                int x1 = u[i][j + 1];
                int x2 = u[1 - i][j + z];

                if (x1 == N || x2 == N)
                {
                    ans = min(ans, dp[i][j][z]);
                    continue;
                }

                if (x1 - j < x2 - j + 1)
                {
                    dp[i][x1][max(0, z - (x1 - j))] = min(dp[i][x1][max(0, z - (x1 - j))], dp[i][j][z]);
                }
                else if (x1 - j > x2 - j + 1)
                {
                    dp[1 - i][x2][1] = min(dp[1 - i][x2][1], dp[i][j][z]);
                    dp[i][x2][1] = min(dp[i][x2][1], dp[i][j][z] + 1);
                }
                else
                {
                    assert(max(0, z - (x1 - j)) == 0);
                    dp[i][x1][0] = min(dp[i][x1][0], dp[i][j][z] + 1);
                    dp[1 - i][x2][2] = min(dp[1 - i][x2][2], dp[i][j][z] + 1);
                }
            }
        }
    }

    //cout << ans << "\n";
    ans *= -1;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < n; ++j)
            ans += (a[i][j] - '0');
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
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}