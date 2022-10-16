#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int val, vald;
};

const int MAXN = 300 * 1000 + 5, MOD = 1000 * 1000 * 1000 + 7;
Node st[4 * MAXN];
int d[MAXN], l[MAXN], r[MAXN];
vector<int> g[MAXN], vt;

void dfs(int v) {
    l[v] = vt.size();
    vt.push_back(v);
    for(size_t i = 0; i < g[v].size(); i++) {
        d[g[v][i]] = d[v] + 1;
        dfs(g[v][i]);
    }
    r[v] = vt.size();
}

void add(int v, int tl, int tr, int l, int r, int x, int xd) {
    if(l == tl && r == tr) {
        st[v].val = (st[v].val + x) % MOD;
        st[v].vald = (st[v].vald + xd) % MOD;
        return;
    }
    int tm = (tl + tr) / 2;
    if(l < tm)
        add(2 * v, tl, tm, l, min(r, tm), x, xd);
    if(r > tm)
        add(2 * v + 1, tm, tr, max(l, tm), r, x, xd);
}

int get(int v, int tl, int tr, int k) {
    if(tl + 1 == tr)
        return (st[v].val + (long long)st[v].vald * d[vt[k]]) % MOD;
    int tm = (tl + tr) / 2;
    if(k < tm)
        return (get(2 * v, tl, tm, k) + st[v].val +
                (long long)st[v].vald * d[vt[k]]) % MOD;
    return (get(2 * v + 1, tm, tr, k) + st[v].val +
            (long long)st[v].vald * d[vt[k]]) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 1; i < n; i++) {
        int p;
        cin >> p;
        p--;
        g[p].push_back(i);
    }
    dfs(0);
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if(type == 1) {
            int v, x, k;
            cin >> v >> x >> k;
            v--;
            add(1, 0, n, l[v], r[v], (x + (long long)k * d[v]) % MOD, -k);
        }
        else {
            int v;
            cin >> v;
            v--;
            cout << (get(1, 0, n, l[v]) + MOD) % MOD << '\n';
        }
    }
    return 0;
}