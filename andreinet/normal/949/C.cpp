#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

vector<vector<int>> graph;
vector<vector<int>> transposed;
vector<bool> used;
vector<int> component;

void dfs1(vector<int> &order, int node) {
    used[node] = true;
    for (int to: graph[node]) {
        if (!used[to]) {
            dfs1(order, to);
        }
    }
    order.push_back(node);
}

void dfs2(int node, int cc) {
    component[node] = cc;
    used[node] = false;
    for (int to: transposed[node]) {
        if (used[to]) {
            dfs2(to, cc);
        }
    }
}

int main() {
#ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
#endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, h;
    cin >> n >> m >> h;

    vector<int> colors(n);
    for (int& x: colors) {
        cin >> x;
    }

    graph.resize(n);
    transposed.resize(n);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        x--; y--;

        if ((colors[x] + 1) % h == colors[y]) {
            graph[x].push_back(y);
            transposed[y].push_back(x);
        }
        if ((colors[y] + 1) % h == colors[x]) {
            graph[y].push_back(x);
            transposed[x].push_back(y);
        }
    }
    used.resize(n, false);
    vector<int> order;
    for (int node = 0; node < n; ++node) {
        if (!used[node]) {
            dfs1(order, node);
        }
    }
    component.resize(n, -1);
    int k = 0;
    for (int i = SZ(order) - 1; i >= 0; --i) {
        int node = order[i];
        if (used[node]) {
            dfs2(node, k++);
        }
    }
    vector<vector<int>> nodes(k);
    for (int i = 0; i < n; ++i) {
        nodes[component[i]].push_back(i);
    }
    vector<bool> bad(k, false);
    for (int node = 0; node < n; ++node) {
        for (int to: graph[node]) {
            if (component[node] != component[to]) {
                bad[component[node]] = true;
            }
        }
    }
    vector<int> v(n + 1);
    for (int i = 0; i < k; ++i) {
        if (!bad[i] && SZ(nodes[i]) < SZ(v)) {
            v = move(nodes[i]);
        }
    }
    cout << v.size() << '\n';
    for (int x: v) {
        cout << x + 1 << ' ';
    }
    cout << '\n';
}