#include <bits/stdc++.h>

using namespace std;

int n, c[2];
vector<int> g[100000];

void dfs(int v, int p, int x) {
    c[x]++;
    for(int to : g[v])
        if(to != p)
            dfs(to, v, !x);
}

int main() {
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v; --u; --v;
        g[u].push_back(v); g[v].push_back(u);
    }
    dfs(0, -1, 0);
    cout << 1LL * c[0] * c[1] - n + 1;
}