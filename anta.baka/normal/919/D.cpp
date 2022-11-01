#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
const int maxn = 3e5;

int n, m, c[maxn], dp[maxn][26];
vector<int> g[maxn], was;

void dfs(int v) {
    was[v] = 1;
    for(int to : g[v])
        if(was[to] == 1) {
            cout << -1;
            exit(0);
        } else if(was[to] == 0) dfs(to);
    was[v] = 2;
}

void dfs1(int v) {
    was[v] = 1;
    for(int to : g[v]) if(!was[to]) dfs1(to);
    for(int x = 0; x < 26; x++) {
        dp[v][x] = (c[v] == x);
        for(int to : g[v]) dp[v][x] = max(dp[v][x], dp[to][x] + (c[v] == x));
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        char ch; cin >> ch; c[i] = ch - 'a';
    }
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--; v--;
        g[u].push_back(v);
    }
    was.assign(n, 0);
    for(int u = 0; u < n; u++) if(!was[u]) dfs(u);
    was.assign(n, 0);
    for(int u = 0; u < n; u++) if(!was[u]) dfs1(u);
    int ans = 0;
    for(int u = 0; u < n; u++) for(int x = 0; x < 26; x++) ans = max(ans, dp[u][x]);
    cout << ans;
}