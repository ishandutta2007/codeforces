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

int n, k;
vector<int> g[N];
int s[N];

map<int, ll> dp[N];
ll dfs(int x, ll k)
{
    if (dp[x].find(k) != dp[x].end())
        return dp[x][k];
    dp[x][k] = s[x] * k;
    if (sz(g[x]) == 0)
        return dp[x][k];
    vector<ll> v;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (k % sz(g[x]) == 0)
        {
            dp[x][k] += dfs(h, k / sz(g[x]));
        }
        else
        {
            dp[x][k] += dfs(h, k / sz(g[x]));
            v.push_back(dfs(h, k / sz(g[x]) + 1) - dfs(h, k / sz(g[x])));
        }
    }
    sort(all(v));
    reverse(all(v));
    for (int i = 0; i < k % sz(g[x]); ++i)
        dp[x][k] += v[i];
    return dp[x][k];
}

void solv()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        g[i].clear();
        dp[i].clear();
    }
    for (int i = 2; i <= n; ++i)
    {
        int p;
        cin >> p;
        g[p].push_back(i);
    }
    for (int i = 1; i <= n; ++i)
        cin >> s[i];

    cout << dfs(1, k) << "\n";
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