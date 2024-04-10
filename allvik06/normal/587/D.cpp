#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cassert>
#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <random>
#include <iomanip>
#include <chrono>

using namespace std;
const int INF = 1e9 + 1;

struct two_sat {
    int n;
    vector <vector <int>> g, rg;

    two_sat(int n) : n(n) {
        g.resize(n);
        rg.resize(n);
    }

    inline void add(int x, int y) {
        g[x].push_back(y);
        g[y ^ 1].push_back(x ^ 1);
        rg[y].push_back(x);
        rg[x ^ 1].push_back(y ^ 1);
    }

    void dfs(int v, vector <int>& ord, vector <int>& used) {
        used[v] = 1;
        for (int i : g[v]) {
            if (used[i]) continue;
            dfs(i, ord, used);
        }
        ord.push_back(v);
    }

    void set_cmp(int v, vector <int>& used, vector <int>& cmp, int lvl) {
        cmp[v] = lvl;
        used[v] = 2;
        for (int i : rg[v]){
            if (used[i] == 1) {
                set_cmp(i, used, cmp, lvl);
            }
        }
    }

    vector <int> solve() {
        vector <int> ord, used(n);
        for (int i = 0; i < n; ++i) {
            if (!used[i]) dfs(i, ord, used);
        }
        reverse(ord.begin(), ord.end());
        vector <int> cmp(n, -1);
        int cur = 0;
        for (int i : ord) {
            if (used[i] == 2) continue;
            set_cmp(i, used, cmp, cur++);
        }
        vector <int> result;
        for (int i = 0; i < n; i += 2) {
            if (cmp[i] == cmp[i ^ 1]) return {-1};
        }
        for (int i = 0; i < n / 6; ++i) {
            if (cmp[2 * i + 1] < cmp[2 * i]) result.push_back(i);
        }
        return result;
    }
};

inline bool check(int n, const vector <array <int, 4>>& a, int cost = -1, bool print_ans = false) {
    int m = (int)a.size();
    two_sat flex(6 * m);
    int cur = 2 * m;
    vector <vector <int>> g(n);
    for (int i = 0; i < m; ++i) {
        g[a[i][0]].push_back(i);
        g[a[i][1]].push_back(i);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < (int)g[i].size(); ++j) {
            flex.add(g[i][j] * 2, cur + j * 2);
            if (j < (int)g[i].size() - 1) {
                flex.add(cur + j * 2, cur + j * 2 + 2);
                flex.add(cur + j * 2, g[i][j + 1] * 2 + 1);
            }
        }
        cur += (int)g[i].size() * 2;
    }
    for (int i = 0; i < m; ++i) {
        if (a[i][3] > cost) {
            flex.add(2 * i, 2 * i + 1);
        }
    }
    for (int i = 0; i < n; ++i) {
        map <int, int> now;
        bool f = false;
        for (int j : g[i]) {
            if (now.count(a[j][2])) {
                if (f) return false;
                f = true;
                flex.add(2 * j + 1, 2 * now[a[j][2]]);
            } else now[a[j][2]] = j;
        }
    }
    auto ans = flex.solve();
    if (ans == vector <int>(1, -1)) return false;
    if (print_ans) {
        cout << "Yes\n" << cost << " " << (int)ans.size() << "\n";
        for (int i : ans) cout << i + 1 << " ";
    }
    return true;
}

inline void solve() {
    int n, m;
    cin >> n >> m;
    vector <array <int, 4>> all(m);
    for (int i = 0; i < m; ++i) {
        int x, y, w, c;
        cin >> x >> y >> c >> w; --x; --y;
        all[i] = {x, y, c, w};
    }
    int l = -1, r = INF;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (check(n, all, mid)) r = mid;
        else l = mid;
    }
    if (r == INF) cout << "No";
    else {
        check(n, all, r, true);
    }
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    if (1) {
        solve();
    } else {

    }
}

/*

 */