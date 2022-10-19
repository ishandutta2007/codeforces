#ifdef ONLINE_JUDGE1
// #include <bits/stdc++.h>
#else
#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#endif

typedef long long ll;

#pragma GCC optimize("Ofast,unroll-loops,fast-math,inline,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx,popcnt")

using namespace std;

struct Node {
    int l, r;
    Node() {
    }
};

Node N[300000 * 19 * 2];
int cur_top = 2;

gp_hash_table<ll, int> hsh;

int merge(int a, int b) {
    ll pp = a * 1000000009LL + b;
    if (hsh.find(pp) != hsh.end()) {
        return hsh[pp];
    }
    N[cur_top].l = a;
    N[cur_top].r = b;
    return hsh[pp] = cur_top++;
}

int SZ = 1;

const int MAXN = 3e5 + 228;
int arr[MAXN];
vector<int> g[MAXN];
int tr[MAXN];

int update(int t, int l, int r, int ind) {
    if (ind < l || ind >= r)
        return t;
    if (l + 1 == r) {
        return t ^ 1;
    }
    int m = (l + r) >> 1;
    return merge(update(N[t].l, l, m, ind), update(N[t].r, m, r, ind));
}

void dfs(int v, int p, int t) {
    t = update(t, 0, SZ, arr[v]);
    tr[v] = t;
    for (int u : g[v]) {
        if (u != p) {
            dfs(u, v, t);
        }
    }
}

const int LOG = 19;

int depth[MAXN];
int up[MAXN][LOG];

void dfsLCA(int v, int p) {
    depth[v] = depth[p] + 1;
    up[v][0] = p;
    for (int i = 1; i < LOG; i++) {
        up[v][i] = up[up[v][i - 1]][i - 1];
    }
    for (int u : g[v]) {
        if (u != p) {
            dfsLCA(u, v);
        }
    }
}

int go(int v, int d) {
    for (int i = 0; i < LOG; i++) {
        if (d & (1 << i)) {
            v = up[v][i];
        }
    }
    return v;
}

int lca(int u, int v) {
    if (depth[v] > depth[u]) {
        swap(u, v);
    }
    u = go(u, depth[u] - depth[v]);
    if (u == v) {
        return u;
    }
    for (int i = LOG - 1; i >= 0; i--) {
        if (up[v][i] != up[u][i]) {
            v = up[v][i];
            u = up[u][i];
        }
    }
    return up[v][0];
}

int query(int a, int b, int l, int r, int ql, int qr) {
    if (a == b) {
        return -1;
    }
    if (ql <= l && r <= qr && l + 1 == r) {
        return r;
    }
    if (ql >= r || qr <= l) {
        return -1;
    }
    int m = (l + r) / 2;
    int a1 = query(N[a].l, N[b].l, l, m, ql, qr);
    if (a1 != -1) {
        return a1;
    }
    int a2 = query(N[a].r, N[b].r, m, r, ql, qr);
    return a2;
}

int main() {
    N[0].l = -1;
    N[0].r = -1;
    N[1].l = -1;
    N[1].r = -1;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i]--;
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int tree = 0;
    while (SZ < n) {
        tree = merge(tree, tree);
        SZ *= 2;
    }
    dfs(0, -1, tree);
    dfsLCA(0, 0);
    while (q--) {
        int u, v, l, r;
        cin >> u >> v >> l >> r;
        u--;
        v--;
        l--;
        int a = tr[u];
        int b = tr[v];
        int c = lca(u, v);
        a = update(a, 0, SZ, arr[c]);
        int ans = query(a, b, 0, SZ, l, r);
        cout << ans << '\n';
    }
}