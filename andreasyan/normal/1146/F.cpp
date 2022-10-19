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
const int N = 200005, M = 998244353;

int n;
int p[N];
vector<int> g[N];

int dp[N][2];

void dfs(int x)
{
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        dfs(h);
    }

    if (g[x].empty())
    {
        dp[x][0] = dp[x][1] = 1;
        return;
    }

    int yans = 1;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        int yyans = (yans * 1LL * dp[h][0] + yans * 1LL * dp[h][1]) % M;
        yans = yyans;
    }

    dp[x][0] = dp[x][1] = yans;

    yans = 1;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];

        yans = (yans * 1LL * dp[h][0]) % M;
    }
    dp[x][1] = (dp[x][1] - yans + M) % M;

    vector<int> s(sz(g[x]));
    for (int i = sz(g[x]) - 1; i >= 0; --i)
    {
        int h = g[x][i];

        s[i] = dp[h][0];
        if (i + 1 < sz(g[x]))
            s[i] = (s[i] * 1LL * s[i + 1]) % M;
    }

    int pp = 1;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];

        int yans = dp[h][1];
        if (i + 1 < sz(g[x]))
            yans = (yans * 1LL * s[i + 1]) % M;
        yans = (yans * 1LL * pp) % M;

        dp[x][0] = (dp[x][0] - yans + M) % M;

        pp = (pp * 1LL * dp[h][0]) % M;
    }
}

void solv()
{
    cin >> n;
    for (int x = 2; x <= n; ++x)
        cin >> p[x];

    for (int x = 2; x <= n; ++x)
        g[p[x]].push_back(x);

    dfs(1);

    cout << dp[1][0] << "\n";
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