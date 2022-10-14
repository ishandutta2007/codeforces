#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double

const int INF = 2e9 + 1;

vector<vector<int>> g;
vector<int> usd, ts;

bool f = false;

void dfs(int v) {
    usd[v] = 1;
    for (auto &to : g[v]) {
        if (usd[to] == 1) f = true;
        if (usd[to] == 0) dfs(to);
    }
    ts.pb(v);
    usd[v] = 2;
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
        g.clear();
        g.resize(n);
        usd.assign(n, 0);
        ts.clear();
        vector<pii> e;
        f = false;
        for (int i = 0; i < m; i++) {
            int ty, a, b;
            cin >> ty >> a >> b; a--; b--;
            if (ty == 0) e.pb(a, b);
            else g[a].pb(b);
        }
        for (int i = 0; i < n; i++) {
            if (usd[i] == 0) dfs(i);
        }
        if (f) {
            cout << "NO\n";
            continue;
        }
        reverse(all(ts));
        cout << "YES\n";
        vector<int> id(n);
        for (int i = 0; i < n; i++) id[ts[i]] = i;
        for (int i = 0; i < n; i++) {
            for (auto &to : g[i]) cout << i + 1 << " " << to + 1 << "\n";
        }
        for (auto &c : e) {
            if (id[c.fi] > id[c.se]) swap(c.fi, c.se);
            cout << c.fi + 1 << " " << c.se + 1 << "\n";
        }
    }
    return 0;
}