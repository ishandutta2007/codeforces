#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <ctime>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using namespace std;

vector<vector<int>> edge;

vector<int> bfs(int v) {
    int n = sz(edge);
    vector<int> dist(n, -1);
    dist[v] = 0;
    queue<int> q;
    q.push(v);
    while (!q.empty()) {
        int u = q.front();
        for (int i = 0; i < sz(edge[u]); ++i)
            if (dist[edge[u][i]] == -1) {
                dist[edge[u][i]] = dist[u] + 1;
                q.push(edge[u][i]);
            }
        q.pop();
    }
    return dist;
}

int main() {
    int n, m;
    cin >> n >> m;
    edge.resize(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        edge[u].push_back(v);
    }
    
    vector<vector<int>> dist(n);
    
    for (int i = 0; i < n; ++i)
        dist[i] = bfs(i);
    
    vector<vector<pair<int, int>>> d(n);
    
    
    for (int i = 0; i < n; ++i) {
        vector<pair<int, int>> a(n);
        for (int j = 0; j < n; ++j)
            a[j] = make_pair(dist[i][j], j);
        sort(all(a));
        d[i].push_back(a[n - 1]);
        d[i].push_back(a[n - 2]);
        d[i].push_back(a[n - 3]);
    }
    
    vector<vector<pair<int, int>>> d1(n);
    for (int i = 0; i < n; ++i) {
        vector<pair<int, int>> a(n);
        for (int j = 0; j < n; ++j)
            a[j] = make_pair(dist[j][i], j);
        sort(all(a));
        d1[i].push_back(a[n - 1]);
        d1[i].push_back(a[n - 2]);
        d1[i].push_back(a[n - 3]);
    }
    
    int gl = 0;
    vector<int> ans(4);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j)
                continue;
            int cur = 0;
            int x = 0;
            while (d1[i][x].second == j)
                ++x;
            x = d1[i][x].second;
            
            int y = 0;
            while (d[j][y].second == i || d[j][y].second == x)
                ++y;
            y = d[j][y].second;
            
            cur = dist[x][i] + dist[i][j] + dist[j][y];
            if (x == i || y == j || dist[x][i] == -1 || dist[i][j] == -1 || dist[j][y] == -1)
                continue;
            
            if (cur > gl) {
                gl = cur;
                ans = {x, i, j, y};
            }
        }
        
        for (int j = 0; j < n; ++j) {
            if (i == j)
                continue;
            int cur = 0;
            int x = 0;
            
            
            int y = 0;
            while (d[j][y].second == i)
                ++y;
            y = d[j][y].second;
            
            while (d1[i][x].second == j || d1[i][x].second == y)
                ++x;
            x = d1[i][x].second;
            
            cur = dist[x][i] + dist[i][j] + dist[j][y];
            if (x == i || y == j || dist[x][i] == -1 || dist[i][j] == -1 || dist[j][y] == -1)
                continue;
            
            if (cur > gl) {
                gl = cur;
                ans = {x, i, j, y};
            }
        }
        
    }
    for (int i = 0; i < 4; ++i)
        cout << ans[i] + 1 << " ";
}