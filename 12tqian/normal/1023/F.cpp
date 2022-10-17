#include <bits/stdc++.h>

using namespace std;

#define f1r(i, a, b) for (int i = a; i < b; ++i)
#define f0r(i, a) f1r(i, 0, a)
#define each(t, a) for (auto& t : a)

#define mp make_pair
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define sz(x) (int) (x).size()
#define all(x) begin(x), end(x)

typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

template <class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template <class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int INF = 2e9;

template <class T> struct LazySeg {
    std::vector<T> sum, lazy;
    int sz;

    void init(int sz_) {
        sz = 1;
        while (sz < sz_) sz *= 2;
        sum.assign(2 * sz, INF);
        lazy.assign(2 * sz, INF);
    }

    void push(int ind, int L, int R) {
        if (lazy[ind] == INF) return;
        ckmin(sum[ind], lazy[ind]);
        if (L != R) {
            ckmin(lazy[2 * ind], lazy[ind]);
            ckmin(lazy[2 * ind + 1], lazy[ind]);
        }
        lazy[ind] = INF;
    }

    void pull(int ind) {
        sum[ind] = min(sum[2 * ind], sum[2 * ind + 1]);
    }

    void build() {
        for (int i = sz - 1; i >= 1; i--) {
            pull(i);
        }
    }

    void upd(int lo, int hi, T inc, int ind = 1, int L = 0, int R = -1) {
        if (R == -1) R += sz;
        push(ind, L, R);
        if (hi < L || R < lo) return ;
        if (lo <= L && R <= hi) {
            lazy[ind] = inc;
            push(ind, L, R);
            return;
        }
        int M = (L + R) / 2;
        upd(lo, hi, inc, 2 * ind, L, M);
        upd(lo, hi, inc, 2 * ind + 1, M + 1, R);
        pull(ind);
    }

    T qsum(int lo, int hi, int ind = 1, int L = 0, int R = -1) {
        if (R == -1) R += sz;
        push(ind, L, R);
        if (lo > R || L > hi) return INF;
        if (lo <= L && R <= hi) return sum[ind];
        int M = (L + R) / 2;
        return min(qsum(lo, hi, 2 * ind, L, M), qsum(lo, hi, 2 * ind + 1, M + 1, R));
    }
};

const bool VALUES_IN_VERTICES = false;

template <class T> class HeavyLight {
    std::vector<int> parent, heavy, depth, root, tree_pos;
    LazySeg<T> tree;

    template <class G> int dfs(const G& graph, int v) {
        int size = 1, max_subtree = 0;
        for (int u : graph[v]) if (u != parent[v]) {
            parent[u] = v;
            depth[u] = depth[v] + 1;
            int subtree = dfs(graph, u);
            if (subtree > max_subtree) heavy[v] = u, max_subtree = subtree;
            size += subtree;
        }
        return size;
    }

    template <class B> void process_path(int u, int v, B op) {
        for (; root[u] != root[v]; v = parent[root[v]]) {
            if (depth[root[u]] > depth[root[v]]) std::swap(u, v);
            op(tree_pos[root[v]], tree_pos[v]);
        }
        if (depth[u] > depth[v]) std::swap(u, v);
        op(tree_pos[u] + (VALUES_IN_VERTICES ? 0 : 1), tree_pos[v]);
    }

public:
    template <class G>
    void init(const G& graph, int r = 0) {
        int n = (int) graph.size();
        heavy.assign(n, -1);
        parent.assign(n, 0);
        depth.assign(n, 0);
        root.assign(n, 0);
        tree_pos.assign(n, 0);
        tree.init(n);
        parent[r] = -1;
        depth[r] = 0;
        dfs(graph, r);
        for (int i = 0, current_pos = 0; i < n; ++i)
            if (parent[i] == -1 || heavy[parent[i]] != i)
            for (int j = i; j != -1; j = heavy[j]) {
                root[j] = i;
                tree_pos[j] = current_pos++;
            }
    }

    void modify_path(int u, int v, const T& value) {
        process_path(u, v, [this, &value](int l, int r) { tree.upd(l, r, value); });
    }
    
    T query_path(int u, int v) {
        T res = INF;
        process_path(u, v, [this, &res](int l, int r) { ckmin(res, tree.qsum(l, r)); });
        return res;
    }
};

struct DSU {
    std::vector<int> e;
    int comps;

    void init(int n) {
        e = std::vector<int>(n, -1);
        comps = n;
    }

    int get(int x) {
        return e[x] < 0 ? x : e[x] = get(e[x]);
    }

    bool same_set(int a, int b) {
        return get(a) == get(b);
    }

    int size(int x) {
        return -e[get(x)];
    }

    bool unite(int x, int y) {
        x = get(x), y = get(y);
        if (x == y) return false;
        if (e[x] > e[y]) std::swap(x, y);
        e[x] += e[y]; e[y] = x;
        comps--;
        return true;
    }
};

inline char gc() { // like getchar()
    static char buf[1 << 16];
    static size_t bc, be;
    if (bc >= be) {
        buf[0] = 0, bc = 0;
        be = fread(buf, 1, sizeof(buf), stdin);
    }
    return buf[bc++]; // returns 0 on EOF
}

int readInt() {
    int a, c;
    while ((a = gc()) < 40);
    if (a == '-') return -readInt();
    while ((c = gc()) >= 48) a = a * 10 + c - 480;
    return a - 48;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n = readInt();
    int k = readInt();
    int m = readInt();
    vector<array<int, 3>> ed;
    vector<array<int, 2>> add;
    f0r(i, k) {
        int u = readInt();
        int v = readInt();
        u--, v--;
        if (u > v) swap(u, v);
        add.pb({u, v});
    }
    f0r(i, m) {
        int u = readInt();
        int v = readInt();
        int w = readInt();
        u--, v--;
        if (u > v) swap(u, v);
        ed.pb({u, v, w});
    }
    sort(all(ed), [&](array<int, 3> a, array<int, 3> b) {
        return a[2] < b[2];
    });
    DSU D; 
    D.init(n);
    f0r(i, k) D.unite(add[i][0], add[i][1]);
    vector<array<int, 2>> need;
    sort(all(need));
    each(e, ed) {
        if (D.same_set(e[0], e[1])) continue;
        need.pb({e[0], e[1]});
        D.unite(e[0], e[1]);
    }
    vector<vi> g(n);
    each(e, add) {
        g[e[0]].pb(e[1]);
        g[e[1]].pb(e[0]);
    }
    each(e, need) {
        g[e[0]].pb(e[1]);
        g[e[1]].pb(e[0]);
    }
    HeavyLight<int> H;
    H.init(g);
    each(e, ed) {
        H.modify_path(e[0], e[1], e[2]);
    }
    ll ans = 0;
    each(e, add) {
        int plus =  H.query_path(e[0], e[1]);
        ans += plus;
        if (plus == INF) {
            cout << -1 << '\n';
            return 0;
        }
    }
    cout << ans << '\n';
    return 0;
}