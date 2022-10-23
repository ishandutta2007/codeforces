#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v, x;
        cin >> u >> v >> x;
        --u, --v;
        g[u].emplace_back(v, x);
        g[v].emplace_back(u, x);
    }

    long long ans = 0;
    vector<vector<tuple<int, int, int>>> stacks(n + 1);
    auto f = [&](int x, int l, int r) {
        auto &st = stacks[x];
        int sum = 0;
        int v = r - l;
        while (st.size()) {
            auto [l2, r2, v2] = st.back();
            if (r2 <= l) break;
            sum += v2;
            v -= r2 - l2;
            st.pop_back();
        }
        ans += (long long) v * sum;
        st.emplace_back(l, r, v);
    };

    auto dfs = [&](auto dfs, int u, int p, int px, int &t) -> void {
        int l = t++;
        for (auto [v, x] : g[u]) if (v != p) dfs(dfs, v, u, x, t);
        if (px >= 0) f(px, l, t);
    };
    int t = 0;
    dfs(dfs, 0, -1, -1, t);
    for (int x = 1; x <= n; ++x) f(x, 0, n);
    cout << ans << endl;
    return 0;
}