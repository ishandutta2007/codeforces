#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back

const int INF = 1e9 + 1;

vector<int> sz;
vector<vector<int>> g;

void dfs(int v, int p) {
    sz[v] = 1;
    for (auto &to : g[v]) {
        if (to == p) continue;
        dfs(to, v);
        sz[v] += sz[to];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        g.clear();
        sz.clear();
        g.resize(n);
        sz.resize(n);
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            a--; b--;
            g[a].pb(b);
            g[b].pb(a);
        }
        x--;
        if ((int)g[x].size() <= 1) {
            cout << "Ayush\n";
            continue;
        }
        dfs(x, -1);
        int total = 0;
        for (auto &to : g[x]) total += sz[to];
        if (total % 2 == 0) cout << "Ashish\n";
        else cout << "Ayush\n";
    }
    return 0;
}