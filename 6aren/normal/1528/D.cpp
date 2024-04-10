#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n, vector<pair<int, int>>(0));   
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        g[u].push_back({v, c});
    }

    for (int i = 0; i < n; i++) {
        int min_dis = 1e9;
        for (auto &edge : g[i]) {
            min_dis = min(min_dis, edge.second);
        }
        int bound = min_dis + n;
        priority_queue<pair<int, int>> pq;
        pq.push({0, i});
        vector<int> d(n, 2e9);
        d[i] = 0;
        vector<bool> used(n, false);
        while (!pq.empty()) {
            auto foo = pq.top();
            pq.pop();
            int u = foo.second;
            int dis = -foo.first;
            if (used[u]) continue;
            used[u] = true; 
            // cout << i << ' ' << u << endl;
            vector<int> dist(n, 2e9);
            for (auto &e : g[u]) {
                int cur = (dis + e.first) % n;
                dist[cur] = e.second;
            }

            for (int v = 0; v < 2 * n; v++) {
                dist[(v + 1) % n] = min(dist[(v + 1) % n], dist[v % n] + 1);
            }
            for (int v = 0; v < n; v++) {
                if (dist[v] + dis < d[v]) {
                    d[v] = dist[v] + dis;
                    pq.push({-d[v], v});
                }
            }
        }
        for (int v = 0; v < n; v++) {
            cout << d[v] << ' ';
        }
        cout << '\n';
    }

    return 0;
}