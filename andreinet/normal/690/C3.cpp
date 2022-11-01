#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

const int NMAX = 200005;

vector<int> G[NMAX];
int father[NMAX];
int level[NMAX];
int anc[20][NMAX];

void dfs(int node, int prev) {
    for (int to: G[node]) {
        level[to] = level[node] + 1;
        dfs(to, node);
    }
}

int goUp(int x, int lvl) {
    for (int k = 19; k >= 0; --k) {
        if ((1 << k) & lvl) {
            x = anc[k][x];
        }
    }
    return x;
}

int lca(int x, int y) {
    if (level[x] > level[y]) {
        x = goUp(x, level[x] - level[y]);
    } else if (level[y] > level[x]) {
        y = goUp(y, level[y] - level[x]);
    }
    if (x == y) {
        return x;
    }
    for (int k = 19; k >= 0; --k) {
        if (anc[k][x] != anc[k][y]) {
            x = anc[k][x];
            y = anc[k][y];
        }
    }
    return father[x];
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i < n; ++i) {
        cin >> father[i];
        father[i]--;
        G[father[i]].push_back(i);
    }
    dfs(0, -1);
    for (int i = 0; i < n; ++i) {
        anc[0][i] = father[i];
    }
    for (int k = 1; k < 20; ++k) {
        for (int i = 0; i < n; ++i) {
            anc[k][i] = anc[k - 1][anc[k - 1][i]];
        }
    }
    
    int n1 = 0, n2 = 0, d = 0;
    for (int node = 1; node < n; ++node) {
        int l1, dist1;

        l1 = lca(n1, node);
        dist1 = level[n1] + level[node] - 2 * level[l1];

        int l2, dist2;

        l2 = lca(n2, node);
        dist2 = level[n2] + level[node] - 2 * level[l2];

        if (max({d, dist1, dist2}) == dist1) {
            n2 = node;
            d = dist1;
        } else if (max({d, dist1, dist2}) == dist2) {
            n1 = node;
            d = dist2;
        }

        cout << d << ' ';
    }
    cout << '\n';
}