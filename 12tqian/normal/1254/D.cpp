#include <bits/stdc++.h>

using namespace std;

const int P = 998244353;
const int N = 1.5e5 + 5;

int n, q, ti = 0;
vector<int> adj[N];
int in[N], out[N], sz[N], par[N], dep[N], top[N], sum[N], fwt[N + 1];

int mpow(long long base, int exp) {
    long long res = 1;
    while (exp) {
        if (exp & 1) {
            res *= base;
            res %= P;
        }
        base *= base;
        base %= P;
        exp >>= 1;
    }
    return res;
}   

void add(int x, int y) {
    // point addition, 1-indexed
    while (x <= N) {
        fwt[x] += y;
        if (fwt[x] >= P) fwt[x] -= P;
        x += x & -x;
    }
}

void add(int l, int r, int x) {
    // add so it goes from [l, r) 0-indexed
    add(l + 1, x);
    add(r + 1, P - x);
}

int get(int x) {
    // query, 0-indexed
    ++x;
    int res = 0;
    while (x > 0) {
        res += fwt[x];
        if (res >= P) res -= P;
        x -= x & -x;
    }
    return res;
}

void dfs_sz(int u) {
    sz[u] = 1;
    if (par[u] != -1) {
        // erase parent from adj
        adj[u].erase(find(adj[u].begin(), adj[u].end(), par[u]));
    }
    for (int& v : adj[u]) {
        dep[v] = dep[u] + 1;
        par[v] = u;
        dfs_sz(v);
        sz[u] += sz[v];
        if (sz[v] > sz[adj[u][0]]) {
            // heavy child at beginning
            swap(v, adj[u][0]); 
        }
    }
}

void dfs_hld(int u) {
    in[u] = ti++;
    for (int v : adj[u]) {
        // top of the chain
        top[v] = v == adj[u][0] ? top[u] : v;
        dfs_hld(v);
    }
    out[u] = ti;
}

void modify(int v, int d) {
    // take care of outside the subtree
    int outside = 1LL * d * sz[v] % P;
    add(0, in[v], outside);
    add(out[v], n, outside);
    // add contribution for v
    add(in[v], in[v] + 1, 1LL * d * n % P);
    if (!adj[v].empty()) {
        // add the heavy tag
        int u = adj[v][0];
        add(in[u], out[u], 1LL * d * (n - sz[u]) % P);
    }
    // add the tag for the light edges
    sum[v] += d;
    if (sum[v] >= P) sum[v] -= P;
}

int query(int v) {
    // first get the heavy tags
    int res = get(in[v]);
    while (v != -1) {
        // move towards root, adding light parts, log times
        v = top[v];
        if (par[v] != -1) {
            res = (res + 1LL * sum[par[v]] * (n - sz[v])) % P;
        }
        v = par[v];
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[--u].push_back(--v);
        adj[v].push_back(u);
    }
    par[0] = -1;
    dfs_sz(0);
    dfs_hld(0);
    int inv = mpow(n, P - 2);
    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int v, d; cin >> v >> d;
            modify(--v, d);
        } else {
            int v; cin >> v;
            cout << 1LL * query(--v) * inv % P << '\n';
        }
    }
    return 0;
}