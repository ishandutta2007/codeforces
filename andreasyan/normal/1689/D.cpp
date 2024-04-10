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
const int N = 1003;

int n, m;
char a[N][N];

int dp[N][N];
void clr()
{
    for (int i = 0; i <= n + 1; ++i)
    {
        for (int j = 0; j <= m + 1; ++j)
        {
            dp[i][j] = -N * N;
        }
    }
}

int ans[N][N];

void solv()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> (a[i] + 1);

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            ans[i][j] = -N * N;

    clr();
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (a[i][j] == 'B')
                dp[i][j] = max(dp[i][j], -i -j);

            ans[i][j] = max(ans[i][j], +i +j + dp[i][j]);
        }
    }

    clr();
    for (int i = 1; i <= n; ++i)
    {
        for (int j = m; j >= 1; --j)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i][j + 1]);
            if (a[i][j] == 'B')
                dp[i][j] = max(dp[i][j], -i +j);

            ans[i][j] = max(ans[i][j], +i -j + dp[i][j]);
        }
    }

    clr();
    for (int i = n; i >= 1; --i)
    {
        for (int j = 1; j <= m; ++j)
        {
            dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            if (a[i][j] == 'B')
                dp[i][j] = max(dp[i][j], +i -j);

            ans[i][j] = max(ans[i][j], -i +j + dp[i][j]);
        }
    }

    clr();
    for (int i = n; i >= 1; --i)
    {
        for (int j = m; j >= 1; --j)
        {
            dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            if (a[i][j] == 'B')
                dp[i][j] = max(dp[i][j], +i +j);

            ans[i][j] = max(ans[i][j], -i -j + dp[i][j]);
        }
    }

    int minu = ans[1][1];
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            minu = min(minu, ans[i][j]);
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (minu == ans[i][j])
            {
                cout << i << ' ' << j << "\n";
                return;
            }
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
    {
        solv();
    }
    return 0;
}