#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

void dfs(const vector<vector<int>>& graph,
         vector<int>& dist,
         int node,
         int prev) {
    for (int to: graph[node]) {
        if (to != prev) {
            dist[to] = dist[node] + 1;
            dfs(graph, dist, to, node);
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
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        graph[x - 1].push_back(y - 1);
        graph[y - 1].push_back(x - 1);
    }

    vector<int> dist(n);
    dist[0] = 0;
    dfs(graph, dist, 0, -1);
    int start = max_element(dist.begin(), dist.end()) - dist.begin();
    dist[start] = 0;
    dfs(graph, dist, start, -1);
    cout << *max_element(dist.begin(), dist.end()) << '\n';
}