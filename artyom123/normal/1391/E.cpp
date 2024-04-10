#include<bits/stdc++.h>

using namespace std;

#define pb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define ll long long
#define pii pair<int, int>

const int INF = 2e9 + 1;

vector<int> d, par, usd;
vector<vector<int>> g;

void dfs(int v, int p, int cur) {
    par[v] = p;
    d[v] = cur;
    usd[v] = 1;
    for (auto &to : g[v]) {
        if (!usd[to]) dfs(to, v, cur + 1);
    }
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        d.assign(n, 0);
        g.clear();
        g.resize(n);
        par.assign(n, 0);
        usd.assign(n, 0);
        int k = (n + 1) / 2;
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b; a--; b--;
            g[a].pb(b);
            g[b].pb(a);
        }
        dfs(0, -1, 0);
        int mx = -1, v = -1;
        for (int i = 0; i < n; i++) {
            if (d[i] > mx) {
                mx = d[i];
                v = i;
            }
        }
        if (mx >= k - 1) {
            cout << "PATH\n";
            cout << mx + 1 << "\n";
            vector<int> path;
            while (v != -1) {
                path.pb(v);
                v = par[v];
            }
            for (auto &c : path) cout << c + 1 << " ";
            cout << "\n";
        } else {
            cout << "PAIRING\n";
            vector<vector<int>> kek(mx + 1);
            for (int i = 0; i < n; i++) kek[d[i]].pb(i);
            vector<pii> ans;
            for (auto &c : kek) {
                while ((int)c.size() >= 2) {
                    ans.pb(c.back(), c[c.size() - 2]);
                    c.pop_back();
                    c.pop_back();
                }
            }
            cout << ans.size() << "\n";
            for (auto &c : ans) cout << c.fi + 1 << " " << c.se + 1 << "\n";
        }
    }
    return 0;
}