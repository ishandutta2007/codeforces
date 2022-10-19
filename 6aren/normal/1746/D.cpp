#include <bits/stdc++.h>

using namespace std;

#define int long long

#ifdef LOCAL
#include<cp/debugger.hpp>
#else 
#define debug(...) 42
#endif

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
        int u;
        cin >> u;
        u--;
        g[u].push_back(i);
    }
    vector<int> s(n);
    for (int &e : s) {
        cin >> e;
    }

    map<pair<int, int>, int> cache; 
    
    function<int(int, int)> solve = [&](int u, int k) {
        if (cache.find(make_pair(u, k)) != cache.end()) return cache[make_pair(u, k)];
        if (g[u].size() == 0) {
            cache[make_pair(u, k)] = k * s[u];
        } else if (g[u].size() == 1) {
            cache[make_pair(u, k)] = solve(g[u][0], k) + k * s[u];
        } else {
            int x = k / g[u].size();
            int y = k / g[u].size() + 1;
            int sum = 0;
            vector<int> tmp;
            for (int e : g[u]) {
                int xx = solve(e, x);
                int yy = solve(e, y);
                sum += xx;
                tmp.push_back(yy - xx);
            }
            sort(tmp.rbegin(), tmp.rend());
            for (int i = 0; i < k % g[u].size(); i++) {
                sum += tmp[i];
            }
            cache[make_pair(u, k)] = sum + k * s[u];
        }
        return cache[make_pair(u, k)];
    };
    cout << solve(0, k) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}