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
const int N = 2003, INF = 1000000009;

int n, m;
int l[N];
int s[N];
int c[N * 2];

int dp[N + N][N];
int dp0[N + N];

void maxh(int& x, int y)
{
    x = max(x, y);
}

void solv()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> l[i];
    for (int i = 1; i <= n; ++i)
        cin >> s[i];
    for (int i = 1; i <= n + m; ++i)
        cin >> c[i];

    for (int j = 1; j <= n + m; ++j)
    {
        for (int q = 1; q <= n; ++q)
            dp[j][q] = -INF;
    }
    for (int j = 1; j <= n + m; ++j)
        dp0[j] = 0;
    for (int i = n; i >= 1; --i)
    {
        maxh(dp[l[i]][0], dp0[l[i]]);
        for (int q = n; q >= 1; --q)
        {
            maxh(dp[l[i]][q], dp[l[i]][q - 1] - s[i] + c[l[i]]);
            int ydp = dp[l[i]][q];
            int qq = q;
            for (int j = l[i] + 1; j <= n + m; ++j)
            {
                qq /= 2;
                ydp += qq * c[j];
                maxh(dp[j][qq], ydp);
                if (qq == 0)
                {
                    maxh(dp0[j], ydp);
                    break;
                }
            }
        }
        for (int j = 1; j <= n; ++j)
            maxh(dp0[j], dp0[j - 1]);
    }

    int ans = 0;
    for (int j = 1; j <= n + m; ++j)
    {
        maxh(ans, dp[j][0]);
        maxh(ans, dp[j][1]);
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