#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

const int NMAX = 200005;

int treeSize[NMAX];
vector<int> G[NMAX];

int64_t ans = 0;

void dfs(int node, int prev, int total) {
    for (int to: G[node]) {
        if (to == prev) {
            continue;
        }
        dfs(to, node, total);
        treeSize[node] += treeSize[to];
    }
    ans += min(treeSize[node], total - treeSize[node]);
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < 2 * m; ++i) {
        int x;
        cin >> x;
        treeSize[x]++;
    }
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dfs(1, -1, 2 * m);
    cout << ans << '\n';
}