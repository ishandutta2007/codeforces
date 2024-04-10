#include <bits/stdc++.h>

using namespace std;

void solve_case(int tc = 0) {
    int n; cin >> n;

    vector<vector<int>> g(n);
    vector<vector<int>> og(n);

    for (int i = 1; i < n; ++i) {
        int p; cin >> p;
        --p;
        g[p].push_back(i);
    }

    for (int i = 1; i < n; ++i) {
        int p; cin >> p;
        --p;
        og[p].push_back(i);
    }

    vector<int> in(n);
    vector<int> out(n);

    int ti = 0;
    
    function<void(int)> dfs_time = [&](int u) {
        in[u] = ti++;
        for (auto& v : og[u]) 
            dfs_time(v);
        out[u] = ti;
    };

    dfs_time(0);

    set<pair<int, int>> ivals;

    auto is_bad = [&](pair<int, int> x) -> bool { // contains smth else
        if (ivals.empty()) return false;
        auto it = ivals.lower_bound(x);
        if (it == ivals.end()) return false;
        if (it->second <= x.second) return true;
        return false;
    };
    
    auto is_leaf = [&](int x) -> bool { 
        if (x == 0) return false;
        if (g[x].empty()) return true;
        return false;
    };

    auto inside = [&](pair<int, int> x) -> pair<int, int> {
        if (ivals.empty()) return {-1, -1}; 
        auto it = ivals.upper_bound(x);
        if (it == ivals.begin()) return {-1, -1};
        it = prev(it);
        if (it->second >= x.second) return *it;
        return {-1, -1};
    };
    
    int ans = 0;

    function<void(int)> dfs = [&](int u) {
        pair<int, int> x = {in[u], out[u]};
        pair<int, int> rem = {-1, -1};
        bool added = false;
        if (!is_bad(x)) {
            added = true;
            rem = inside(x);
            if (rem.first != -1) 
                ivals.erase(rem);
            ivals.insert(x);
        }
        if (is_leaf(u)) 
            ans = max(ans, (int)ivals.size());
        for (auto& v : g[u]) 
            dfs(v);
        if (added) 
            ivals.erase(x);
        if (rem.first != -1) 
            ivals.insert(rem);
    };

    dfs(0);

    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tt = 1; cin >> tt;
    for (int tc = 1; tc <= tt; ++tc) solve_case(tc);
    return 0;
}