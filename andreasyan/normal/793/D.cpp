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
const int N = 82, INF = 1000000009;

int n, k;
vector<pair<int, int> > g[N];

int dp[2][N][N][N];
bool c[2][N][N][N];

int rec(int z, int u, int x, int k)
{
    if (k == 0)
        return 0;
    if (c[z][u][x][k])
        return dp[z][u][x][k];
    c[z][u][x][k] = true;
    dp[z][u][x][k] = INF;
    for (int i = 0; i < sz(g[x]); ++i)
    {
        int h = g[x][i].fi;
        int d = g[x][i].se;
        if (z == 0)
        {
            if (u <= h && h < x)
            {
                dp[z][u][x][k] = min(dp[z][u][x][k], rec(0, u, h, k - 1) + d);
                dp[z][u][x][k] = min(dp[z][u][x][k], rec(1, x - 1, h, k - 1) + d);
            }
        }
        else
        {
            if (x < h && h <= u)
            {
                dp[z][u][x][k] = min(dp[z][u][x][k], rec(1, u, h, k - 1) + d);
                dp[z][u][x][k] = min(dp[z][u][x][k], rec(0, x + 1, h, k - 1) + d);
            }
        }
    }
    return dp[z][u][x][k];
}

void solv()
{
    cin >> n >> k;
    int m;
    cin >> m;
    while (m--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        g[x].push_back(m_p(y, z));
    }

    int ans = INF;
    for (int i = 1; i <= n; ++i)
    {
        ans = min(ans, rec(0, 1, i, k - 1));
        ans = min(ans, rec(1, n, i, k - 1));
    }

    if (ans == INF)
        cout << "-1\n";
    else
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