#include <iostream>
#include <random>
#include <vector>
#include <iomanip>
#include <cassert>
#include <bitset>
#include <map>
#include <algorithm>
#include <set>
#include <cmath>
#include <random>
#include <array>

using namespace std;
#define int long long
const int MAXL = 17;
vector <vector <int>> g, bp;
vector <int> gl, sz, num, last, st, cycle, pos;
vector <bool> used, on_cycle;

bool dfs0(int v, int pr) {
    used[v] = true;
    st.push_back(v);
    for (int i : g[v]) {
        if (i == pr) continue;
        if (used[i]) {
            while (!st.empty()) {
                on_cycle[st.back()] = true;
                cycle.push_back(st.back());
                if (st.back() == i) return true;
                st.pop_back();
            }
        } else if (dfs0(i, v)) return true;
    }
    st.pop_back();
    return false;
}

void dfs1(int v, int p) {
    bp[0][v] = p;
    sz[v] = 1;
    for (int i : g[v]) {
        if (i == p || on_cycle[i]) continue;
        gl[i] = gl[v] + 1;
        dfs1(i, v);
        sz[v] += sz[i];
    }
}

void dfs2(int v, int& last_ind) {
    num[v] = last_ind;
    ++last_ind;
    int maxx_sz = 0, ind = -1;
    for (int i = 0; i < (int)g[v].size(); ++i) {
        if (g[v][i] == bp[0][v] || on_cycle[g[v][i]]) continue;
        if (sz[g[v][i]] > maxx_sz) {
            maxx_sz = sz[g[v][i]];
            ind = i;
        }
    }
    if (ind == -1) return;
    swap(g[v][0], g[v][ind]);
    for (int i = 0; i < (int)g[v].size(); ++i) {
        if (g[v][i] == bp[0][v] || on_cycle[g[v][i]]) continue;
        if (i == 0) {
            last[g[v][i]] = last[v];
        } else {
            last[g[v][i]] = g[v][i];
        }
        dfs2(g[v][i], last_ind);
    }
}

inline void build_bp(int n) {
    for (int i = 1; i < MAXL; ++i) {
        for (int j = 0; j < n; ++j) {
            bp[i][j] = bp[i - 1][bp[i - 1][j]];
        }
    }
}

inline int parent(int v, int k) {
    for (int i = MAXL - 1; i >= 0; --i) {
        if ((1 << i) <= k) {
            k -= (1 << i);
            v = bp[i][v];
        }
    }
    return v;
}

inline int lca(int a, int b) {
    if (gl[a] < gl[b]) swap(a, b);
    a = parent(a, gl[a] - gl[b]);
    if (a == b) return a;
    for (int i = MAXL - 1; i >= 0; --i) {
        if (bp[i][a] != bp[i][b]) {
            a = bp[i][a];
            b = bp[i][b];
        }
    }
    return bp[0][a];
}

struct SegTree {
    int len;
    vector <int> t, p;

    SegTree(int n) {
        len = (1 << (int)ceil(log2(n)));
        t.resize(4 * n);
        p.resize(4 * n);
    }

    inline void push(int v, int l, int r) {
        if (p[v] == 0) return;
        p[2 * v] ^= 1;
        p[2 * v + 1] ^= 1;
        t[2 * v] = (r - l + 1) / 2 - t[2 * v];
        t[2 * v + 1] = (r - l + 1) / 2 - t[2 * v + 1];
        p[v] = 0;
    }

    void update(int v, int l, int r, int A, int B) {
        if (l > B || A > r) return;
        if (A <= l && r <= B) {
            t[v] = r - l + 1 - t[v];
            p[v] ^= 1;
            return;
        }
        push(v, l, r);
        int m = (l + r) / 2;
        update(2 * v, l, m, A, B);
        update(2 * v + 1, m + 1, r, A, B);
        t[v] = t[2 * v] + t[2 * v + 1];
    }

    inline void update(int l, int r) {
        update(1, 0, len - 1, l, r);
    }

