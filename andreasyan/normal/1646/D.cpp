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
vector<int> g[N];

pair<int, ll> dp[N][2];

void dfs(int x, int p)
{
    dp[x][0] = m_p(0, -1);
    dp[x][1] = m_p(1, -sz(g[x]));
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        dfs(h, x);

        dp[x][0].fi += max(dp[h][0], dp[h][1]).fi;
        dp[x][0].se += max(dp[h][0], dp[h][1]).se;

        dp[x][1].fi += dp[h][0].fi;
        dp[x][1].se += dp[h][0].se;
    }
}

int w[N];
void dfs1(int x, int p, bool z)
{
    if (z)
        w[x] = sz(g[x]);
    else
        w[x] = 1;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        if (z)
            dfs1(h, x, false);
        else
        {
            if (dp[h][1] > dp[h][0])
                dfs1(h, x, true);
            else
                dfs1(h, x, false);
        }
    }
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

    if (n == 2)
    {
        cout << "2 2\n1 1\n";
        return;
    }

    dfs(1, 1);
    if (dp[1][1] > dp[1][0])
        dfs1(1, 1, true);
    else
        dfs1(1, 1, false);

    cout << max(dp[1][1], dp[1][0]).fi << ' ' << -max(dp[1][1], dp[1][0]).se << "\n";
    for (int i = 1; i <= n; ++i)
        cout << w[i] << ' ';
    cout << "\n";
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