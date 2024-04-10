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

int dp[N];
int q[N];
void dfs(int x, int p)
{
    q[x] = 1;

    vector<int> v;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;

        dfs(h, x);
        v.push_back(h);

        q[x] += q[h];
    }

    if (v.empty())
        dp[x] = 0;
    else if (sz(v) == 1)
        dp[x] = q[v[0]] - 1;
    else if (sz(v) == 2)
        dp[x] = max(dp[v[0]] + q[v[1]] - 1, dp[v[1]] + q[v[0]] - 1);
    else
        assert(false);
}

void solv()
{
    cin >> n;
    for (int x = 1; x <= n; ++x)
        g[x].clear();
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(1, 1);

    cout << dp[1] << "\n";
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