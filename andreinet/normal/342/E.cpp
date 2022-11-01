#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

const int NMAX = 100005, BUCKET = 5000;

vector<int> G[NMAX];
int level[NMAX];
int efirst[NMAX];
int eh[2 * NMAX], enode[2 * NMAX];
int rmq[20][2 * NMAX], xlog[2 * NMAX];
int epos = 0;

int dp1[NMAX];
int dp[NMAX];

bool special[NMAX];

void dfs(int node, int prev) {
    efirst[node] = ++epos;
    enode[epos] = node;
    eh[epos] = level[node];
    dp1[node] = level[node];
    dp[node] = level[node];

    for (int to: G[node]) {
        if (to == prev) {
            continue;
        }
        level[to] = level[node] + 1;
        dfs(to, node);
        enode[++epos] = node;
        eh[epos] = level[node];
    }
}

void buildRmq() {
    for (int i = 2; i <= epos; ++i) {
        xlog[i] = xlog[i / 2] + 1;
    }
    for (int i = 1; i <= epos; ++i) {
        rmq[0][i] = i;
    }
    for (int k = 1; k < 20; ++k) {
        int y = 1 << k - 1;
        for (int i = 1; i + (1 << k) - 1 <= epos; ++i) {
            rmq[k][i] = rmq[k - 1][i];
            if (eh[rmq[k][i]] > eh[rmq[k - 1][i + y]]) {
                rmq[k][i] = rmq[k - 1][i + y];
            }
        }
    }
}

void setDp1(int node, int prev) {
    dp1[node] = NMAX;
    for (int to: G[node]) {
        if (to == prev) {
            continue;
        }
        setDp1(to, node);
        dp1[node] = min(dp1[node], dp1[to] + 1);
    }
    if (special[node]) {
        dp1[node] = 0;
    }
}

void setDp(int node, int prev, int up) {
    int v1 = up, v2 = NMAX;
    dp[node] = min(up, dp1[node]);
    if (special[node]) {
        v1 = 0;
        dp[node] = 0;
    }
    for (int to: G[node]) {
        if (to == prev) continue;
        int cval = dp1[to] + 1;
        if (cval < v1) {
            v2 = v1;
            v1 = cval;
        } else if (cval < v2) {
            v2 = cval;
        }
    }

    for (int to: G[node]) {
        if (to == prev) continue;
        if (dp1[to] + 1 == v1) {
            setDp(to, node, v2 + 1);
        } else {
            setDp(to, node, v1 + 1);
        }
    }
}

int lca(int x, int y) {
    x = efirst[x];
    y = efirst[y];
    if (x > y) {
        swap(x, y);
    }
    int d = xlog[y - x + 1];
    int ret;
    if (eh[rmq[d][x]] < eh[rmq[d][y - (1 << d) + 1]]) {
        ret = rmq[d][x];
    } else {
        ret = rmq[d][y - (1 << d) + 1];
    }
    return enode[ret];
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dfs(1, -1);
    buildRmq();

    int adds[BUCKET + 3];
    int pos = 0;
    special[1] = true;
    for (int t = 0; t < q; ++t) {
        int type, node;
        cin >> type >> node;
        if (type == 1) {
            adds[pos++] = node;
            special[node] = true;
        } else {
            int ans = dp[node];
            for (int i = 0; i < pos; ++i) {
                int x = adds[i];
                int dist = level[node] + level[x] - 2 * level[lca(node, x)];
                ans = min(ans, dist);
            }
            cout << ans << '\n';
        }
        if (pos == BUCKET) {
            setDp1(1, -1);
            setDp(1, -1, n + 1);
            pos = 0;
        }
    }
}