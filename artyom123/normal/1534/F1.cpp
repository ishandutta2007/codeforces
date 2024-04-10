#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double
#define mp make_pair
#define ull unsigned long long

const int INF = 1e9 + 1;
const ll INFLL = (ll)1e18 + 1;
const ll mod = 1e9 + 7;

void dfs(int v, vector<int> &usd, vector<vector<int>> &g, vector<int> &a) {
    usd[v] = 1;
    for (auto &to : g[v]) {
        if (!usd[to]) dfs(to, usd, g, a);
    }
    a.pb(v);
}

int solve(vector<vector<int>> g) {
    int n = g.size();
    vector<vector<int>> gr(n);
    for (int i = 0; i < n; i++) {
        for (auto &to : g[i]) gr[to].pb(i);
    }
    vector<int> ts;
    vector<int> usd(n);
    for (int i = 0; i < n; i++) {
        if (!usd[i]) {
            dfs(i, usd, g, ts);
        }
    }
    reverse(all(ts));
    usd.assign(n, 0);
    int cur_id = 0;
    vector<int> id(n);
    vector<vector<int>> comp;
    for (auto &v : ts) {
        if (usd[v]) continue;
        vector<int> now;
        dfs(v, usd, gr, now);
        for (auto &c : now) id[c] = cur_id;
        comp.pb(now);
        cur_id++;
    }
    int ans = 0;
    for (auto &c : comp) {
        bool ok = 1;
        for (auto &v : c) {
            for (auto &to : gr[v]) {
                if (id[to] != id[v]) ok = 0;
            }
        }
        ans += ok;
    }
    return ans;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (auto &c : a) cin >> c;
    int cnts = 0;
    vector<vector<int>> ma(n, vector<int>(m, -1));
    vector<set<int>> b(m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '#') ma[i][j] = cnts++;
            if (a[i][j] == '#') b[j].insert(i);
        }
    }
    vector<vector<int>> g(cnts);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '#') {
                if (i - 1 >= 0 && a[i - 1][j] == '#') g[ma[i][j]].pb(ma[i - 1][j]);
                auto it = b[j].upper_bound(i);
                if (it != b[j].end()) g[ma[i][j]].pb(ma[*it][j]);
                if (j > 0) {
                    it = b[j - 1].lower_bound(i);
                    if (it != b[j - 1].end()) g[ma[i][j]].pb(ma[*it][j - 1]);
                }
                if (j + 1 < m) {
                    it = b[j + 1].lower_bound(i);
                    if (it != b[j + 1].end()) g[ma[i][j]].pb(ma[*it][j + 1]);
                }
            }
        }
    }
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
    }
    cout << solve(g);
    return 0;
}