#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAX_N = 200009;
vector<int> g[MAX_N];
int c[MAX_N];
bool used[MAX_N];
vector<pair<int, int> > q[MAX_N][2];
int n;
int dp[MAX_N][2];
int inf = 1ll * 1000 * 1000 * 1000 * 1000 * 1000 * 1000;
vector<int> ans;
bool u[MAX_N][2];

void dfs(int v, int pr)
{
    if (pr != -1 && g[v].size() == 1)
    {
        dp[v][0] = c[v];
        dp[v][1] = 0;
        used[v] = true;
        return;
    }
    int sum = 0;
    for (int to : g[v])
    {
        if (to != pr)
            dfs(to, v);
        sum += dp[to][0];
    }
    int mi = inf;
    for (int to : g[v])
    {
        if (to == pr)
            continue;
        mi = min(mi, sum - dp[to][0] + dp[to][1]);
    }
    if (mi + c[v] <= sum)
    {
        used[v] = true;
        vector<int> cur;
        for (int to : g[v])
        {
            if (to == pr)
                continue;
            if (sum - dp[to][0] + dp[to][1] == mi)
                cur.push_back(to);
        }
        if (cur.size() == 1)
        {
            for (int to : g[v])
            {
                if (to == pr || to == cur.back())
                    continue;
                q[v][0].emplace_back(to, 0);
            }
            q[v][0].emplace_back(cur.back(), 1);
        }
        else
        {
            for (int to : g[v])
            {
                if (to == pr)
                    continue;
                q[v][0].emplace_back(to, 0);
            }
            for (int to : cur)
                q[v][0].emplace_back(to, 1);
        }
    }
    if (mi + c[v] >= sum)
    {
        for (int to : g[v])
        {
            if (to == pr)
                continue;
            q[v][0].emplace_back(to, 0);
        }
    }
    vector<int> cur;
        for (int to : g[v])
        {
            if (to == pr)
                continue;
            if (sum - dp[to][0] + dp[to][1] == mi)
                cur.push_back(to);
        }
        if (cur.size() == 1)
        {
            for (int to : g[v])
            {
                if (to == pr || to == cur.back())
                    continue;
                q[v][1].emplace_back(to, 0);
            }
            q[v][1].emplace_back(cur.back(), 1);
        }
        else
        {
            for (int to : g[v])
            {
                if (to == pr)
                    continue;
                q[v][1].emplace_back(to, 0);
            }
            for (int to : cur)
                q[v][1].emplace_back(to, 1);
        }
    dp[v][1] = mi;
    dp[v][0] = min(mi + c[v], sum);
    dp[v][1] = min(dp[v][1], dp[v][0]);
}

void dfs1(int v, int t)
{
    u[v][t] = true;
    if (t == 0 && used[v])
        ans.push_back(v);
    for (auto to : q[v][t])
    {
        if (!u[to.first][to.second])
            dfs1(to.first, to.second);
    }
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifdef ON_PC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ON_PC
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> c[i];
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0, -1);
    dfs1(0, 0);
    cout << dp[0][0] << " " << ans.size() << "\n";
    sort(ans.begin(), ans.end());
    for (int e : ans)
        cout << e + 1 << " ";
}