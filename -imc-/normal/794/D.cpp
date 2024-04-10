#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;

int n;
vector<vector<int>> e;

vector<int> bfs(int v)
{
    deque<int> q;
    q.push_back(v);
    
    vector<int> d(n, -1);
    d[v] = 0;
    
    while (!q.empty())
    {
        v = q.front();
        q.pop_front();
        
        for (int u: e[v])
            if (d[u] == -1)
            {
                d[u] = d[v] + 1;
                q.push_back(u);
            }
    }
    
    return d;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int m;
    cin >> n >> m;
    
    e.resize(n);
    
    set<pair<int, int>> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--; v--;
        e[u].push_back(v);
        e[v].push_back(u);
        edges.emplace(min(u, v), max(u, v));
    }
    
    pair<int, int> edge;
    for (int i = 0; i < n; i++)
        if ((int)e[i].size() != n - 1)
        {
            vector<char> vis(n, false);
            vis[i] = true;
            for (int u: e[i])
                vis[u] = true;
            
            for (int j = 0; j < n; j++)
                if (!vis[j])
                {
                    edge = make_pair(i, j);
                    goto breakAll;
                }
        }
        
    breakAll:;
    if (edge.first == edge.second)
    {
        cout << "YES\n";
        for (int i = 0; i < n; i++)
            cout << "1 ";
        cout << "\n";
        return 0;
    }
    
    vector<int> d = bfs(edge.first);
    int start = max_element(all(d)) - d.begin();
    d = bfs(start);
    
    vector<int> mark = d;
    for (int i = 0; i < (int)mark.size(); i++)
        if (mark[i] <= 1)
            mark[i] = 2;
        else
            mark[i]++;
        
    start = max_element(all(d)) - d.begin();
    d = bfs(start);
    
    int mx = *max_element(all(d));
    for (int i = 0; i < n; i++)
        if (d[i] == mx)
            mark[i] = 1;
    
    vector<vector<int>> with_mark(n + 1);
    for (int i = 0; i < n; i++)
        with_mark[mark[i] - 1].push_back(i);
    
    for (int i = 0; i <= n; i++)
    {
        for (int a: with_mark[i])
        {
            for (int delta = -1; delta <= 1; delta++)
            {
                if (i + delta < 0 || i + delta > n) continue;
                
                if (delta == 0 && (li)with_mark[i].size() * (li)(with_mark[i].size() - 1) / 2 > m)
                {
                    cout << "NO\n";
                    return 0;
                }
                
                if (delta != 0 && (li)with_mark[i].size() * (li)(with_mark[i + delta].size()) > m)
                {
                    cout << "NO\n";
                    return 0;
                }
            
                for (int b: with_mark[i + delta])
                    if (a < b && !edges.count(make_pair(a, b)))
                    {
                        cout << "NO\n";
                        return 0;
                    }
            }
        }
    }
    
    cout << "YES\n";
    for (int v: mark)
        cout << v << " ";
    cout << endl;
        
    
    return 0;
}