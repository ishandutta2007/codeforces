#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;
const int NMAX = 100005;

int64_t dp1[NMAX], dp2[NMAX];
int treeSize[NMAX];
int father[NMAX], an[20][NMAX];
int level[NMAX];

vector<int> G[NMAX];

void dfs1(int node, int prev) {
    father[node] = prev;
    treeSize[node] = 1;
    level[node] = level[prev] + 1;
    for (int p: G[node]) {
        if (p == prev) continue;
        dfs1(p, node);
        treeSize[node] += treeSize[p];
        dp1[node] += dp1[p] + treeSize[p];
    }
}

void dfs2(int node, int prev, int n) {
    if (prev != 0) {
        int64_t cdp = dp2[prev] - dp1[node] - treeSize[node];
        dp2[node] = dp1[node] + cdp + (n - treeSize[node]);
    } else {
        dp2[node] = dp1[node];
    }
    for (int p: G[node]) {
        if (p == prev) continue;
        dfs2(p, node, n);
    }
}

int goUp(int x, int lvl) {
    for (int k = 19; k >= 0; --k) {
        if (lvl & (1 << k)) {
            x = an[k][x];
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
    if (x == y) return x;
    for (int k = 19; k >= 0; --k) {
        if (an[k][x] != an[k][y]) {
            x = an[k][x];
            y = an[k][y];
        }
    }
    return an[0][x];
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    dfs1(1, 0);
    dfs2(1, 0, n);

    for (int i = 1; i <= n; ++i)
        an[0][i] = father[i];
    for (int k = 1; k < 20; ++k) {
        for (int i = 1; i <= n; ++i) {
            an[k][i] = an[k - 1][an[k - 1][i]];
        }
    }

    cout << setprecision(17) << fixed;
    while (q-- > 0) {
        int x, y;
        cin >> x >> y;

        int l = lca(x, y);
        if (l == y) swap(x, y);

        if (l != x) {
            double d1 = (double) dp1[x] / treeSize[x];
            double d2 = (double) dp1[y] / treeSize[y];
            double ans = d1 + d2 + level[x] + level[y] - 2 * level[l] + 1;
            cout << ans << '\n';
        } else {
            int p = goUp(y, level[y] - level[x] - 1);
            double d1 = (double) (dp2[x] - dp1[p] - treeSize[p]) /
                                 (n - treeSize[p]);
            double d2 = (double) dp1[y] / treeSize[y];
            double ans = d1 + d2 + level[x] + level[y] - 2 * level[l] + 1;
            cout << ans << '\n';
        }
    }
}