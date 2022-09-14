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

using namespace std;

vector<int> vis;
vector< vector<int> > edge, num;
vector<int> del;
vector<int> ans[3];

void dfs(int v, int p, int e) {
    vis[v] = 1;
    for (int i = 0; i < (int)edge[v].size(); i++)
        if (vis[edge[v][i]] == 0)
            dfs(edge[v][i], v, num[v][i]);
    vector<int> a;
    for (int i = 0; i < (int)edge[v].size(); i++)
        if (del[num[v][i]] == 0 && edge[v][i] != p)
            a.push_back(i);
    for (int i = 0; i < (int)a.size() - 1; i += 2) {
        del[num[v][a[i]]] = 1;
        del[num[v][a[i + 1]]] = 1;
        ans[0].push_back(edge[v][a[i]]);
        ans[1].push_back(v);
        ans[2].push_back(edge[v][a[i + 1]]);
    }
    if (p != -1 && (int)a.size() % 2 == 1) {
        del[num[v][a[a.size() - 1]]] = 1;
        del[e] = 1;
        ans[0].push_back(p);
        ans[1].push_back(v);
        ans[2].push_back(edge[v][a[a.size() - 1]]);
    }
}



int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    edge.resize(n);
    num.resize(n);
    del.resize(m);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        edge[u].push_back(v);
        edge[v].push_back(u);
        num[u].push_back(i);
        num[v].push_back(i);
    }
    vis.resize(n);
    for (int i = 0; i < n; i++) {
        if (vis[i] == 0)
            dfs(i, -1, -1);
    }
    if (m % 2 == 0 && ans[0].size() == m / 2) {
        for (int i = 0; i < m / 2; i++) {
            for (int j = 0; j < 3; j++)
                cout << ans[j][i] + 1 << " ";
            cout << endl;
        }
    }
    else
        cout << "No solution";
    return 0;
}