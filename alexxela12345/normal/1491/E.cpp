#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;


int n;
vector<vector<pair<int, int>>> g;
vector<int> used;

int dfs(int v, int p, int f0, int f1) {
    if (f0 + f1 <= 3) {
        return -1;
    }
    int sz = 1;
    for (auto pp : g[v]) {
        if (used[pp.second] || pp.first == p) {
            continue;
        }
        int u = pp.first;
        int szu = dfs(u, v, f0, f1);
        if (szu == -1) {
            return -1;
        }
        if (szu == 1e9) {
            return szu;
        }
        if (szu == f0 || szu == f1) {
            used[pp.second] = 1; 
            if (szu == f0) {
                if (dfs(u, -1, 2 * f0 - f1, f1 - f0) == -1 && dfs(v, -1, f1 - f0, f0) == -1) {
                    return -1;
                }
            } else {
                swap(u, v);
                if (dfs(u, -1, 2 * f0 - f1, f1 - f0) == -1 && dfs(v, -1, f1 - f0, f0) == -1) {
                    return -1;
                }
            }
            return 1e9;
        }
        sz += szu;
    }
    return sz;
}

void solve() {
    cin >> n;
    g.resize(n);
    used.resize(n - 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back({b, i});
        g[b].push_back({a, i});
    }
    int f0 = 1;
    int f1 = 1;
    if (n < 3) {
        cout << "YES" << endl;
        return;
    }
    while (f0 + f1 < n) {
        f0 += f1;
        swap(f0, f1);
    }
    if (f0 + f1 != n) {
        cout << "NO" << endl;
        return;
    }
    if (dfs(0, -1, f0, f1) == -1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
}