    int get_ans(int v, int l, int r, int A, int B) {
        if (l > B || A > r) return 0;
        if (A <= l && r <= B) return t[v];
        push(v, l, r);
        int m = (l + r) / 2;
        return get_ans(2 * v, l, m, A, B) + get_ans(2 * v + 1, m + 1, r, A, B);
    }

    inline int get_ans(int l, int r) {
        return get_ans(1, 0, len - 1, l, r);
    }
};

inline void update_single_path(int a, int root, SegTree& t) {
    while (true) {
        if (last[a] == root) {
            t.update(num[root] + 1, num[a]);
            break;
        }
        t.update(num[last[a]], num[a]);
        a = bp[0][last[a]];
    }
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int n, q;
    cin >> n >> q;
    g.resize(n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y; --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    used.resize(n);
    on_cycle.resize(n);
    dfs0(0, -1);
    gl.resize(n);
    sz.resize(n);
    bp.resize(MAXL, vector <int> (n + 1, n));
    for (int i : cycle) {
        dfs1(i, n);
    }
    num.resize(n);
    last.resize(n);
    int last_ind = 0;
    for (int i : cycle) {
        last[i] = i;
        dfs2(i, last_ind);
    }
    build_bp(n);
    SegTree t(n);
    SegTree ct(n);
    pos.resize(n, -1);
    for (int i = 0; i < (int)cycle.size(); ++i) pos[cycle[i]] = i;
    int cur_sum_trees = 0;
    while (q--) {
        int a, b;
        cin >> a >> b; --a; --b;
        int a_root = parent(a, gl[a]), b_root = parent(b, gl[b]);
        if (a_root == b_root) {
            cur_sum_trees -= t.get_ans(num[a_root] + 1, num[a_root] + sz[a_root] - 1);
            update_single_path(a, a_root, t);
            update_single_path(b, a_root, t);
            cur_sum_trees += t.get_ans(num[a_root] + 1, num[a_root] + sz[a_root] - 1);
        } else {
            cur_sum_trees -= t.get_ans(num[a_root] + 1, num[a_root] + sz[a_root] - 1);
            update_single_path(a, a_root, t);
            cur_sum_trees += t.get_ans(num[a_root] + 1, num[a_root] + sz[a_root] - 1);
            cur_sum_trees -= t.get_ans(num[b_root] + 1, num[b_root] + sz[b_root] - 1);
            update_single_path(b, b_root, t);
            cur_sum_trees += t.get_ans(num[b_root] + 1, num[b_root] + sz[b_root] - 1);
            int right_len, left_len;
            if (pos[a_root] < pos[b_root]) {
                right_len = pos[b_root] - pos[a_root];
                left_len = pos[a_root] + (int)cycle.size() - pos[b_root];
            } else {
                left_len = pos[a_root] - pos[b_root];
                right_len = pos[b_root] + (int)cycle.size() - pos[a_root];
            }
            bool ord_left = false;
            if (left_len < right_len) ord_left = true;
            else if (left_len == right_len && cycle[(pos[a_root] - 1 + (int)cycle.size()) % (int)cycle.size()] < cycle[(pos[a_root] + 1) % (int)cycle.size()]) ord_left = true;
            if (ord_left) {
                if (pos[a_root] > pos[b_root]) ct.update(pos[b_root] + 1, pos[a_root]);
                else {
                    ct.update(0, pos[a_root]);
                    ct.update(pos[b_root] + 1, (int)cycle.size() - 1);
                }
            } else {
                if (pos[a_root] < pos[b_root]) ct.update(pos[a_root] + 1, pos[b_root]);
                else {
                    ct.update(pos[a_root] + 1, (int)cycle.size() - 1);
                    ct.update(0, pos[b_root]);
                }
            }
        }
        cout << n - cur_sum_trees - min((int)cycle.size() - 1, ct.get_ans(0, (int)cycle.size() - 1)) << "\n";
    }
    return 0;
}

/*
 6 4
6 3
4 3
1 5
1 2
5 4
5 6
1 1
3 3
5 2
5 6

 */