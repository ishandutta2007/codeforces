#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cassert>
#include <map>
#include <set>
#include <cmath>

using namespace std;
const int MAXP = 5000;

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int n, m;
    cin >> n >> m;
    vector <int> p(n), c(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i]; --c[i];
    }
    int d;
    cin >> d;
    vector <bool> del(n);
    vector <int> num(d);
    for (int i = 0; i < d; ++i) {
        int x;
        cin >> x; --x;
        del[x] = true;
        num[i] = x;
    }
    vector <vector <int>> g(MAXP + m);
    vector <int> ans(MAXP + m, -1), used(MAXP + m, -1);
    int lvl = 0, mex = 0;

    function <bool(int)> dfs = [&](int v) {
        if (used[v] == lvl) return false;
        used[v] = lvl;
        for (int i : g[v]) {
            if (ans[i] == -1) {
                ans[i] = v;
                return true;
            }
        }
        for (int i : g[v]) {
            if (dfs(ans[i])) {
                ans[i] = v;
                return true;
            }
        }
        return false;
    };

    auto add_man = [&](int v) {
        g[p[v]].push_back(MAXP + c[v]);
        while (mex < MAXP && dfs(mex)) {
            ++mex;
            ++lvl;
        }
        ++lvl;
    };

    for (int i = 0; i < n; ++i) {
        if (!del[i]) add_man(i);
    }
    vector <int> res(d);
    res.back() = mex;
    for (int i = d - 1; i > 0; --i) {
        add_man(num[i]);
        res[i - 1] = mex;
    }
    for (int i = 0; i < d; ++i) cout << res[i] << "\n";
}

/*

 */