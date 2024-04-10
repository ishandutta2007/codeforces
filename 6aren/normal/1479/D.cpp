// #pragma GCC optimize ("O3")
// #pragma GCC optimize ("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #pragma comment(linker, "/STACK:1024000000,1024000000")
#include<bits/stdc++.h>
using namespace std;

const int N = 300005;
const int BL = 750;

namespace SqrtDS {
    const int BLL = 550;
    bool a[N];
    int count[N / BLL + 1];
    void push(int x) {
        a[x] ^= 1;
        if (a[x]) count[x / BLL]++;
        else count[x / BLL]--;
    }

    int get(int l, int r) {
        while (l <= r) {
            if (l % BLL || l + BLL > r) {
                if (a[l] != 0) return l;
                l++;
            } else {
                if (count[l / BLL] == 0) {
                    l += BLL;
                    continue;
                }
                for (int i = l; i < l + BLL; i++) {
                    if (a[i] != 0) return i;
                }
            }
        }
        return -1;
    }
}

int n, m;
vector<int> g[N];
int par[20][N], dep[N];
int st[N], en[N], timer = 0;
int indexx[2 * N];

void dfs(int u, int p) {
    dep[u] = dep[p] + 1;
    st[u] = ++timer;
    for (int e : g[u]) {
        if (e == p) continue;
        dfs(e, u);
        par[0][e] = u;
    }
    en[u] = ++timer;
}

int get_lca(int u, int v) {
    if (dep[u] > dep[v]) swap(u, v);
    for (int i = 19; i >= 0; i--) {
        if (dep[par[i][v]] >= dep[u]) v = par[i][v];
    }
    if (u == v) return u;
    for (int i = 19; i >= 0; i--) {
        if (par[i][u] != par[i][v]) {
            u = par[i][u];
            v = par[i][v];
        }
    }
    return par[0][u];
}

struct Query {
    int l, r, id, add, ql, qr;
};

int res = 0;
int w[N];

void push(int x) {
    int u = indexx[x];
    SqrtDS::push(w[u]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        indexx[st[i]] = i;
        indexx[en[i]] = i;
    }
    for (int i = 1; i < 20; i++) {
        for (int j = 1; j <= n; j++) {
            par[i][j] = par[i - 1][par[i - 1][j]];
        }
    }
    
    vector<Query> queries(m);

    for (int i = 0; i < m; i++) {
        queries[i].id = i;
        int u, v;
        cin >> u >> v >> queries[i].ql >> queries[i].qr;
        if (dep[u] > dep[v]) swap(u, v); 
        int lca = get_lca(u, v);
        if (lca == u) {
            queries[i].l = st[u];
            queries[i].r = st[v];
            queries[i].add = 0;
        } else {
            if (st[u] > st[v]) swap(u, v);
            queries[i].l = en[u];
            queries[i].r = st[v];
            queries[i].add = st[lca];
        }
    }
    
    sort(queries.begin(), queries.end(), [&](const Query &lhs, const Query &rhs) {
        return make_pair(lhs.l / BL, lhs.r) < make_pair(rhs.l / BL, rhs.r);
    });


    int L = 1, R = 0;
    vector<int> ans(m);
    for (Query query : queries) {
        int l = query.l;
        int r = query.r;
        int id = query.id;
        int add = query.add;
        int ql = query.ql;
        int qr = query.qr;
        while (R < r) {
            push(++R);
        }
        while (L > l) {
            push(--L);
        }
        while (R > r) {
            push(R--);
        }
        while (L < l) {
            push(L++);
        }
        if (add != 0) push(add);
        ans[id] = SqrtDS::get(ql, qr);
        if (add != 0) push(add);
    }

    for (int e : ans) cout << e << '\n';

    return 0;
}