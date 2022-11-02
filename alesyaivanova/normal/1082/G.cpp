#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAX_N = 100009;
const int MAX_M = 100009;
vector<pair<int, int> > g[MAX_N];
int n, m, s, t;
int c[2 * MAX_M];
int f[2 * MAX_M];
map<pair<int, int>, int> u;
int d[MAX_N];
int pt[MAX_N];
int inf = 1ll * 1000 * 1000 * 1000 * 1000 * 1000 * 1000;
int sum = 0;

bool bfs(int j)
{
    for (int i = 0; i < n; i++)
    {
        d[i] = -1;
        pt[i] = 0;
    }
    d[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (auto to : g[v])
        {
            if (c[to.second] - f[to.second] < j)
                continue;
            if (d[to.first] == -1)
            {
                d[to.first] = d[v] + 1;
                q.push(to.first);
            }
        }
    }
    if (d[t] == -1)
        return false;
    return true;
}

int dfs(int v, int cmin, int j)
{
    if (v == t || cmin == 0)
        return cmin;
    for (; pt[v] < (int)g[v].size(); pt[v]++)
    {
        pair<int, int> to = g[v][pt[v]];
        if (d[to.first] != d[v] + 1 || c[to.second] - f[to.second] < j)
            continue;
        int flow = dfs(to.first, min(cmin, c[to.second] - f[to.second]), j);
        if (flow)
        {
            f[to.second] += flow;
            f[to.second ^ 1] -= flow;
            return flow;
        }
    }
    return 0;
}

int dinic()
{
    int ans = 0;
    for (int j = inf; j >= 1; j /= 2)
    {
        while (bfs(j))
        {
            while(true)
            {
                int cur = dfs(s, inf, j);
                if (cur > 0)
                    ans += cur;
                else
                    break;
            }
        }
    }
    return ans;
}

void build_g()
{
    int n1, m1;
    cin >> n1 >> m1;
    t = 0;
    int cnt = 0;
    for (int i = 1; i <= n1; i++)
    {
        int a;
        cin >> a;
        g[i].emplace_back(t, cnt);
        g[t].emplace_back(i, cnt + 1);
        c[cnt] = a;
        cnt += 2;
    }
    s = n1 + 1;
    for (int i = n1 + 2; i < n1 + m1 + 2; i++)
    {
        int a, b, c1;
        cin >> a >> b >> c1;
        sum += c1;
        g[s].emplace_back(i, cnt);
        g[i].emplace_back(s, cnt + 1);
        c[cnt] = c1;
        cnt += 2;
        g[i].emplace_back(a, cnt);
        g[a].emplace_back(i, cnt + 1);
        c[cnt] = inf;
        cnt += 2;
        g[i].emplace_back(b, cnt);
        g[b].emplace_back(i, cnt + 1);
        c[cnt] = inf;
        cnt += 2;
    }
    n = n1 + m1 + 2;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    build_g();
    cout << sum - dinic();
}