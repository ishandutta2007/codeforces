#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int MxN = (int) 2e5 + 9;
vector<int> adj[MxN + 9];
bool vis[MxN + 9];
int chosen[MxN + 9];

void dfs(const int u) {
    chosen[u] = false;
    vis[u] = true;

    for(int v : adj[u])
        if(!vis[v]) {
            dfs(v);
            if(!chosen[v])
                chosen[u] = true;
        }
}

void f() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i<=n; ++i) {
        adj[i].clear();
        chosen[i] = vis[i] = 0;
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);

    int cnt = accumulate(chosen, chosen + n + 1, 0);
    cout << cnt << '\n';
    assert(cnt <= n/2);
    for(int i = 1; i <= n; ++i)
        if(chosen[i])
            cout << i << ' ';
        cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) f();
    return 0;
}