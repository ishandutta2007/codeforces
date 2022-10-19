#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;

#define all(v) (v).begin(),(v).end()

const int INF = 1e9 + 228;

int n, k;

vector<vector<int>> g;

vector<int> arr;
vector<int> tin;
vector<int> tout;
vector<int> ord;
vector<int> p;
int cur_time = 0;

void dfs(int v, int d = 1) {
    ord.push_back(v);
    arr[cur_time] = d;
    tin[v] = cur_time++;
    for (int u : g[v]) {
        if (tin[u] == -1) {
            p[u] = v;
            dfs(u, d + 1);
        }
    }
    tout[v] = cur_time;
}

vector<pair<int, int>> tree;
vector<int> mod;

void push(int v, int l, int r) {
    tree[v].first += mod[v];
    if (l + 1 != r) {
        mod[2 * v + 1] += mod[v];
        mod[2 * v + 2] += mod[v];
    }
    mod[v] = 0;
}

void build(int v, int l, int r) {
    if (l + 1 == r) {
        tree[v] = {arr[l], l};
    } else {
        int m = (l + r) / 2;
        build(2 * v + 1, l, m);
        build(2 * v + 2, m, r);
        tree[v] = max(tree[2 * v + 1], tree[2 * v + 2]);
    }
}

void add(int v, int l, int r, int ql, int qr, int x) {
    push(v, l, r);
    if (l >= qr || ql >= r)
        return;
    if (ql <= l && r <= qr) {
        mod[v] += x;
        push(v, l, r);
        return;
    }
    int m = (l + r) / 2;
    add(2 * v + 1, l, m, ql, qr, x);
    add(2 * v + 2, m, r, ql, qr, x);
    tree[v] = max(tree[2 * v + 1], tree[2 * v + 2]);
}

void add(int l, int r, int x) {
    add(0, 0, n, l, r, x);
    return;
    for (int i = l; i < r; i++) {
        arr[i] += x;
    }
}

int getv() {
    int i = tree[0].second;
    add(i, i + 1, -INF);
    return ord[i];
}

ll eval(int n, int r, int can) {
    int best = n / 2;
    best = min(best, can);
    return (ll) (n - r - best) * (r - best);
}

void solve() {
    ord.clear();
    cin >> n >> k; 
    g.clear();
    p.assign(n, -1);
    tin.assign(n, -1);
    tout.assign(n, -1);
    arr.assign(n, 0);
    arr.assign(n, -1);
    g.resize(n);
    for (int i= 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0);
    int alive;
    alive = n;
    ll min_ans = eval(n, 0, n);
    vector<int> can(n, 1);
    tree.resize(4 * n);
    mod.resize(4 * n);
    build(0, 0, n);
    for (int r = 1; r <= k; r++) {
        int bestv = getv();
        {
            int v = bestv;
            while (v != -1 && can[v]) {
                add(tin[v], tout[v], -1);
                can[v] = 0;
                alive--;
                v = p[v];
            }
        }
        min_ans = max(min_ans, eval(n, r, alive));
    }
    cout << min_ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
}