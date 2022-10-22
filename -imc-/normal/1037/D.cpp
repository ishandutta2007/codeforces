#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;
using ld = long double;

#define int li

void solve(bool);

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#else
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
#endif

    solve(true);

    return 0;
}

vector<vector<int>> ed;
vector<vector<int>> e;
vector<int> depth;
vector<int> parent;

void dfs(int v, int p = -1) {
    for (int u : ed[v]) {
        if (u == p) continue;
        depth[u] = depth[v] + 1;
        parent[u] = v;
        e[v].push_back(u);
        dfs(u, v);
    }
}

void solve(bool __attribute__((unused)) read) {
    int n;
    cin >> n;

    ed.clear();
    ed.resize(n);

    e.clear();
    e.resize(n);

    depth.assign(n, 0);
    parent.assign(n, 0);

    for (int i = 0; i + 1 < n; ++i) {
        int x, y;
        cin >> x >> y;
        --x; --y;

        ed[x].push_back(y);
        ed[y].push_back(x);
    }

    dfs(0);

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }

    if (a[0] != 0) {
        cout << "No" << endl;
        return;
    }

    vector<int> gotChildren(n);

    vector<int> childOf;
    childOf.push_back(-1);
    parent[0] = -1;

    //a.erase(a.begin());
    //curParent = 0;

    int i = -1;
    for (int x : a) {
        ++i;
        if (parent[x] != childOf[i]) {
            cout << "No" << endl;
            return;
        }

        for (int i = 0; i < e[x].size(); ++i) {
            childOf.push_back(x);
        }
    }

    cout << "Yes" << endl;
}