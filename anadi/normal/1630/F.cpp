#include <bits/stdc++.h>

using namespace std;

const int N = 50'007;

struct Matching {
    int n;
    vector <int> vis;
    vector <int> adj[2];
    vector <vector <int> > G;

    Matching(int _n) {
        n = _n;
        adj[0].resize(n + 1);
        adj[1].resize(n + 1);

        G.resize(n + 1);
        vis.resize(n + 1);
    }

    void add_edge(int u, int v) {
        G[u].push_back(v);
    }

    bool go(int u) {
        vis[u] = 1;
        for (const int &v: G[u]) {
            const int &r = adj[1][v];
            if (!r || (!vis[r] && go(r))) {
                adj[0][u] = v;
                adj[1][v] = u;
                return true;
            }
        }

        return false;
    }

    int run() {
        bool change = true;
        while (change) {
            change = false;
            for (int i = 1; i <= n; ++i) {
                if (!adj[0][i] && go(i)) {
                    change = true;
                }
            }

            fill(vis.begin(), vis.end(), 0);
        }

        return count_if(adj[0].begin(), adj[0].end(), [](int v) { return v > 0; });
    }
};

int n;
int in[N], id[N];

void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &in[i]);
        id[in[i]] = i;
    }

    Matching m(2 * n + 1);

    auto add_edge = [&](int u, int val) {
        int v = id[val];
        if (u == v || !v) {
            return;
        }

        m.add_edge(v, u);
        m.add_edge(n + v, n + u);
    };

    for (int i = 1; i <= n; ++i) {
        m.add_edge(i, n + i);

        int v = in[i];
        for (int j = 1; j * j <= v; ++j) {
            if (v % j == 0) {
                add_edge(i, j);
                add_edge(i, v / j);
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        id[in[i]] = 0;
    }

    printf("%d\n", m.run() - n);
}

int main()
{
    int cases;
    scanf("%d", &cases);

    while (cases--) {
        solve();
    }

    return 0;
}