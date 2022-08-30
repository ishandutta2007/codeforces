#include <bits/stdc++.h>
#define int long long
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> " << endl;
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') fu = -1; c = getchar(); }
    while(c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if(x < 0) putchar('-'), x = -x;
    if(x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

template <typename T>
struct hash_map_t {
    vector <T> v, val, nxt;
    vector <int> head;
    int mod, tot, lastv;
    T lastans;
    bool have_ans;

    hash_map_t (int md = 0) {
        head.clear(); v.clear(); val.clear(); nxt.clear(); tot = 0; mod = md;
        nxt.resize(1); v.resize(1); val.resize(1); head.resize(mod);
        have_ans = 0;
    }

    bool count(int x) {
        int u = x % mod;
        for(register int i = head[u]; i; i = nxt[i]) {
            if(v[i] == x) {
                have_ans = 1;
                lastv = x;
                lastans = val[i];
                return 1;
            }
        }
        return 0;
    }

    void ins(int x, int y) {
        int u = x % mod;
        nxt.push_back(head[u]); head[u] = ++tot;
        v.push_back(x); val.push_back(y);
    }

    int qry(int x) {
        if(have_ans && lastv == x) return lastans;
        count(x);
        return lastans;
    }
};

#define update(u) if(u -> left -> size) u -> size = u -> left -> size + u -> right -> size, u -> sum = u -> left -> sum + u -> right -> sum, u -> value = u -> right -> value
#define new_node(a, b, c, d, e) (&(*st[cnt++] = node_t(a, b, c, d, e)))
#define merge(a, b) new_node(a -> size + b -> size, b -> value, a -> sum + b -> sum, a, b)
#define ratio 4

const int N = 250005, INF = 0x7fffffff;

struct node_t {
    int size, value; ll sum;
    node_t *left, *right;
    node_t () {}
    node_t (int a, int b, ll c, node_t *d, node_t *e) : size(a), value(b), sum(c), left(d), right(e) {}
} *rt[N], *null, *st[4000000], t[4000000];

struct edge_t {
    int u, v, next, val;
} G[N << 1];

set < pair <int, int> > po;
typedef set < pair <int, int> > :: iterator IT1;
vector <int> adj[N];
int deg[N], head[N], fa[N], faval[N];
ll f[N][2], sum;
int n, cnt, tot;

inline void addedge(int u, int v, int val) {
    G[++tot] = (edge_t) {u, v, head[u], val}, head[u] = tot;
    G[++tot] = (edge_t) {v, u, head[v], val}, head[v] = tot;
}

void maintain(node_t *u) {
    if(u -> left -> size > u -> right -> size * ratio) u -> right = merge(u -> left -> right, u -> right), st[--cnt] = u -> left, u -> left = u -> left -> left;
    else if(u -> right -> size > u -> left -> size * ratio) u -> left = merge(u -> left, u -> right -> left), st[--cnt] = u -> right, u -> right = u -> right -> right;
}

void ins(node_t *u, int x) {
    if(u -> size == 1) u -> left = new_node(1, min(u -> value, x), min(u -> value, x), null, null), u -> right = new_node(1, max(u -> value, x), max(u -> value, x), null, null);
    else ins(x > u -> left -> value ? u -> right : u -> left, x);
    update(u); maintain(u);
}

void erase(node_t *u, int x) {
    if(u -> left -> size == 1 && u -> left -> value == x) st[--cnt] = u -> left, st[--cnt] = u -> right, *u = *u -> right;
    else if(u -> right -> size == 1 && u -> right -> value == x) st[--cnt] = u -> left, st[--cnt] = u -> right, *u = *u -> left;
    else erase(x > u -> left -> value ? u -> right : u -> left, x);
    update(u); maintain(u);
}

ll find(node_t *u, int x) {
    if(u -> size == 1) return x ? u -> sum : 0;
    return x > u -> left -> size ? find(u -> right, x - u -> left -> size) + u -> left -> sum : find(u -> left, x);
}

void dfs1(int u, int father) {
    for(register int i = head[u]; i; i = G[i].next) {
        int v = G[i].v;
        if(v == father) continue;
        fa[v] = u; faval[v] = G[i].val;
        dfs1(v, u);
    }
}

void dfs2(int u, int father, int ii) {
    if(faval[u] && father) erase(rt[u], faval[u]);
    ll sum = 0;
    for(register unsigned i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        dfs2(v, u, ii);
        erase(rt[u], faval[v]);
        if(f[v][1] + faval[v] < f[v][0]) sum += f[v][1] + faval[v], ins(rt[u], 0);
        else sum += f[v][0], ins(rt[u], f[v][1] + faval[v] - f[v][0]);
    }
    // cout << "u = " << u << ", sum = " << sum << endl;
    f[u][0] = sum + find(rt[u], deg[u] - ii), f[u][1] = sum + find(rt[u], deg[u] - ii - 1);
    for(register unsigned i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if(f[v][1] + faval[v] < f[v][0]) erase(rt[u], 0);
        else erase(rt[u], f[v][1] + faval[v] - f[v][0]);
        ins(rt[u], faval[v]);
    }
    if(faval[u] && father) ins(rt[u], faval[u]);
}

#undef int
int main() {
#define int long long
    read(n);
    null = new node_t(0, 0, 0, 0, 0);
    for(register int i = 1; i <= n; i++) rt[i] = new node_t(1, INF, INF, null, null);
    for(register int i = 0; i < 4000000; i++) st[i] = &t[i];
    for(register int i = 1; i < n; i++) {
        int u, v, val;
        read(u); read(v); read(val);
        addedge(u, v, val);
        ++deg[u]; ++deg[v];
        ins(rt[u], val);
        ins(rt[v], val);
        sum += val;
    }
    for(register int i = 1; i <= n; i++) po.insert(make_pair(deg[i], i));
    dfs1(1, 0);
    print(sum, ' ');
    for(register int i = 1; i < n; i++) {
        vector <int> nowp;
        IT1 it = po.end(); --it;
        while(1) {
            if(it -> first > i) nowp.push_back(it -> second);
            else break;
            if(it == po.begin()) break;
            --it;
        }
        int len = (int)nowp.size();
        for(register int j = 0; j < len; j++) {
            int u = nowp[j];
            if(deg[fa[u]] > i) adj[fa[u]].push_back(u);
        }
        ll ans = 0;
        for(register int j = 0; j < len; j++) {
            int u = nowp[j];
            if(deg[fa[u]] <= i) {
                dfs2(u, 0, i);
                ans += f[u][0];
            }
        }
        for(register int j = 0; j < len; j++) {
            int u = nowp[j];
            adj[u].clear();
        }
        print(ans, ' ');
    }
    putchar('\n');
    return 0;
}