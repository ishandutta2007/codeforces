#include <iostream>
#include <vector>

using namespace std;

struct Node {
    long long val, upd;
};

const int MAXN = 400 * 1000 + 5;
int tin[MAXN], tout[MAXN];
long long col[MAXN];
Node st[4 * MAXN];
vector<int> g[MAXN], p;

void dfs(int v, int par) {
    tin[v] = p.size();
    p.push_back(v);
    for(size_t i = 0; i < g[v].size(); i++)
        if(g[v][i] != par)
            dfs(g[v][i], v);
    tout[v] = p.size();
}

void buildst(int v, int tl, int tr) {
    st[v].upd = 0;
    if(tl == tr - 1) {
        st[v].val = col[p[tl]];
        return;
    }
    int tm = (tl + tr) / 2;
    buildst(2 * v, tl, tm);
    buildst(2 * v + 1, tm, tr);
    st[v].val = (st[2 * v].val | st[2 * v + 1].val);
}

void push(int v) {
    if(!st[v].upd)
        return;
    st[2 * v].val = st[v].upd;
    st[2 * v].upd = st[v].upd;
    st[2 * v + 1].val = st[v].upd;
    st[2 * v + 1].upd = st[v].upd;
    st[v].upd = 0;
}

void update(int v, int tl, int tr, int l, int r, long long val) {
    if(tl == l && tr == r) {
        st[v].val = val;
        st[v].upd = val;
        return;
    }
    push(v);
    int tm = (tl + tr) / 2;
    if(l < tm)
        update(2 * v, tl, tm, l, min(r, tm), val);
    if(r > tm)
        update(2 * v + 1, tm, tr, max(l, tm), r, val);
    st[v].val = (st[2 * v].val | st[2 * v + 1].val);
}

long long get(int v, int tl, int tr, int l, int r) {
    if(tl == l && tr == r)
        return st[v].val;
    push(v);
    int tm = (tl + tr) / 2;
    long long res = 0;
    if(l < tm)
        res = (res | get(2 * v, tl, tm, l, min(r, tm)));
    if(r > tm)
        res = (res | get(2 * v + 1, tm, tr, max(l, tm), r));
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> col[i];
        col[i] = (1ll << col[i]);
    }
    for(int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;
        v--;
        u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    dfs(0, -1);
    buildst(1, 0, n);
    for(int i = 0; i < m; i++) {
        int t;
        cin >> t;
        if(t == 1) {
            int v;
            long long c;
            cin >> v >> c;
            v--;
            c = (1ll << c);
            update(1, 0, n, tin[v], tout[v], c);
        }
        else {
            int v;
            cin >> v;
            v--;
            cout << __builtin_popcountll(get(1, 0, n, tin[v], tout[v])) << '\n';
        }
    }
    return 0;
}