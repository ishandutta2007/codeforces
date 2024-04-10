#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e3 + 7;
vector <int> g[N];
bool u[N];
int dp[N][3];
vector <int> l;
int kek = 1;

void dfs(int v)
{
    u[v] = 1;
    l.push_back(v);
    for (auto to: g[v])
    {
        if (!u[to])
        {
            dfs(to);
        }
    }
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    int n, m, w;
    cin >> n >> m >> w;
    vector <int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    vector <int> b(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int d = 1; d <= w; d++)
    {
        dp[d][0] = INT_MIN;
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!u[i])
        {
            l.clear();
            dfs(i);
            int sum1 = 0;
            int sum2 = 0;
            for (auto c: l)
            {
                sum1 += a[c];
                sum2 += b[c];
            }
            for (int c = 0; c <= w; c++)
            {
                dp[c][1] = dp[c][2] = dp[c][0];
            }
            for (int c = 0; c <= w; c++)
            {
                if (c + sum1 <= w && dp[c][0] != INT_MIN)
                {
                    dp[c + sum1][1] = max(dp[c + sum1][1], dp[c][0] + sum2);
                }
            }
            for (auto c: l)
            {
                for (int d = w; d >= 0; d--)
                {
                    if (d + a[c] <= w && dp[d][0] != INT_MIN)
                    {
                        dp[d + a[c]][2] = max(dp[d + a[c]][2], dp[d][0] + b[c]);
                    }
                }
            }
            for (int c = 0; c <= w; c++)
            {
                dp[c][0] = max(dp[c][1], dp[c][2]);
                res = max(res, dp[c][0]);
            }
        }
    }
    cout << res << endl;
}