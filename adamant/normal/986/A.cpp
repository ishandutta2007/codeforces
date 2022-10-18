#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)

const int maxn = 1e5 + 42;

vector<int> g[maxn];

void bfs(vector<int> &dist) {
    deque<int> que;
    for(int i = 0; i < (int)dist.size(); i++) {
        if(dist[i] == 0) {
            que.push_back(i);
        }
    }
    while(que.size()) {
        int v = que.front();
        que.pop_front();
        for(auto u: g[v]) {
            if(dist[v] + 1 < dist[u]) {
                dist[u] = dist[v] + 1;
                que.push_back(u);
            }
        }
    }
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k, s;
    cin >> n >> m >> k >> s;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    int u[m], v[m];
    for(int i = 0; i < m; i++) {
        cin >> u[i] >> v[i];
        u[i]--, v[i]--;
        g[u[i]].push_back(v[i]);
        g[v[i]].push_back(u[i]);
    }
    int dist[n][k];
    for(int z = 0; z < k; z++) {
        vector<int> dst(n, n + 1);
        for(int i = 0; i < n; i++) {
            if(a[i] == z) {
                dst[i] = 0;
            }
        }
        bfs(dst);
        for(int i = 0; i < n; i++) {
            dist[i][z] = dst[i];
        }
    }
    for(int i = 0; i < n; i++) {
        sort(dist[i], dist[i] + k);
        cout << accumulate(dist[i], dist[i] + s, 0) << ' ';
    }
    cout << endl;
    return 0;
}