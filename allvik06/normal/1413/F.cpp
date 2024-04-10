#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <array>
#include <algorithm>
#include <cmath>

using namespace std;
vector <vector <int>> g;

void calc_gl(int v, int p, vector <int>& gl) {
    for (int i : g[v]) {
        if (i == p) continue;
        gl[i] = gl[v] + 1;
        calc_gl(i, v, gl);
    }
}

void calc_oth(int v, int p, vector <int>& sz, vector <int>& num, int& now) {
    num[v] = now++;
    for (int i : g[v]) {
        if (i == p) continue;
        calc_oth(i, v, sz, num, now);
        sz[v] += sz[i];
    }
}

struct SegTree {
    int n;
    vector <pair <int, int>> t;
    vector <int> p;

    SegTree(int n, vector <int>& gl, vector <int>& num) : n(n) {
        t.resize(4 * n);
        p.resize(4 * n);
        vector <int> gg(n);
        for (int i = 0; i < n; ++i) gg[num[i]] = gl[i];
        build(1, 0, n - 1, gg);
    }

    void build(int v, int l, int r, vector <int>& gg) {
        if (l == r) {
            t[v].first = gg[l];
            return;
        }
        int m = (l + r) / 2;
        build(2 * v, l, m, gg);
        build(2 * v + 1, m + 1, r, gg);
        t[v].first = max(t[2 * v].first, t[2 * v + 1].first);
    }

    inline void push(int v) {
        if (p[v] == 0) return;
        swap(t[2 * v].first, t[2 * v].second);
        swap(t[2 * v + 1].first, t[2 * v + 1].second);
        p[2 * v] ^= 1;
        p[2 * v + 1] ^= 1;
        p[v] = 0;
    }

    void update(int v, int l, int r, int A, int B) {
        if (l > B || A > r) return;
        if (A <= l && r <= B) {
            swap(t[v].first, t[v].second);
            p[v] ^= 1;
            return;
        }
        push(v);
        int m = (l + r) / 2;
        update(2 * v, l, m, A, B);
        update(2 * v + 1, m + 1, r, A, B);
        t[v].first = max(t[2 * v].first, t[2 * v + 1].first);
        t[v].second = max(t[2 * v].second, t[2 * v + 1].second);
    }

    void update(int l, int r) {
        update(1, 0, n - 1, l, r);
    }
};

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int n;
    cin >> n;
    vector <array <int, 3>> all(n - 1);
    g.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < 3; ++j) cin >> all[i][j];
        --all[i][0];
        --all[i][1];
        g[all[i][0]].push_back(all[i][1]);
        g[all[i][1]].push_back(all[i][0]);
    }
    vector <int> gl(n);
    calc_gl(0, -1, gl);
    int f = max_element(gl.begin(), gl.end()) - gl.begin();
    gl[f] = 0;
    calc_gl(f, -1, gl);
    int s = max_element(gl.begin(), gl.end()) - gl.begin(), now1 = 0, now2 = 0;
    vector <int> gl1(n), sz1(n, 1), num1(n), gl2(n), sz2(n, 1), num2(n);
    calc_gl(f, -1, gl1);
    calc_gl(s, -1, gl2);
    calc_oth(f, -1, sz1, num1, now1);
    calc_oth(s, -1, sz2, num2, now2);
    SegTree t1(n, gl1, num1), t2(n, gl2, num2);
    for (auto i : all) {
        if (i[2]) {
            if (gl1[i[0]] < gl1[i[1]]) t1.update(num1[i[1]], num1[i[1]] + sz1[i[1]] - 1);
            else t1.update(num1[i[0]], num1[i[0]] + sz1[i[0]] - 1);
            if (gl2[i[0]] < gl2[i[1]]) t2.update(num2[i[1]], num2[i[1]] + sz2[i[1]] - 1);
            else t2.update(num2[i[0]], num2[i[0]] + sz2[i[0]] - 1);
        }
    }
    int m;
    cin >> m;
    while (m--) {
        int ind;
        cin >> ind; --ind;
        auto i = all[ind];
        if (gl1[i[0]] < gl1[i[1]]) t1.update(num1[i[1]], num1[i[1]] + sz1[i[1]] - 1);
        else t1.update(num1[i[0]], num1[i[0]] + sz1[i[0]] - 1);
        if (gl2[i[0]] < gl2[i[1]]) t2.update(num2[i[1]], num2[i[1]] + sz2[i[1]] - 1);
        else t2.update(num2[i[0]], num2[i[0]] + sz2[i[0]] - 1);
        cout << max(t1.t[1].first, t2.t[1].first) << "\n";
    }
}