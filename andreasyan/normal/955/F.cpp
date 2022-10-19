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
const int N = 300005;

int n;
vector<int> g[N];

ll ans;

const int m = 22;
int dp[N][m];
int maxu[N][m];
void dfs(int x, int p)
{
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        dfs(h, x);
        for (int j = 2; j < m; ++j)
        {
            maxu[x][j] = max(maxu[x][j], maxu[h][j]);
        }
    }
    dp[x][2] = sz(g[x]) - 1;
    if (x == p)
        ++dp[x][2];
    for (int j = 3; j < m; ++j)
    {
        vector<int> v;
        for (int i = 0; i < g[x].size(); ++i)
        {
            int h = g[x][i];
            if (h == p)
                continue;
            v.push_back(dp[h][j - 1]);
        }
        sort(all(v));
        reverse(all(v));
        for (int i = sz(v) - 1; i >= 0; --i)
        {
            if (v[i] >= i + 1)
            {
                dp[x][j] = i + 1;
                break;
            }
        }
    }
    for (int j = 2; j < m; ++j)
        maxu[x][j] = max(maxu[x][j], dp[x][j]);

    for (int j = m - 1; j >= 2; --j)
    {
        if (!maxu[x][j])
            continue;
        if (!maxu[x][j + 1])
            ans += ((j - 1) * 1LL * (maxu[x][j] - 1));
        else
            ans += ((j - 1) * 1LL * (maxu[x][j] - maxu[x][j + 1]));
    }
}

int d[N];
void dfs1(int x, int p)
{
    d[x] = 1;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        dfs1(h, x);
        d[x] = max(d[x], d[h] + 1);
    }
}

void solv()
{
    cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        int x = i + 1, y = i + 2;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 1);
    ans += (n - 1) * 1LL * n;
    dfs1(1, 1);
    for (int x = 1; x <= n; ++x)
        ans += d[x];

    cout << ans << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);
    solv();
    return 0;
}