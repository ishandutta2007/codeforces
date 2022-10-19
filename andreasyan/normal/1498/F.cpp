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
const int N = 100005, K = 22;

int n, k;
vector<int> g[N];
int a[N];

vector<int> dp[N];
void dfs0(int x, int p)
{
    for (int j = 0; j < k * 2; ++j)
    {
        dp[x].push_back(0);
    }
    dp[x][0] ^= a[x];
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        dfs0(h, x);
        for (int j = 0; j < k * 2; ++j)
        {
            dp[x][j] ^= dp[h][(j - 1 + k * 2) % (k * 2)];
        }
    }
}

int ans[N];
void dfs1(int x, int p, vector<int> dpp)
{
    for (int j = 0; j < k * 2; ++j)
    {
        dp[x][j] ^= dpp[(j - 1 + k * 2) % (k * 2)];
    }
    for (int j = k; j < k * 2; ++j)
        ans[x] ^= dp[x][j];
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        for (int j = 0; j < k * 2; ++j)
        {
            dp[x][j] ^= dp[h][(j - 1 + k * 2) % (k * 2)];
        }
        dfs1(h, x, dp[x]);
        for (int j = 0; j < k * 2; ++j)
        {
            dp[x][j] ^= dp[h][(j - 1 + k * 2) % (k * 2)];
        }
    }
    for (int j = 0; j < k * 2; ++j)
    {
        dp[x][j] ^= dpp[(j - 1 + k * 2) % (k * 2)];
    }
}

void solv()
{
    cin >> n >> k;
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int x = 1; x <= n; ++x)
        cin >> a[x];

    dfs0(1, 1);
    vector<int> pp;
    for (int j = 0; j < k * 2; ++j)
    {
        pp.push_back(0);
    }
    dfs1(1, 1, pp);

    for (int x = 1; x <= n; ++x)
    {
        if (ans[x])
            cout << "1 ";
        else
            cout << "0 ";
    }
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
        solv();
    return 0;
}