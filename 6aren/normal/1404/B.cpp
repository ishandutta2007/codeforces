#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

const int N = 100005;

int n, a, b, da, db;
vector<int> g[N];
int dp[N];
int ans = 0;
int d[N];

void dfs(int cur, int par) {
    int mx1 = 0;
    int mx2 = 0;
    for (int e : g[cur]) {
        if (e == par) continue;
        dfs(e, cur);
        if (dp[e] > mx1) mx2 = mx1, mx1= dp[e];
        else if (dp[e] > mx2) mx2 = dp[e];
    }
    ans = max(ans, mx1 + mx2);
    dp[cur] = mx1 + 1;
}

void dfs2(int cur, int par) {
    for (int e : g[cur]) {
        if (e == par) continue;
        d[e] = d[cur] + 1;
        dfs2(e, cur);
    }
}


void solve() {
    cin >> n >> a >> b >> da >> db;
    ans = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = 0;
        g[i].clear();
        d[i] = 0;
    }
    dp[a] = 1;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs2(b, 0);
    if (db <= 2 * da || a == b || d[a] <= da) {
        cout << "Alice\n";
        return;
    } 
    dfs2(b, 0);
    dfs(1, 0);
    if (ans <= 2 * da) cout << "Alice\n";
    else cout << "Bob\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int ntest;
    cin >> ntest;
    while (ntest--) solve();
    return 0;
}