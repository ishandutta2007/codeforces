#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;
const int NMAX = 200005, INF = 0x3f3f3f3f;

vector<int> G[NMAX];

int dpr[NMAX], dpn[NMAX];

void dfs(int node, int prev) {
    int cnt = 0;
    int sum = 0;
    for (int p: G[node]) {
        if (p == prev) continue;
        dfs(p, node);
        sum += dpn[p] + 1;
        cnt++;
    }
    if (cnt == 0) return;
    int dpx[3], ndpx[3];
    memset(dpx, INF, sizeof dpx);
    dpx[0] = 0;
    for (int p: G[node]) {
        if (p == prev) continue;
        memset(ndpx, INF, sizeof ndpx);
        ndpx[0] = dpx[0] + dpn[p] + 1;
        for (int i = 1; i < 3; ++i) {
            ndpx[i] = min(dpx[i - 1] + dpr[p], dpx[i] + dpn[p] + 1);
        }
        memcpy(dpx, ndpx, sizeof dpx);
    }
    dpr[node] = dpx[1];
    dpn[node] = min(dpx[1], dpx[2]);
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int n, X, Y;
    cin >> n >> X >> Y;

    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;

        G[x].push_back(y);
        G[y].push_back(x);
    }

    if (X <= Y) {

        dfs(1, 0);
        int cntY = dpn[1];
        int64_t ans = (int64_t) cntY * Y + (int64_t) (n - 1 - cntY) * X;
        cout << ans << '\n';
    } else {
        int xnode = 1;
        while (xnode <= n && SZ(G[xnode]) != n - 1) {
            ++xnode;
        }

        if (xnode == n + 1) {
            cout << (int64_t) Y * (n - 1) << '\n';
        } else {
            cout << (int64_t) Y * (n - 2) + X << '\n';
        }
    }
}