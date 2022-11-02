#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 200010;
int n, m, k;
pair<int, int> ed[MAX_N];
set<int> g[MAX_N];
bool used[MAX_N];
int ans[MAX_N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        ed[i].first = a;
        ed[i].second = b;
        g[a].insert(b);
        g[b].insert(a);
    }
    for (int i = 0; i < n; i++)
        used[i] = true;
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (g[i].size() < k)
        {
            q.push(i);
        }
    }
    int cur = n;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        if (!used[v])
            continue;
        used[v] = false;
        cur--;
        for (int to : g[v])
        {
            if (!used[to])
                continue;
            g[to].erase(v);
            if (g[to].size() < k)
                q.push(to);
        }
    }
    ans[m - 1] = cur;
    for (int i = m - 1; i > 0; i--)
    {
        int a = ed[i].first;
        int b = ed[i].second;
        if (g[a].find(b) != g[a].end())
            g[a].erase(b);
        if (g[b].find(a) != g[b].end())
            g[b].erase(a);
        if (used[a] && g[a].size() < k)
            q.push(a);
        if (used[b] && g[b].size() < k)
            q.push(b);
        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            if (!used[v])
                continue;
            used[v] = false;
            cur--;
            for (int to : g[v])
            {
                if (!used[to])
                    continue;
                g[to].erase(v);
                if (g[to].size() < k)
                    q.push(to);
            }
        }
        ans[i - 1] = cur;
    }
    for (int i = 0; i < m; i++)
        cout << ans[i] << "\n";
}