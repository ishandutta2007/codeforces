#pragma GCC optimize("Ofast,unroll-loops,fast-math,inline,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,abm,mmx,popcnt")
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef long double ldb;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    unordered_set<int> premb = {0};
    unordered_set<int> studs;
    vector<int> used(n);
    while (!premb.empty() || !studs.empty()) {
        if (!premb.empty()) {
            int v = *premb.begin();
            premb.erase(v);
            used[v] = 1;
            for (int u : g[v]) {
                premb.erase(u);
                if (used[u] == 0) {
                    used[u] = 2;
                    studs.insert(u);
                } else if (used[u] == 1) {
                    assert(false);
                } else {
                    used[u] = 2;
                }
            }
        } else {
            int v = *studs.begin();
            studs.erase(v);
            for (int u : g[v]) {
                if (used[u] == 0) {
                    premb.insert(u);
                }
            }
        }
    }
    bool good = 1;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            good = 0;
            break;
        }
        if (used[i] == 1)
            cnt++;
    }
    if (!good) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        cout << cnt << endl;
        for (int i = 0; i < n; i++) {
            if (used[i] == 1) {
                cout << i + 1 << " ";
            }
        }
        cout << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // coment next line if there is only one test
    cin >> t;

    while (t--) {
        solve();
    }
}