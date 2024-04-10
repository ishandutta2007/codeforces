#include<bits/stdc++.h>

using namespace std;

int const maxn = 1e5 + 5, maxw = 1001;
int a[maxn], L[maxn], R[maxn], cur = 1, ok[2 * maxn], psh[(1 << 20)];
vector < int > g[maxn];
bitset < maxw > in[(1 << 19)];
bitset < maxw > OK[maxw];
bitset < maxw > ans;
int mod;

void dfs(int v, int p) {
    L[v] = cur;
    ok[cur++] = v;
    for (auto u : g[v]) {
        if (u != p) dfs(u, v);
    }
    R[v] = cur++;
}

void build(int i, int l, int r) {
    if (r - l == 1) {
        if (ok[l] > 0) in[i][a[ok[l]]] = 1;
    }
    else {
        int m = (r + l) / 2;
        build(2 * i + 1, l, m);
        build(2 * i + 2, m, r);
        in[i] = (in[2 * i + 1]|in[2 * i + 2]);
    }
}

inline void push(int i) {
    psh[i] %= mod;
    if (psh[i] == 0) return;
    psh[2 * i + 1] += psh[i], psh[2 * i + 2] += psh[i];
    in[i] = ((in[i] << psh[i])|(in[i] >> (mod - psh[i])));
    psh[i] = 0;
}

void update(int i, int l, int r, int lq, int rq, int x) {
    push(i);
    if (lq >= r || l >= rq) return;
    if (lq <= l && r <= rq) {
        psh[i] += x;
        push(i);
        return;
    }
    int m = (r + l) / 2;
    update(2 * i + 1, l, m, lq, rq, x);
    update(2 * i + 2, m, r, lq, rq, x);
    in[i] = (in[2 * i + 1]|in[2 * i + 2]);
}

void get(int i, int l, int r, int lq, int rq) {
    push(i);
    if (lq >= r || l >= rq) return;
    if (lq <= l && r <= rq) {
        ans = (ans|in[i]);
        return;
    }
    int m = (r + l) / 2;
    get(2 * i + 1, l, m, lq, rq);
    get(2 * i + 2, m, r, lq, rq);
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, u, v;
    cin >> n >> m;
    mod = m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] %= m;
    }
    for (int i = 1; i < n; ++i) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    build(0, 1, cur);
    for (int i = 1; i <= m; ++i) {
        for (int j = m - i; j < m; ++j) OK[i][j] = 1;
    }
    vector < int > good;
    for (int i = 2; i < m; ++i) {
        int check = 1;
        for (int j = 2; j < i; ++j) if (i % j == 0) check = 0;
        if (check) good.push_back(i);
    }
    int q, type, x;
    cin >> q;
    for (int i = 1; i <= q; ++i) {
        cin >> type;
        if (type == 1) {
            cin >> v >> x;
            update(0, 1, cur, L[v], R[v] + 1, x % m);
        }
        else {
            cin >> v;
            int out = 0;
            ans = OK[0];
            get(0, 1, cur, L[v], R[v] + 1);
            for (auto key : good) out += ans[key];
            cout << out << '\n';
        }
    }
    return 0;
}