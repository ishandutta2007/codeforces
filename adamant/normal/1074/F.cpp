#include <bits/stdc++.h>

using namespace std;
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define int int64_t

const int maxn = 2e5 + 42, logn = 20;
const int inf = 1e9;

vector<int> g[maxn];
int in[maxn], out[maxn], h[maxn];
int up[maxn][logn];
map<int, int> mode[maxn];
int t;

void dfs(int v = 0, int p = 0) {
    in[v] = t++;
    for(auto u: g[v]) {
        if(u != p) {
            h[u] = h[v] + 1;
            mode[v][u] = 1;
            mode[u][v] = 0;
            up[u][0] = v;
            for(int i = 1; i < logn; i++) {
                up[u][i] = up[up[u][i - 1]][i - 1];
            }
            dfs(u, v);
        }
    }
    out[v] = t;
}

int get_up(int v, int x) {
    for(int i = 0; i < logn; i++) {
        if((x >> i) & 1) {
            v = up[v][i];
        }
    }
    return v;
}

bool is_par(int a, int b) {
    return in[a] <= in[b] && out[b] <= out[a];
}

int next(int u, int v) {
    if(is_par(u, v)) {
        return get_up(v, h[v] - h[u] - 1);
    } else {
        return up[u][0];
    }
}

int mx[4 * maxn];
int cnt_mx[4 * maxn];
int ad[4 * maxn];

void build(int v = 1, int l = 0, int r = maxn) {
    cnt_mx[v] = r - l;
    if(r - l > 1) {
        int m = (l + r) / 2;
        build(2 * v, l, m);
        build(2 * v + 1, m, r);
    }
}

void sadd(int a, int b, int c, int v = 1, int l = 0, int r = maxn) {
    if(a <= l && r <= b) {
        mx[v] += c;
        ad[v] += c;
        return;
    } else if(r <= a || b <= l) {
        return;
    } else {
        int m = (l + r) / 2;
        sadd(a, b, c, 2 * v, l, m);
        sadd(a, b, c, 2 * v + 1, m, r);
        int A = mx[2 * v], B = mx[2 * v + 1];
        mx[v] = max(A, B) + ad[v];
        cnt_mx[v] = A == B ? cnt_mx[2 * v] + cnt_mx[2 * v + 1] : A > B ? cnt_mx[2 * v] : cnt_mx[2 * v + 1];
    }
}

void add(int p, int v, int c) {
    if(mode[p][v] == 1) {
        sadd(in[v], out[v], c);
    } else {
        sadd(0, t, c);
        sadd(in[p], out[p], -c);
    }
}

void upd(int u, int v, int c) {
    int uu = next(u, v), vv = next(v, u);
    add(uu, u, c);
    add(vv, v, c);
}

int total = 1;

map<int, int> lol[maxn];
int present(int u, int v) {
    lol[u][v] ^= 1;
    lol[v][u] ^= 1;
    int c = lol[u][v] ? 1 : -1;
    total += c;
    return c;
}
int get() {
    return mx[1] == total ? cnt_mx[1] : 0;
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs();
    build();
    sadd(0, t, 1);
    while(q--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        upd(u, v, present(u, v));
        cout << get() << endl;
    }
    return 0;
}