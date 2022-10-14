#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back

const long long INF = 1e18 + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    vector<int> t(n);
    for (auto &c : t) cin >> c;
    vector<pair<int, int>> order(n);
    for (int i = 0; i < n; i++) {
        order[i] = {t[i], i};
    }
    sort(all(order));
    vector<int> ans;
    for (auto &c : order) ans.pb(c.se + 1);
    vector<int> color(n);
    for (auto &c : order) {
        set<int> now;
        for (auto &to : g[c.se]) now.insert(color[to]);
        for (int p = 1; ; p++) {
            if (now.find(p) == now.end()) {
                if (c.fi != p) {
                    cout << -1;
                    return 0;
                }
                color[c.se] = p;
                break;
            }
        }
    }
    for (auto &c : ans) cout << c << " ";
    return 0;
}