#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;
 
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;
 
template <typename T>
inline void read(T &f) {
    f = 0; T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}
 
template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}
 
template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 3e5 + 5;

vector <int> adj[N];
int rt[N], lc[N], rc[N], dad[N], _siz[N], key[N];
int fa[N], a[N], siz[N], wson[N], top[N], tops[N], pre[N], where[N], dep[N];
int n, m, tot, dfn; ll ans;

inline int newNode(int x) {
    ++tot;
    key[tot] = (rand() << 15) ^ rand();
    _siz[tot] = 1;
    return tot;
}

void update(int u) {
    _siz[u] = _siz[lc[u]] + _siz[rc[u]] + 1;
}

void split(int u, int k, int &l, int &r) {
    // fprintf(stderr, "u = %d, siz[u] = %d, k = %d\n", u, siz[u], k);
    if (!u) { l = r = 0; return; }
    if (_siz[lc[u]] >= k) {
        r = u; dad[lc[u]] = 0;
        split(lc[u], k, l, lc[r]);
        dad[lc[r]] = r;
        update(r);
    } else {
        l = u; dad[rc[u]] = 0;
        split(rc[u], k - _siz[lc[u]] - 1, rc[l], r);
        dad[rc[l]] = l;
        update(l);
    }
}

int merge(int u, int v) {
    if (!u || !v) return u | v;
    if (key[u] < key[v]) {
        rc[u] = merge(rc[u], v);
        dad[rc[u]] = u;
        update(u);
        return u;
    } else {
        lc[v] = merge(u, lc[v]);
        dad[lc[v]] = v;
        update(v);
        return v;
    }
}

void dfs1(int u) {
    siz[u] = 1;
    for (int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i];
        if (v == fa[u]) continue;
        dep[v] = dep[u] + 1; fa[v] = u; dfs1(v); siz[u] += siz[v];
        if (siz[v] > siz[wson[u]]) wson[u] = v;
    }
}

void dfs2(int u, int tp) {
    tops[u] = ++dfn; pre[dfn] = u; top[u] = tp;
    // fprintf(stderr, "u = %d, tp = %d\n", u, tp);
    if (wson[u]) dfs2(wson[u], tp);
    for (int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i];
        if (v == fa[u] || v == wson[u]) continue;
        dfs2(v, v);
    }
}

int getrnk(int u) {
    int ans = _siz[lc[u]];
    while (dad[u]) {
        if (rc[dad[u]] == u) ans += _siz[lc[dad[u]]] + 1;
        u = dad[u];
    }
    return ans;
}

bool cmp(int i, int j) { return a[i] < a[j]; }

int _tot;
void dfs3(int u) {
    ++_tot;
    if (_tot != a[u]) {
        printf("NO\n");
        exit(0);
    }
    sort(adj[u].begin(), adj[u].end(), cmp);
    for (int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i];
        if (v == fa[u]) continue;
        dfs3(v);
    }
}

int main() {
    srand(123);
    read(n);
    for (int i = 1; i <= n; i++) read(a[i]);
    for (int i = 1; i < n; i++) {
        int u, v;
        read(u); read(v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(1); dfs2(1, 1);
    int minn = n;
    for (int i = 2; i <= n; i++) {
        if (a[fa[i]] <= a[i]) minn = min(minn, a[fa[i]]);
    }
    for (int i = 2; i <= n; i++) {
        if (a[i] > minn && a[fa[i]] > minn && a[fa[i]] > a[i]) {
            // fprintf(stderr, "i = %d, fa[i] = %d, minn = %d\n", i, fa[i], minn);
            printf("NO\n");
            return 0;
        }
    }
    for (int i = 1; i <= n; i++) newNode(i);
    for (int i = 1; i <= n; i++) {
        int u = pre[i];
        where[a[u]] = top[u];
        rt[top[u]] = merge(rt[top[u]], a[u]);
        // fprintf(stderr, "top[u] = %d, a[u] = %d\n", top[u], a[u]);
    }
    for (int i = minn; i >= 1; i--) {
        int rnk = getrnk(i);
        int u = where[i];
        ans += dep[u] + rnk;
        int l, r, tem;
        split(rt[u], rnk, l, r);
        split(r, 1, tem, r);
        // fprintf(stderr, "i = %d, u = %d, tem = %d, rnk = %d\n", i, u, tem, rnk);
        rt[u] = merge(l, r);
        while (1) {
            if (u == 1) {
                rt[u] = merge(i, rt[u]);
                where[i] = u;
                break;
            }
            int tmp = fa[u];
            int _l, _r, _tem;
            split(rt[top[tmp]], tops[tmp] - tops[top[tmp]], _l, _r);
            split(_r, 1, _tem, _r);
            rt[top[tmp]] = merge(_l, _r);
            rt[u] = merge(_tem, rt[u]);
            where[_tem] = u;
            u = top[fa[u]];
            // fprintf(stderr, "u = %d\n", u);
        }
    }
    for (int i = 1; i <= n; i++) {
        // fprintf(stderr, "where[%d] = %d\n", i, where[i]);
        // fprintf(stderr, "getrnk(%d) = %d\n", i, getrnk(i));
        int u = pre[tops[where[i]] + getrnk(i)];
        a[u] = i;
    }
    // for (int i = 1; i <= n; i++) fprintf(stderr, "a[%d] = %d\n", i, a[i]);
    dfs3(1);
    printf("YES\n");
    print(ans, '\n');
    for (int i = 1; i <= n; i++) print(a[i], i == n ? '\n' : ' ');
    return 0;
}