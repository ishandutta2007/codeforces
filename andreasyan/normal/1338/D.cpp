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
const int N = 100005, INF = 1000000009;

int n;
vector<int> g[N];

int dp[N][2];

int ans;
void dfs(int x, int p)
{
    dp[x][0] = dp[x][1] = 0;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        dfs(h, x);
        dp[x][1] = max(dp[x][1], max(dp[h][0], dp[h][1]));
        dp[x][0] = max(dp[x][0], max(dp[h][0] - 1, dp[h][1]) + sz(g[x]) - (x != p));
    }

    int max1 = -INF, max2 = -INF;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        int u = max(dp[h][1], dp[h][0] - 1);
        if (u >= max1)
        {
            max2 = max1;
            max1 = u;
        }
        else if (u >= max2)
        {
            max2 = u;
        }
    }
    ans = max(ans, sz(g[x]) + max1);
    ans = max(ans, sz(g[x]) + max1 + max2);
}

void solv()
{
    cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    ans = 0;
    dfs(1, 1);
    dfs(n, n);
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