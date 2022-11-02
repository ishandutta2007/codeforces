#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAX_N = 100009;
vector<pair<int, int> > g[MAX_N];
bool x[MAX_N];
int y[MAX_N];
int n, m, k;
bool used[MAX_N];
vector<pair<int, int> > g1[MAX_N];
int u[MAX_N];
int b[MAX_N];
int cnt[MAX_N];

bool dfs(int v, int pr, int t, int ww, bool uu)
{
    if (t == 0)
    {
        bool q = x[v];
        for (auto to : g1[v])
        {
            if (to.first != pr)
            {
                bool u1 = dfs(to.first, v, t, ww, uu);
                cnt[v] += cnt[to.first];
                if (u1)
                    u[v] = max(u[v], max(u[to.first], to.second));
                q |= u1;
            }
        }
        if (x[v])
            cnt[v]++;
        return q;
    }
    else
    {
        if (pr != -1)
        {
            b[v] = max(b[v], ww);
        }
        int ma = 0;
        int ma1 = 0;
        uu |= x[v];
        bool uu1 = uu;
        for (auto to : g1[v])
        {
            if (to.first != pr && cnt[to.first] >= 1)
            {
                uu = 1;
                ww = max(ww, to.second);
                if (u[to.first] > ma)
                {
                    ma1 = ma;
                    ma = u[to.first];
                }
                else if (u[to.first] > ma1)
                    ma1 = u[to.first];
            }
        }
        for (auto to : g1[v])
        {
            if (to.first != pr)
            {
                if (cnt[v] == cnt[to.first] && !uu1)
                    dfs(to.first, v, t, 0, 0);
                else if (u[to.first] == ma)
                    dfs(to.first, v, t, max(ma1, ww), uu);
                else
                    dfs(to.first, v, t, max(ma, ww), uu);
            }
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> y[i];
        y[i]--;
        x[y[i]] = true;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b1, c;
        cin >> a >> b1 >> c;
        a--;
        b1--;
        g[a].emplace_back(b1, c);
        g[b1].emplace_back(a, c);
    }
    priority_queue<pair<int, pair<int, int> > > q;
    used[0] = true;
    for (auto to : g[0])
        q.emplace(-to.second, make_pair(0, to.first));
    while (!q.empty())
    {
        pair<int, int> v = q.top().second;
        int w = -q.top().first;
        q.pop();
        if (used[v.second])
            continue;
        used[v.second] = true;
        g1[v.first].emplace_back(v.second, w);
        g1[v.second].emplace_back(v.first, w);
        for (auto to : g[v.second])
        {
            if (!used[to.first])
                q.emplace(-to.second, make_pair(v.second, to.first));
        }
    }
    dfs(0, -1, 0, 0, 0);
    dfs(0, -1, 1, 0, 0);
    for (int i = 0; i < k; i++)
        cout << max(u[y[i]], b[y[i]]) << " ";
}