#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;


const int MxN = (int)2e5 + 9;

bool dfs(const int u, vector<int> adj[MxN + 9], int vis[MxN + 9]) {
    assert(!vis[u]);
    vis[u] = 1;
    for(int v : adj[u]) {
        if(vis[v] == 2)
            continue;
        if(vis[v] == 1 || dfs(v,adj,vis))
            return true;
    }

    vis[u] = 2;
    return false;
}


vector<int> adj1[MxN + 9];
vector<int> adj2[MxN + 9];
int vis1[MxN + 9];
int vis2[MxN + 9];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj1[u].push_back(v);
        adj2[v].push_back(u);
    }


    string ans;
    for(int i = 1; i <= n; ++i) {
        ans += vis1[i] || vis2[i] ? 'E' : 'A';
        bool b1 = !vis1[i] && dfs(i, adj1, vis1);
        bool b2 = !vis2[i] && dfs(i, adj2, vis2);
        if(b1 || b2) {
            cout << -1;
            exit(0);
        }
    }

    cout << count(ans.begin(), ans.end(), 'A') << '\n' << ans;
    return 0;
}