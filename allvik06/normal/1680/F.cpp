#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cassert>

using namespace std;
const int INF = 1e9;
int n;
vector <vector <int>> g;
vector <int> gl, used;

void find_gl(int v) {
    used[v] = 1;
    for (int i : g[v]) {
        if (used[i] == 1) continue;
        gl[i] = gl[v] + 1;
        find_gl(i);
    }
}

inline bool check_simple() {
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        int ti = (gl[i] & 1) ^ 1;
        for (int j : g[i]) {
            int tj = (gl[j] & 1) ^ 1;
            if (ti == 0 && tj == 0) cnt = 3;
            if (ti == 1 && tj == 1) ++cnt;
        }
    }
    if (cnt <= 2) {
        cout << "YES\n";
        for (int i = 0; i < n; ++i) {
            if (gl[i] % 2 == 0) cout << 1;
            else cout << 0;
        }
        cout << "\n";
        return true;
    }
    return false;
}

struct vrt {
    int mn[2][2];
    int mx[2][2];

    vrt() {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                mn[i][j] = INF;
                mx[i][j] = -INF;
            }
        }
    }
};

vector <vrt> dp;

void merge(vrt& a, const vrt& b) {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            a.mn[i][j] = min(a.mn[i][j], b.mn[i][j]);
            a.mx[i][j] = max(a.mx[i][j], b.mx[i][j]);
        }
    }
}

void calc_dp(int v) {
    for (int i : g[v]) {
        if (gl[i] == gl[v] - 1) continue;
        if (gl[i] == gl[v] + 1) {
            calc_dp(i);
            merge(dp[v], dp[i]);
        }
        if (gl[i] < gl[v]) {
            int tv = (gl[v] & 1);
            int ti = (gl[i] & 1);
            dp[v].mn[tv][ti] = min(dp[v].mn[tv][ti], gl[i]);
            dp[v].mx[tv][ti] = max(dp[v].mx[tv][ti], gl[i]);
        }
    }
}

void set_ans(int v, vector <int>& ans) {
    if (gl[v] % 2 == 0) ans[v] = 0;
    else ans[v] = 1;
    for (int i : g[v]) {
        if (gl[i] == gl[v] + 1) set_ans(i, ans);
    }
}

bool find_ans(int v) {
    if (gl[v] % 2 == 0) {
        int cnt = 0;
        for (int i : g[v]) {
            if (gl[i] == gl[v] - 1) continue;
            if (gl[i] == gl[v] + 1) {
                if (dp[i].mn[0][0] != INF || dp[i].mn[1][1] != INF) ++cnt;
            }
            if (gl[i] < gl[v] && gl[i] % 2 == 0) return false;
        }
        if (cnt >= 2) return false;
        assert(cnt == 1);
        for (int i : g[v]) {
            if (gl[i] == gl[v] + 1) {
                if (dp[i].mn[0][0] != INF || dp[i].mn[1][1] != INF) {
                    if (find_ans(i)) return true;
                }
            }
        }
        return false;
    }
    if (dp[v].mx[1][1] < gl[v] && dp[v].mn[1][0] > gl[v] && dp[v].mx[0][0] < gl[v] && dp[v].mn[0][1] >= gl[v]) {
        vector <int> ans(n);
        for (int i = 0; i < n; ++i) {
            if (gl[i] % 2 == 0) ans[i] = 1;
        }
        set_ans(v, ans);
        cout << "YES\n";
        for (int i = 0; i < n; ++i) cout << ans[i];
        cout << "\n";
        return true;
    }
    int cnt = 0;
    for (int i : g[v]) {
        if (gl[i] == gl[v] - 1) continue;
        if (gl[i] == gl[v] + 1) {
            if (dp[i].mn[0][0] != INF || dp[i].mn[1][1] != INF) ++cnt;
        }
        if (gl[i] < gl[v] && gl[i] % 2 == 1) return false;
    }
    if (cnt >= 2) return false;
    assert(cnt == 1);
    for (int i : g[v]) {
        if (gl[i] == gl[v] + 1) {
            if (dp[i].mn[0][0] != INF || dp[i].mn[1][1] != INF) {
                if (find_ans(i)) return true;
            }
        }
    }
    return false;
}

inline bool solve_root(int root) {
    gl.assign(n, 0);
    used.assign(n, 0);
    find_gl(root);
    if (check_simple()) return true;
    dp.assign(n, {});
    calc_dp(root);
    if (find_ans(root)) return true;
    return false;
}

void solve() {
    int m;
    cin >> n >> m;
    g.assign(n, {});
    int root1, root2;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y; --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
        root1 = x;
        root2 = y;
    }
    if (solve_root(root1)) return;
    if (solve_root(root2)) return;
    cout << "NO\n";
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

/*
 1
6 8
4 5
5 6
2 5
1 6
3 1
6 3
1 5
3 2

 YES
110101

 */