#include <string>
#include <queue>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <set>
#include <iostream>
#include <cassert>
#include <utility>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

vector<vector<int>> edge;
vector<vector<int>> col;
vector<vector<int>> nEdge;

vector<int> vis;

vector<int> num;

void dfs(int v, int e, int color) {
    vis[v] = color;
    for (int i = 0; i < sz(edge[v]); ++i)
        if (vis[edge[v][i]] == -1 && col[v][i] == e)
            dfs(edge[v][i], e, color);
}

vector<int> vis1;

vector<int> p[2];
int x[2];

bool dfs1(int v, int color) {
    p[color].push_back(v);
    x[color] += num[v];
    vis1[v] = color;
    for (int i = 0; i < sz(nEdge[v]); ++i) {
        if (vis1[nEdge[v][i]] == -1)
            dfs1(nEdge[v][i], 1 - color);
        else {
            if (color + vis1[nEdge[v][i]] != 1)
                return false;
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    edge.resize(n);
    col.resize(n);
    
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        char ch;
        cin >> u >> v >> ch;
        c = (ch == 'R' ? 0 : 1);
        --u; --v;
        edge[u].push_back(v);
        edge[v].push_back(u);
        col[u].push_back(c);
        col[v].push_back(c);
    }
    
    vis.resize(n, -1);
    int color = 0;
    for (int i = 0; i < n; ++i)
        if (vis[i] == -1)
            dfs(i, 0, color++);
    
    bool f1 = true;
    nEdge.resize(color);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < sz(edge[i]); ++j) {
            if (col[i][j] == 1) {
                if (vis[i] == vis[edge[i][j]])
                    f1 = false;
                else {
                    nEdge[vis[i]].push_back(vis[edge[i][j]]);
                    nEdge[vis[edge[i][j]]].push_back(vis[i]);
                }
            }
        }
    
    num.resize(color);
    for (int i = 0; i < n; ++i)
        ++num[vis[i]];
    
    vis1.resize(color, -1);
    
    vector<int> t(color);
    
    if (f1) {
        for (int i = 0; i < color; ++i)
            if (vis1[i] == -1) {
                if (!dfs1(i, 0))
                    f1 = false;
                if (x[0] > x[1])
                    swap(p[0], p[1]);
                
                for (int j = 0; j < p[0].size(); ++j)
                    t[p[0][j]] = 1;
                p[0].clear();
                p[1].clear();
                x[0] = 0;
                x[1] = 0;
            }
    }
    
    vector<int> ans1;
    for (int i = 0; i < n; ++i) {
        if (t[vis[i]])
            ans1.push_back(i + 1);
    }
    
    
    vis.clear();
    vis.resize(n, -1);
    color = 0;
    for (int i = 0; i < n; ++i)
        if (vis[i] == -1)
            dfs(i, 1, color++);
    
    bool f2 = true;
    
    nEdge.clear();
    nEdge.resize(color);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < sz(edge[i]); ++j) {
            if (col[i][j] == 0) {
                if (vis[i] == vis[edge[i][j]])
                    f2 = false;
                else {
                    nEdge[vis[i]].push_back(vis[edge[i][j]]);
                    nEdge[vis[edge[i][j]]].push_back(vis[i]);
                }
            }
        }
    
    num.clear();
    num.resize(color);
    for (int i = 0; i < n; ++i)
        ++num[vis[i]];
    
    vis1.clear();
    vis1.resize(color, -1);
    
    t.clear();
    t.resize(color);
    
    if (f2) {
        for (int i = 0; i < color; ++i)
            if (vis1[i] == -1) {
                if (!dfs1(i, 0))
                    f2 = false;
                if (x[0] > x[1])
                    swap(p[0], p[1]);
                
                for (int j = 0; j < p[0].size(); ++j)
                    t[p[0][j]] = 1;
                p[0].clear();
                p[1].clear();
                x[0] = 0;
                x[1] = 0;
            }
    }
    
    vector<int> ans2;
    for (int i = 0; i < n; ++i) {
        if (t[vis[i]])
            ans2.push_back(i + 1);
    }
    
    
    if ((f2 && sz(ans1) > sz(ans2)) || !f1)
        swap(ans1, ans2);
    
    if (f1 || f2) {
        cout << sz(ans1) << endl;
        for (int i = 0; i < sz(ans1); ++i)
            cout << ans1[i] << " ";
        cout << endl;
        return 0;
    }
    
    cout << -1 << endl;
    return 0;
}