#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <cassert>
#include <unordered_map>
#include <fstream>
#include <random>
#include <cstring>
#include <bitset>
#include <functional>
#include <tuple>
#include <complex>
#include <chrono>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef unsigned int uint;
typedef pair<ll, int> pli;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
// mt19937 rnd(1);

const int MAXN = 500500;
const ll INF = 1e18;

vector<pii> g[MAXN];
int l[MAXN], r[MAXN];
vector<ll> leaves;
vector<int> id;
int m = 0;

class SegmentTree {
public:
    SegmentTree() {}

    SegmentTree(int nn) {
        n = nn;
        mn.resize(4 * nn);
        pr.resize(4 * nn);
    }

    void add(int l, int r, ll val) {
        add(0, 0, n, l, r, val);
    }

    ll get_min(int l, int r) {
        return get_min(0, 0, n, l, r);
    }

private:

    void push(int v) {
        mn[v] += pr[v];
        pr[2 * v + 1] += pr[v];
        pr[2 * v + 2] += pr[v];
        pr[v] = 0;
    }

    void add(int v, int lf, int rg, int l, int r, ll val) {
        if (l <= lf && rg <= r) {
            pr[v] += val;
            return;
        }
        if (rg <= l || r <= lf) {
            return;
        }
        push(v);
        int mid = (lf + rg) / 2;
        add(2 * v + 1, lf, mid, l, r, val);
        add(2 * v + 2, mid, rg, l, r, val);
        mn[v] = min(mn[2 * v + 1] + pr[2 * v + 1], mn[2 * v + 2] + pr[2 * v + 2]);
    }

    ll get_min(int v, int lf, int rg, int l, int r) {
        if (l <= lf && rg <= r) {
            return pr[v] + mn[v];
        }
        if (rg <= l || r <= lf) {
            return INF;
        }
        push(v);
        int mid = (lf + rg) / 2;
        return min(get_min(2 * v + 1, lf, mid, l, r), get_min(2 * v + 2, mid, rg, l, r));
    }

    int n;
    vector<ll> mn;
    vector<ll> pr;
};

void dfs(int v, ll depth = 0) {
    if (sz(g[v]) == 0) {
        l[v] = m++;
        r[v] = m;
        leaves.push_back(depth);
        id.push_back(v);
        return;
    }
    r[v] = 0; l[v] = MAXN;
    for (auto p : g[v]) {
        int u, w;
        tie(u, w) = p;
        dfs(u, depth + w);
        r[v] = max(r[v], r[u]);
        l[v] = min(l[v], l[u]);
    }
}

SegmentTree tree;
ll res[MAXN];

struct Query {
    int id, l, r;
};

vector<Query> query[MAXN];

void solve(int v, ll depth = 0) {
    for (auto q : query[v]) {
        // cout << "!" << q.id << " " << q.l << " " << q.r << endl;
        res[q.id] = tree.get_min(q.l, q.r) + depth;
    }

    for (auto p : g[v]) {
        int u, w;
        tie(u, w) = p;
        // cout << l[u] << " " << r[u] << " " << - 2 * w << endl;
        tree.add(l[u], r[u], - 2 * w);
        solve(u, depth + w);
        // cout << l[u] << " " << r[u] << " " << + 2 * w << endl;
        tree.add(l[u], r[u], 2 * w);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);    

    int n, q;
    cin >> n >> q;
    for (int i = 1; i < n; ++i) {
        int u, w;
        cin >> u >> w;
        --u;
        // cout << u << " " << i << " " << w << endl;
        g[u].push_back({i, w});
    }

    dfs(0);

    tree = SegmentTree(m);

    for (int i = 0; i < m; ++i) {
        tree.add(i, i + 1, leaves[i]);
    }

    for (int i = 0; i < q; ++i) {
        int v, l, r;
        cin >> v >> l >> r;
        --l;
        l = lower_bound(all(id), l) - id.begin();
        r = lower_bound(all(id), r) - id.begin();
        --v;
        // cout << "!" << v << " " << l << " " << r << endl;
        query[v].push_back({i, l, r});
    }

    solve(0);

    for (int i = 0; i < q; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
}