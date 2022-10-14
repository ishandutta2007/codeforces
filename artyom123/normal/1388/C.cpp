#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back

const int MAXN = 2e5 + 5;

vector<vector<int>> g;
vector<int> sz, p;

void dfs(int v, int par) {
    sz[v] = p[v];
    for (auto &to : g[v]) {
        if (to == par) continue;
        dfs(to, v);
        sz[v] += sz[to];
    }
}

void dfs1(int v, int par, vector<int> &kek, bool &good) {
    int sum = 0;
    for (auto &to : g[v]) {
        if (to == par) continue;
        dfs1(to, v, kek, good);
        sum += kek[to];
    }
    if (sum > kek[v]) good = false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        p.assign(n, 0);
        for (auto &c : p) cin >> c;
        g.clear();
        g.resize(n);
        vector<int> h(n);
        for (auto &c : h) cin >> c;
        sz.assign(n, 0);
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b; a--; b--;
            g[a].pb(b); g[b].pb(a);
        }
        dfs(0, -1);
        bool good = true;
        vector<int> kek(n);
        for (int i = 0; i < n; i++) {
            int y = (sz[i] - h[i]) / 2;
            int x = sz[i] - y;
            if (x - y != h[i] || x < 0 || x > sz[i]) good = false;
            kek[i] = x;
        }
        if (!good) {
            cout << "NO\n";
            continue;
        }
        dfs1(0, -1, kek, good);
        if (!good) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
    return 0;
}