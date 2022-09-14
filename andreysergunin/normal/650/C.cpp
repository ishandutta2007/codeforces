#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <ctime>
#include <queue>

using namespace std;

vector< vector<int> > edge;
vector< vector<int> > condEdge;
vector<int> ans;


vector<int> vis, tout;
int k = 0;

void dfs1(int v) {
    vis[v] = 1;
    for (int i = 0; i < edge[v].size(); i++)
        if (vis[edge[v][i]] == 0)
            dfs1(edge[v][i]);
    tout.push_back(v);
}

void dfs2(int v, int c) {
    vis[v] = c;
    for (int i = 0; i < edge[v].size(); i++)
        if (vis[edge[v][i]] == -1)
            dfs2(edge[v][i], c);
}

int main() {
    int n, m;
    cin >> n >> m;
    edge.resize(n * m);
    vector< vector<int> > a(n);
    for (int i = 0; i < n; i++) {
        a[i].resize(m);
        for (int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
    }
    for (int i = 0; i < n; i++) {
        vector< pair<int, int> > b;
        for (int j = 0; j < m; j++)
            b.push_back(make_pair(a[i][j], j));
        sort(b.begin(), b.end());
        for (int j = 0; j < m - 1; j++) {
            edge[b[j + 1].second + i * m].push_back(b[j].second + i * m);
            if (b[j + 1].first == b[j].first)
                edge[b[j].second + i * m].push_back(b[j + 1].second + i * m);
        }
    }
    
    for (int j = 0; j < m; j++) {
        vector< pair<int, int> > b;
        for (int i = 0; i < n; i++)
            b.push_back(make_pair(a[i][j], i));
        sort(b.begin(), b.end());
        for (int i = 0; i < n - 1; i++) {
            edge[b[i + 1].second * m + j].push_back(b[i].second * m + j);
            if (b[i + 1].first == b[i].first)
                edge[b[i].second * m + j].push_back(b[i + 1].second * m + j);
        }
    }

    vis.resize(n * m);
    for (int i = 0; i < n * m; i++)
        if (vis[i] == 0)
            dfs1(i);
    
    vector< vector<int> > edge1(n * m);
    for (int i = 0; i < n * m; i++)
        for (int j = 0; j < edge[i].size(); j++)
            edge1[edge[i][j]].push_back(i);
    edge = edge1;

    int c = 0;
    for (int i = 0; i < n * m; i++)
        vis[i] = -1;
    for (int i = n * m - 1; i >= 0; i--)
        if (vis[tout[i]] == -1)
            dfs2(tout[i], c++);
    
    condEdge.resize(c);
    for (int i = 0; i < n * m; i++) {
        for (int j = 0; j < edge[i].size(); j++)
            if (vis[i] != vis[edge[i][j]])
                condEdge[vis[edge[i][j]]].push_back(vis[i]);
    }
    
    
    ans.resize(c);
    for (int i = c - 1; i >= 0; i--) {
        ans[i] = 0;
        int t = 0;
        for (int j = 0; j < condEdge[i].size(); j++)
            t = max(t, ans[condEdge[i][j]] + 1);
        ans[i] = t;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << ans[vis[i * m + j]] + 1 << " ";
        cout << endl;
    }
    
    
    return 0;
}