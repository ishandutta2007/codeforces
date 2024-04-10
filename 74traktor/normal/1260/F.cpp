#include<bits/stdc++.h>

using namespace std;

struct pt {
    int i, type;
    long long len;
};

int const maxn = 1e5 + 1, N = (1 << 18);
vector < int > g[maxn];
bool ok[maxn];
long long go[N], cnt[N], l[maxn], r[maxn], psh_go[N], psh_cnt[N];
int sz[maxn];
long long ans, alls = 1;
long long mod = 1e9 + 7;
long long st[maxn], rev[maxn];
long long val[maxn], len[maxn];
int ptr;
long long S1 = 0, S2 = 0;
int clearr[N];
vector < pt > what[maxn];
int was[N];
int timer;

long long bin(long long x, int y) {
    if (y == 0) return 1;
    if (y % 2 == 0) {
        long long q = bin(x, y / 2);
        return q * q % mod;
    }
    return x * bin(x, y - 1) % mod;
}

inline void add(int v, long long x, long long tmp) {
    int to;
    for (auto key : what[v]) {
        to = key.i;
        if (was[to] != timer) clearr[ptr++] = to, was[to] = timer;
        if (key.type) {
            psh_go[to] += x, psh_cnt[to] += tmp;
        }
        else {
            go[to] += key.len * x;
            cnt[to] += key.len * tmp;
        }
    }
}

inline void get(int v) {
    S1 = 0, S2 = 0;
    int to;
    for (auto key : what[v]) {
        to = key.i;
        if (key.type) S1 += go[to], S2 += cnt[to];
        S1 += key.len * psh_go[to];
        S2 += key.len * psh_cnt[to];
    }
    S1 %= mod, S2 %= mod;
}

void build(int v, int p) {
    sz[v] = 1;
    for (auto u : g[v]) {
        if (ok[u] || u == p) continue;
        build(u, v);
        sz[v] += sz[u];
    }
}

void f(int v, int p, long long d) {
    get(v);
    ans += rev[len[v]] * (S2 * d % mod + S1);
    ans %= mod;
    for (auto u : g[v]) {
        if (u == p || ok[u]) continue;
        f(u, v, d + 1);
    }
}

void del(int v, int p, long long d) {
    add(v, d * val[v] % mod, val[v]);
    for (auto u : g[v]) {
        if (u == p || ok[u]) continue;
        del(u, v, d + 1);
    }
}

void dfs(int v) {
    timer++;
    build(v, -1);
    int T = sz[v], lst = v;
    bool find = true;
    while (find) {
        find = false;
        for (auto u : g[v]) {
            if (u == lst || ok[u]) continue;
            if (sz[u] >= T / 2) {
                lst = v, v = u, find = true;
                break;
            }
        }
    }
    ptr = 1;
    add(v, 0, val[v]);
    lst = -1;
    for (auto u : g[v]) {
        if (ok[u]) continue;
        if (lst != -1) del(lst, v, 1);
        f(u, v, 1);
        lst = u;
    }
    for (int i = 1; i < ptr; ++i) {
        int c = clearr[i];
        go[c] = 0, cnt[c] = 0, psh_go[c] = 0, psh_cnt[c] = 0;
    }
    ok[v] = true;
    for (auto u : g[v]) if (!ok[u]) dfs(u);
}

void calc(int i, long long lef, long long righ, int lq, int rq, int pos) {
    if (lq >= righ || lef >= rq) return;
    if (lq <= lef && righ <= rq) what[pos].push_back({i, 1, min(righ, r[pos] + 1) - max(lef, l[pos])});
    else what[pos].push_back({i, 0, min(righ, r[pos] + 1) - max(lef, l[pos])});
    if (lq <= lef && righ <= rq) return;
    long long m = (righ + lef) / 2;
    calc(2 * i + 1, lef, m, lq, rq, pos);
    calc(2 * i + 2, m, righ, lq, rq, pos);
}

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, u, v;
    cin >> n;
    //n = 100000;
    st[0] = 1;
    rev[0] = 1;
    for (long long i = 1; i < maxn; ++i) {
        rev[i] = bin(i, mod - 2);
    }
    for (int i = 1; i <= n; ++i) cin >> l[i] >> r[i];
    for (int i = 1; i <= n; ++i) calc(0, 1, maxn, l[i], r[i] + 1, i);
    for (int i = 1; i < n; ++i) {
        cin >> u >> v;
        //u = i, v = i + 1;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) alls *= (r[i] - l[i] + 1), alls %= mod;
    for (int i = 1; i <= n; ++i) val[i] = alls * rev[r[i] - l[i] + 1] % mod, len[i] = r[i] - l[i] + 1;
    for (int i = 1; i <= n; ++i) ok[i] = false;
    dfs(1);
    cout << ans % mod << '\n';
    return 0;
}