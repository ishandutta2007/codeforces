#include <bits/stdc++.h>

using namespace std;

vector <pair <int, int> > guys;
vector <int> g[50];
bool used[50];
long long ans = 1;

void dfs(int v) {
    used[v] = 1;
    for (int i = 0; i < (int) g[v].size(); i++) {
        if (!used[g[v][i]]) {
            dfs(g[v][i]);
            ans *= 2;
        }
    }
}

int main() {
    int n, m, u, v;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            dfs(i);
        }
    }
    cout << ans << endl;
}