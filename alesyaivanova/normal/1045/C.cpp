#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100010;
vector<pair<int, int> > g[MAX_N];
bool used[5 * MAX_N];
int n, m, q;
vector<pair<int, int> > g1[2 * MAX_N];
const int T = 22;
int pr[2 * MAX_N][T];
int dist[2 * MAX_N][T];
int h[2 * MAX_N];

void dfs(int v, int p, int d, int h1)
{
    h[v] = h1;
    pr[v][0] = p;
    dist[v][0] = d;
    for (int i = 1; i < T; i++)
    {
        int u = pr[v][i - 1];
        pr[v][i] = pr[u][i - 1];
        dist[v][i] = dist[v][i - 1] + dist[u][i - 1];
    }
    for (auto to : g1[v])
    {
        if (to.first != p)
            dfs(to.first, v, to.second, h1 + 1);
    }
}

int find_lca(int a, int b)
{
    if (h[a] < h[b])
    {
        int c = a;
        a = b;
        b = c;
    }
    int j = T - 1;
    int ans = 0;
    while (h[a] > h[b])
    {
        int a1 = pr[a][j];
        if (h[a1] < h[b])
        {
            j--;
            continue;
        }
        ans += dist[a][j];
        a = a1;
        j--;
    }
    j = T - 1;
    while (a != b && j >= 0)
    {
        int a1 = pr[a][j];
        int b1 = pr[b][j];
        if (a1 == b1)
        {
            j--;
            continue;
        }
        ans += dist[a][j];
        ans += dist[b][j];
        a = a1;
        b = b1;
        j--;
    }
    if (a != b)
    {;
        ans += dist[a][0];
        ans += dist[b][0];
        a = pr[a][0];
        b = pr[b][0];
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> q;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].emplace_back(b, i);
        g[b].emplace_back(a, i);
    }
    for (int i = 0; i < n; i++)
    {
        sort(g[i].begin(), g[i].end());
    }
    int n1 = n;
    for (int v = 0; v < n; v++)
    {
        for (int e = 0; e < (int)g[v].size(); e++)
        {
            if (used[g[v][e].second])
                continue;
            used[g[v][e].second] = true;
            int to = g[v][e].first;
            //cout << " " << v << " " << to << endl;
            int j1 = 0;
            int j2 = 0;
            bool t = false;
            while (j1 < (int)g[v].size() && j2 < (int)g[to].size())
            {
                //cout << j2 << " " << g[to].size() << " " << g[v][j1].first << " " << g[to][j2].first << endl;
                if (g[v][j1].first == g[to][j2].first)
                {
                    t = true;
                    used[g[v][j1].second] = true;
                    used[g[to][j2].second] = true;
                    int u1 = g[v][j1].first;
                    g1[u1].emplace_back(n1, 1);
                    g1[n1].emplace_back(u1, 1);
                    for (pair<int, int> u2 : g[u1])
                    {
                        if (!used[u2.second] && !g1[u2.first].empty() && g1[u2.first].back().first == n1)
                            used[u2.second] = true;
                    }
                    j1++;
                    j2++;
                }
                else if (g[v][j1].first < g[to][j2].first)
                    j1++;
                else
                    j2++;
            }

            if (t)
            {
                g1[v].emplace_back(n1, 1);
                g1[n1].emplace_back(v, 1);
                g1[to].emplace_back(n1, 1);
                g1[n1].emplace_back(to, 1);
                n1++;
            }
            else
            {
                g1[v].emplace_back(to, 2);
                g1[to].emplace_back(v, 2);
            }
        }
    }

    dfs(0, 0, 0, 0);
    for (int j = 0; j < q; j++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        int ans = find_lca(a, b);
        cout << ans / 2 << "\n";
    }
}