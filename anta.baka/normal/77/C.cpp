#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, k[100000], rt;
vector<int> g[100000];
ll dp[100000];

void dfs(int v, int p) {
    if(v != rt) k[v]--;
    vector<pair<ll, int>> vec;
    for(int to : g[v]) {
        if(to == p) continue;
        dfs(to, v);
        vec.push_back({dp[to], to});
    }
    sort(vec.begin(), vec.end(), greater<pair<ll, int>>());
    for(int i = 0; i < vec.size() && k[v] != 0; i++) {
        dp[v] += vec[i].first + 2;
        k[v]--;
    }
    for(int to : g[v])
        if(to != p)
            if(k[v] >= k[to]) { dp[v] += 2 * k[to]; k[v] -= k[to]; }
            else { dp[v] += 2 * k[v]; k[v] = 0; break; }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> k[i];
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v; --u; --v;
        g[u].push_back(v); g[v].push_back(u);
    }
    cin >> rt; rt--;
    dfs(rt, -1);
    cout << dp[rt];
}