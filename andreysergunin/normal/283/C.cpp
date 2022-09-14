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

using namespace std;

const int P = 1e9 + 7;

vector< vector<int> > edge;
vector<int> vis;
vector<int> depth;
vector<int> w;
vector<int> a;
bool f = true;

void dfs (int v, int c, int d) {
    vis[v] = c;
    w[v] = d + a[v];
    depth[v] = 0;
    for (int i = 0; i < edge[v].size(); i++) {
        if (vis[edge[v][i]] == c)
            f = false;
        if (vis[edge[v][i]] == 0)
            dfs(edge[v][i], c, w[v]);
        depth[v] = max(depth[v], depth[edge[v][i]] + 1);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, q;
    long long t;
    cin >> n >> q >> t;
    edge.resize(n);
    a.resize(n);
    vector<int> g(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[v] = 1;
        edge[u].push_back(v);
    }
    int c = 1;
    vis.resize(n);
    depth.resize(n);
    w.resize(n);
    for (int i = 0; i < n; i++)
        if (g[i] == 0)
            dfs(i, c++, 0);
    for (int i = 0; i < n; i++)
        if (vis[i] == 0)
            f = false;
    if (!f) {
        cout << 0;
        return 0;
    }
    for (int i = 0; i < n; i++)
        t -= (long long)depth[i] * a[i];
    if (t < 0) {
        cout << 0;
        return 0;
    }
    vector< vector<int> > dp(t + 1);
    for (int i = 0; i <= t; i++)
        dp[i].resize(n);
    for (int i = 0; i < n; i++)
        dp[0][i] = 1;
    for (int i = 1; i <= t; i++) {
        for (int j = 0; j < n; j++) {
            if (j > 0)
                dp[i][j] = dp[i][j - 1];
            if (i - w[j] >= 0)
                dp[i][j] = (dp[i][j] + dp[i - w[j]][j]) % P;
        }
    }
    cout << dp[t][n - 1] << endl;
}