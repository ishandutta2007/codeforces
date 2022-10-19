#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <bits/stdc++.h>

using namespace std;

#define int long long

const int INF = 1e18;

template <typename T>
struct seg_tree {

    vector<T> t;
    vector<T> to_add;

    size_t main_size;

    void build(int v, int L, int R, vector<int> & a) {
        if (L == R - 1)
            t[v] = a[L];
        else {
            int M = (L + R) / 2;
            build(2 * v + 1, L, M, a);
            build(2 * v + 2, M, R, a);
            t[v] = min(t[2 * v + 1], t[2 * v + 2]);
        }
    }

    void push(int v) {
        t[v] += to_add[v];
        if (2 * v + 1 < 4 * main_size)
            to_add[2 * v + 1] += to_add[v];
        if (2 * v + 2 < 4 * main_size)
            to_add[2 * v + 2] += to_add[v];
        to_add[v] = 0;
    }

    void update(int v, int L, int R, int i, int x) {
        push(v);
        if (R <= i || L > i)
            return;
        else if (L == R - 1)
            t[v] = x;
        else {
            int M = (L + R) / 2;
            update(2 * v + 1, L, M, i, x);
            update(2 * v + 2, M, R, i, x);
            t[v] = min(t[2 * v + 1], t[2 * v + 2]);
        }
    }

    void update(int i, int x) {
        update(0, 0, main_size, i, x);
    }

    void seg_add(int v, int L, int R, int l, int r, int x) {
        push(v);
        if (R <= l || r <= L)
            return;
        else if (l <= L && R <= r)
            to_add[v] += x;
        else {
            int M = (L + R) / 2;
            seg_add(2 * v + 1, L, M, l, r, x);
            seg_add(2 * v + 2, M, R, l, r, x);
            push(2 * v + 1);
            push(2 * v + 2);
            t[v] = min(t[2 * v + 1], t[2 * v + 2]);
        }
    }

    void seg_add(int l, int r, int x) {
        return seg_add(0, 0, main_size, l, r, x);
    }

    int seg_min(int v, int L, int R, int l, int r) {
        push(v);
        if (R <= l || r <= L)
            return INF;
        else if (l <= L && R <= r)
            return t[v];
        else {
            int M = (L + R) / 2;
            return min(seg_min(2 * v + 1, L, M, l, r), seg_min(2 * v + 2, M, R, l, r));
        }
    }

    int seg_min(int l, int r) {
        return seg_min(0, 0, main_size, l, r);
    }

    seg_tree() { }

    seg_tree(vector<T> & a) {
        main_size = a.size();
        t.resize(a.size() * 4);
        to_add.resize(a.size() * 4);
        build(0, 0, a.size(), a);
    }
};

int n;
vector<vector<int>> G1;
vector<vector<int>> G2;
int timer, tans;
vector<int> tin;
vector<int> tout;

void dfs1(int v) {
    tin[v] = timer++;
    for (int to : G2[v])
        dfs1(to);
    tout[v] = timer++;
}

void dfs2(int v, seg_tree<int> & st, int ans) {
    int l = tin[v];
    int r = tout[v];
    int num = st.seg_min(l, l + 1);
    // for (int i = 0; i < 2 * n; ++i)
        // cout << st.seg_min(i, i + 1) << ' ';
    // cout << endl;
    if (st.seg_min(l, r) == 0) {
        // cout << "CASE 1" << endl;
        ans++;
        tans = max(tans, ans);
        st.seg_add(l, r, -v-1);
        for (int to : G1[v])
            dfs2(to, st, ans);
        st.seg_add(l, r, +v+1);
    } else if (st.seg_min(l, l + 1) == st.seg_min(r, r + 1)) {
        // cout << "CASE 2" << endl;
        int num = st.seg_min(l, l + 1);
        // cout << -num + 1 << endl;
        st.seg_add(tin[-num - 1], tout[-num - 1], -num);
        st.seg_add(l, r, -v-1);
        for (int to : G1[v])
            dfs2(to, st, ans);
        st.seg_add(tin[-num - 1], tout[-num - 1], num);
        st.seg_add(l, r, +v+1);
    } else {
        // cout << "CASE 3" << endl;
        for (int to : G1[v])
            dfs2(to, st, ans);
    }
}

void solve() {
    cin >> n;
    G1 = vector<vector<int>> (n);
    for (int i = 1; i < n; ++i) {
        int x;
        cin >> x;
        G1[x - 1].push_back(i);
    }
    G2 = vector<vector<int>> (n);
    for (int i = 1; i < n; ++i) {
        int x;
        cin >> x;
        G2[x - 1].push_back(i);
    }
    tin = vector<int>(n);
    tout = vector<int>(n);

    timer = 0;
    tans = 0;
    vector<int> a(2 * n);
    seg_tree<int> st(a);

    dfs1(0);

    dfs2(0, st, 0);

    cout << tans << '\n';
}

signed main() {
    int t;
    cin >> t;
    while (t--) solve();
}