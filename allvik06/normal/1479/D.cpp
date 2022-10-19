#include <bits/stdc++.h>

using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")

inline int min(const int& a, const int& b) {
    if (a < b) return a;
    return b;
}

inline int max(const int& a, const int& b) {
    if (a > b) return a;
    return b;
}

int a[300001];
int bl[300001];
vector <int> g[300002];
int t = 0, k, k1, cha = 0;

struct z {
    int u, v, l, r;
};

struct nz {
    int l, r, lz, rz, i;
};

int eo[2000001];
int tin[300001];
int tout[300001];
int gl[300001];
int f[300001];
int bp[20][300001];

void dfs(int v, int p) {
    bp[0][v] = p;
    tin[v] = t;
    ++t;
    bool ff = false;
    for (int i : g[v]) {
        if (i != p) {
            ff = true;
            gl[i] = gl[v] + 1;
            if (f[v] == -1) f[v] = cha;
            eo[cha] = i;
            ++cha;
            dfs(i, v);
            eo[cha] = i;
            ++cha;
        }
    }
    if (!ff) {
        f[v] = cha;
        eo[cha] = -1;
        ++cha;
        eo[cha] = -1;
        ++cha;
    }
    tout[v] = t;
    ++t;
}

int kol_bl[300001];
int kol[300001];

inline int parent(int v, int kk) {
    for (int i = 19; i >= 0; --i) {
        if ((1 << i) <= kk) {
            kk -= (1 << i);
            v = bp[i][v];
        }
    }
    return v;
}

inline int lca(int v, int u) {
    if (gl[u] < gl[v]) swap(u, v);
    u = parent(u, gl[u] - gl[v]);
    if (u == v) return u;
    for (int i = 19; i >= 0; --i) {
        if (bp[i][u] != bp[i][v]) {
            v = bp[i][v];
            u = bp[i][u];
        }
    }
    return bp[0][v];
}

bool cmp(const nz& one, const nz& two) {
    if (one.l / k == two.l / k) return one.r < two.r;
    return one.l < two.l;
}

inline void add(int i) {
    if (i < 0) return;
    kol[a[i]] ^= 1;
    if (kol[a[i]] == 0) --kol_bl[bl[a[i]]];
    else ++kol_bl[bl[a[i]]];
}

inline int get(int l, int r) {
    for (int i = l; i < min(k1 * (bl[l] + 1), r + 1); ++i) {
        if (kol[i] == 1) return i;
    }
    for (int i = r; i > max(l - 1, k1 * bl[r] - 1); --i) {
        if (kol[i] == 1) return i;
    }
    for (int bl1 = bl[l] + 1; bl1 < bl[r]; ++bl1) {
        if (kol_bl[bl1] > 0) {
            for (int i = bl1 * k1; i < (bl1 + 1) * k1; ++i) {
                if (kol[i] == 1) return i;
            }
            assert(false);
        }
    }
    return -1;
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int n, q;
    cin >> n >> q;
    k = sqrt(2 * n);
    k1 = sqrt(n);
    for (int i = 0; i <= n; ++i) {
        bl[i] = i / k1;
    }
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y; --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    z all[q];
    for (int i = 0; i < q; ++i) {
        cin >> all[i].u >> all[i].v >> all[i].l >> all[i].r; --all[i].u; --all[i].v;
    }
    for (int i = 0; i < 300001; ++i) f[i] = -1;
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < n; ++j) {
            bp[i][j] = n;
        }
    }
    dfs(0, n);
    for (int i = 1; i < 20; ++i) {
        for (int j = 0; j < n; ++j) {
            bp[i][j] = bp[i - 1][bp[i - 1][j]];
        }
    }
    nz new_all[q];
    for (int i = 0; i < q; ++i) {
        int u = all[i].u, v = all[i].v;
        if (tin[u] > tin[v]) swap(u, v);
        new_all[i] = {f[u], f[v] - 1, all[i].l, all[i].r, i};
    }
    sort(new_all, new_all + q, cmp);
    int l = 0, r = -1;
    vector <int> result(q);
    for (int i = 0; i < q; ++i) {
        while (l < new_all[i].l) {
            add(eo[l]);
            ++l;
        }
        while (l > new_all[i].l) {
            --l;
            add(eo[l]);
        }
        while (r < new_all[i].r) {
            ++r;
            add(eo[r]);
        }
        while (r > new_all[i].r) {
            add(eo[r]);
            --r;
        }
        add(lca(all[new_all[i].i].u, all[new_all[i].i].v));
        result[new_all[i].i] = get(new_all[i].lz, new_all[i].rz);
        add(lca(all[new_all[i].i].u, all[new_all[i].i].v));
    }
    for (int i : result) cout << i << "\n";
    return 0;
}