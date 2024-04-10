#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double

const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;

vector<vector<int>> g;

int ans = 0;

int dfs(int v, int p) {
    vector<int> val;
    for (auto &to : g[v]) {
        if (to == p) continue;
        val.pb(dfs(to, v));
    }
    sort(all(val));
    if (val.empty()) return 1;
    if (v != 0) {
        ans = max(ans, val.back() + 1);
        return val[0] + 1;
    } else {
        ans = max(ans, val.back());
        if ((int)val.size() > 1) ans = max(ans, val[(int)val.size() - 2] + 1);
        return 0;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        g.clear();
        g.resize(n);
        ans = 0;
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b; a--; b--;
            g[a].pb(b);
            g[b].pb(a);
        }
        dfs(0, -1);
        cout << ans << "\n";
    }
    return 0;
}