#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int v, add;
};

const int MAXN = 200 * 1000 + 5;
int a[MAXN], d[MAXN], tin[2][MAXN], tout[2][MAXN];
vector<int> g[MAXN], vv[2];
Node st[2][4 * MAXN];

void dfs(int v, int p) {
    for(int i = 0; i < 2; i++)
        tin[i][v] = vv[i].size();
    vv[d[v] % 2].push_back(v);
    for(size_t i = 0; i < g[v].size(); i++)
        if(g[v][i] != p) {
            d[g[v][i]] = d[v] + 1;
            dfs(g[v][i], v);
        }
    for(int i = 0; i < 2; i++)
        tout[i][v] = vv[i].size();
}

void buildst(int t, int v, int tl, int tr) {
    if(tl == tr - 1) {
        st[t][v].v = vv[t][tl];
        return;
    }
    int tm = (tl + tr) / 2;
    buildst(t, 2 * v, tl, tm);
    buildst(t, 2 * v + 1, tm, tr);
}

void push(int t, int v) {
    if(!st[t][v].add)
        return;
    st[t][2 * v].add += st[t][v].add;
    st[t][2 * v + 1].add += st[t][v].add;
    st[t][v].add = 0;
}

void add(int t, int v, int tl, int tr, int l, int r, int val) {
    if(l == tl && r == tr) {
        st[t][v].add += val;
        return;
    }
    push(t, v);
    int tm = (tl + tr) / 2;
    if(l < tm)
        add(t, 2 * v, tl, tm, l, min(r, tm), val);
    if(r > tm)
        add(t, 2 * v + 1, tm, tr, max(l, tm), r, val);
}

int get(int t, int v, int tl, int tr, int k) {
    if(tl == tr - 1)
        return a[st[t][v].v] + st[t][v].add;
    push(t, v);
    int tm = (tl + tr) / 2;
    if(k < tm)
        return get(t, 2 * v, tl, tm, k);
    else
        return get(t, 2 * v + 1, tm, tr, k);
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;
        v--;
        u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    if(n == 1) {
        n = 2;
        g[0].push_back(1);
        g[1].push_back(0);
    }
    dfs(0, -1);
    for(int i = 0; i < 2; i++)
        buildst(i, 1, 0, vv[i].size());
    for(int i = 0; i < m; i++) {
        int q;
        cin >> q;
        if(q == 1) {
            int x, val;
            cin >> x >> val;
            x--;
            if(d[x] % 2) {
                if(tin[0][x] != tout[0][x])
                    add(0, 1, 0, vv[0].size(), tin[0][x], tout[0][x], -val);
                add(1, 1, 0, vv[1].size(), tin[1][x], tout[1][x], val);
            }
            else {
                add(0, 1, 0, vv[0].size(), tin[0][x], tout[0][x], val);
                if(tin[1][x] != tout[1][x])
                    add(1, 1, 0, vv[1].size(), tin[1][x], tout[1][x], -val);
            }
        }
        else {
            int x;
            cin >> x;
            x--;
            if(d[x] % 2)
                cout << get(1, 1, 0, vv[1].size(), tin[1][x]) << '\n';
            else
                cout << get(0, 1, 0, vv[0].size(), tin[0][x]) << '\n';
        }
    }
    return 0;
}