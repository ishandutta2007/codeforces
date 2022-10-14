#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long

const int INF = 1e9 + 1;
const long long INFLL = 1e18 + 1;

bool IS_MULTITEST = 0;

void dfs_color(int v, vector<int> &col, vector<vector<int>> &g) {
    for (auto &to : g[v]) {
        if (col[to]) continue;
        col[to] = 3 - col[v];
        dfs_color(to, col, g);
    }
}

bool f = false;

vector<int> cycle, usd;

void dfs(int v, int p, vector<int> &st, vector<vector<int>> &g) {
    usd[v] = 1;
    st.pb(v);
    for (auto &to : g[v]) {
        if (to == p) continue;
        if (!usd[to]) {
            dfs(to, v, st, g);
            continue;
        }
        if (f) continue;
        f = true;
        cycle.pb(to);
        while (st.back() != to) {
            cycle.pb(st.back());
            st.pop_back();
        }
    }
    if (st.size()) st.pop_back();
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--; b--;
        g[a].pb(b); g[b].pb(a);
    }
    if (m == n - 1) { /// tree
        vector<int> col(n);
        col[0] = 1;
        dfs_color(0, col, g);
        vector<int> cnt1, cnt2;
        for (int i = 0; i < n; i++) {
            if (col[i] == 1) cnt1.pb(i);
            else cnt2.pb(i);
        }
        if (cnt1.size() >= cnt2.size()) {
            cout << 1 << "\n";
            for (int i = 0; i < (k + 1) / 2; i++) cout << cnt1[i] + 1 << " ";
        } else {
            cout << 1 << "\n";
            for (int i = 0; i < (k + 1) / 2; i++) cout << cnt2[i] + 1 << " ";
        }
        return;
    }
    /// cycle
    vector<int> st;
    usd.resize(n);
    dfs(0, -1, st, g);
    int l = 0, r = cycle.size() - 1;
    vector<int> ind(n, INF);
    for (int i = 0; i < (int)cycle.size(); i++) ind[cycle[i]] = i;
    for (int i = 0; i < r; i++) {
        int mn = INF;
        for (auto &to : g[cycle[i]]){
            if (ind[to] > i + 1) mn = min(mn, ind[to]);
        }
        if (mn > r) continue;
        l = i, r = mn;
    }
    if (r - l + 1 <= k) {
        cout << 2 << "\n";
        cout << r - l + 1 << "\n";
        for (int i = l; i <= r; i++) cout << cycle[i] + 1 << " ";
        return;
    }
    cout << 1 << "\n";
    int cnt = 0;
    for (int i = l; i <= r && cnt < (k + 1) / 2; i++) {
        if (i % 2 == l % 2) {
            cout << cycle[i] + 1 << " ";
            cnt++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    if (IS_MULTITEST) cin >> t;
    while (t--) solve();
    return 0;
}