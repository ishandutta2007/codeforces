#include <bits/stdc++.h>

// #define int long long

using namespace std;

const int R = 1 << 18, INF = 1e9;

int mx_val[R * 2], mx_d[R * 2], psh[R * 2];

int d[R], sz[R], pr[R], pr_hld[R], tin[R], pos[R];

vector<int> g[R];

void calc_sz(int v = 0) {
    sz[v] = 1;
    for (auto u : g[v]) {
        d[u] = d[v] + 1;
        calc_sz(u);
        sz[v] += sz[u];
    }
}

int t = 0;

void build_hld(int v = 0) {
    tin[v] = t;
    pos[tin[v]] = v;
    t++;
    int pos_u = 0;
    for (int i = 0; i < (int) g[v].size(); ++i) {
        if (sz[g[v][i]] > sz[g[v][pos_u]]) {
            pos_u = i;
        }
    }
    if (pos_u != 0) {
        swap(g[v][0], g[v][pos_u]);
    }
    for (int i = 0; i < (int) g[v].size(); ++i) {
        if (i == 0) {
            pr_hld[g[v][i]] = pr_hld[v];
        } else {
            pr_hld[g[v][i]] = g[v][i];
        }
        build_hld(g[v][i]);
    }
}

void build_segment_tree() {
    for (int i = R; i < R * 2; ++i) {
        psh[i] = -1;
        mx_val[i] = 0;
        mx_d[i] = d[pos[i - R]];
    }
    for (int i = R - 1; i > 0; --i) {
        psh[i] = -INF;
        mx_val[i] = 0;
        mx_d[i] = max(mx_d[i * 2], mx_d[i * 2 + 1]);
    }
}

void push(int node) {
    if (psh[node] != -INF) {
        // psh[node * 2] = psh[node * 2 + 1] = psh[node];
        psh[node * 2] = max(psh[node * 2], psh[node]);
        psh[node * 2 + 1] = max(psh[node * 2 + 1], psh[node]);
        mx_val[node * 2] = max(mx_val[node * 2], psh[node] + mx_d[node * 2] * 2);
        mx_val[node * 2 + 1] = max(mx_val[node * 2 + 1], psh[node] + mx_d[node * 2 + 1] * 2);
    }
    psh[node] = -INF;
}

void assign(int ql, int qr, int val, int node = 1, int nl = 0, int nr = R) {
    if (ql == qr) {
        return;
    }
    if (ql <= nl && nr <= qr) {
        psh[node] = max(psh[node], val);
        mx_val[node] = max(mx_val[node], val + mx_d[node] * 2);
        return;
    }
    if (qr <= nl || nr <= ql) {
        return;
    }
    push(node);
    int nm = (nl + nr) / 2;
    assign(ql, qr, val, node * 2, nl, nm);
    assign(ql, qr, val, node * 2 + 1, nm, nr);
    assert(mx_val[node] <= max(mx_val[node * 2], mx_val[node * 2 + 1]));
    mx_val[node] = max(mx_val[node * 2], mx_val[node * 2 + 1]);
}

int find_pos(int ql, int qr, int val, int node = 1, int nl = 0, int nr = R) {
    // cout << "!" << val << ' ' << mx_val[node] << endl;
    if (qr <= nl || nr <= ql) {
        return -1;
    }
    if (mx_val[node] <= val) {
        return -1;
    }
    if (nl == nr - 1) {
        return nl;
    }
    push(node);
    int nm = (nl + nr) / 2;
    int v = find_pos(ql, qr, val, node * 2 + 1, nm, nr);
    if (v == -1) {
        v = find_pos(ql, qr, val, node * 2, nl, nm);
    }
    assert(mx_val[node] <= max(mx_val[node * 2], mx_val[node * 2 + 1]));
    mx_val[node] = max(mx_val[node * 2], mx_val[node * 2 + 1]);
    return v;
}

int find_pos_hld(int v, int val) {
    while (v != 0) {
        int ans = find_pos(tin[pr_hld[v]], tin[v] + 1, val);
        if (ans != -1) {
            return pos[ans];
        }
        v = pr[pr_hld[v]];
    }
    return -1;
}

void assign_hld(int v, int p, int val) {
    while (tin[v] > tin[p]) {
        assign(max(tin[p] + 1, tin[pr_hld[v]]), tin[v] + 1, val);
        v = pr[pr_hld[v]];
    }
}

int get_ans(int v, int tm) {
    int pos = find_pos_hld(v, tm + d[v]);
    if (pos == -1) {
        assign_hld(v, 0, tm + d[v]);
        return tm + d[v] * 2;
    } else {
        assign_hld(v, pos, tm + d[v] - d[pos] * 2);
        return tm + (d[v] - d[pos]) * 2;
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    n++;
    for (int i = 1; i < n; ++i) {
        cin >> pr[i];
        g[pr[i]].push_back(i);
    }
    calc_sz();
    build_hld();
    build_segment_tree();
    // for (int i = 0; i < n; ++i) {
    //     cout << pr[i] << ' ' << pr_hld[i] << ' ' << sz[i] << ' ' << d[i] << endl;
    // }
    vector<int> x(m), tm(m), ans(m);
    vector<pair<pair<int, int>, int>> qs;
    for (int i = 0; i < m; ++i) {
        cin >> x[i] >> tm[i];
        qs.push_back({{tm[i] + d[x[i]], x[i]}, i});
    }
    sort(qs.begin(), qs.end());
    for (int i = 0; i < m; ++i) {
        ans[qs[i].second] = get_ans(x[qs[i].second], tm[qs[i].second]);
    }
    for (int i = 0; i < m; ++i) {
        cout << ans[i] << ' ';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}