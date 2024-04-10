#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int MxN = (int) 2e5 + 9;

int queryDist(const int u) {
    cout << "d " << u << endl;
    int resp;
    cin >> resp;
    return resp;
}

int queryNode(const int u) {
    cout << "s " << u << endl;
    int resp;
    cin >> resp;
    if (resp == -1)
        for (;;) {}
    return resp;
}

int n, D;
vector<int> adj[MxN + 9];
int parent[MxN + 9];
int depth[MxN + 9];
int cnt[MxN + 9];
int height[MxN + 9];

void dfs(const int u) {
    if (depth[u] == D)
        adj[u].clear();
    for (int v : adj[u]) {
        adj[v].erase(find(adj[v].begin(), adj[v].end(), u));
        depth[v] = depth[u] + 1;
        parent[v] = u;
        dfs(v);
        height[u] = max(height[u], height[v] + 1);
    }
    adj[u].erase(remove_if(adj[u].begin(), adj[u].end(), [](const int v) {
        return depth[v] + height[v] < D;
    }), adj[u].end());

    cnt[u] = 1;
    for (int v : adj[u])
        cnt[u] += cnt[v];
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    D = queryDist(1);


    dfs(1);
    DBG(cnt[1])

    int root = 1;
    while (depth[root] < D) {

        int u = root;
        while (depth[u] < D) {
            assert(!adj[u].empty());
            int mx = 0;
            for (const int v : adj[u])
                mx = max(mx, (int) adj[v].size());
            for (const int v : adj[u])
                if ((int) adj[v].size() == mx) {
                    u = v;
                    break;
                }
        }

        const int d = queryDist(u);
        if (!d) {
            root = u;
            break;
        }

        assert(d % 2 == 0);
        for (int rep = d / 2; rep > 0; --rep)
            u = parent[u];
        assert(depth[root] <= depth[u]);
        assert(adj[u].size() > 1);
        root = queryNode(u);
    }
    cout << "! " << root << endl;
    return 0;
}