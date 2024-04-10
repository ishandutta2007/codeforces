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


vector< vector<int> > edge, num;
vector<int> vis;
vector<int> tout;

void dfs(int v) {
    vis[v] = 1;
    for (int i = 0; i < edge[v].size(); i++)
        if (vis[edge[v][i]] == 0)
            dfs(edge[v][i]);
    tout.push_back(v);
}

int main() {
    int n, m;
    cin >> n >> m;
    edge.resize(n);
    num.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        edge[u].push_back(v);
        num[u].push_back(i);
    }
    vis.resize(n);
    for (int i = 0; i < n; i++)
        if (vis[i] == 0)
            dfs(i);
    reverse(tout.begin(), tout.end());
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        bool f = false;
        for (int j = 0; j < edge[tout[i]].size(); j++) {
            if (edge[tout[i]][j] == tout[i + 1]) {
                f = true;
                ans = max(ans, num[tout[i]][j]);
            }
        }
        if (!f) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans + 1 << endl;
    return 0;
}