#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long

const int INF = 2e9 + 1;
const ll INFLL = 1e18 + 1;
const int mod = 1e9 + 7;

int b, w;

vector<vector<int>> g;

void dfs(int v, int p, int c) {
    if (c == 1) b++;
    else w++;
    for (auto &to : g[v]) {
        if (to != p) dfs(to, v, 3 - c);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    g.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b; a--; b--;
        g[a].pb(b); g[b].pb(a);
    }
    dfs(0, -1, 1);
    cout << min(b, w) - 1;
    return 0;
}