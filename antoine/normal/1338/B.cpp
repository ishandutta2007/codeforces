#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;


const int MxN = (int) 1e5 + 9;
vector<int> adj[MxN + 9];
int depth[MxN + 9];

void dfs(const int u, const int par) {
    for (int v :adj[u])
        if (v != par) {
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int root = 1;
    while (adj[root].size() == 1)
        ++root;
    assert(root <= n);
    dfs(root, -1);

    {
        set<int> s;
        for (int i = 1; i <= n; ++i)
            if (adj[i].size() == 1)
                s.insert(depth[i] & 1);
        cout << (s.size() == 1 ? 1 : 3) << ' ';
    }

    int ans = n - 1;
    for (int u = 1; u <= n; ++u) {
        int cnt = 0;
        for (const int v : adj[u])
            cnt += adj[v].size() == 1;
        ans -= max(0, cnt - 1);
    }
    cout << ans;
    return 0;
}