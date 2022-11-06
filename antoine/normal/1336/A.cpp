#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int MxN = (int)2e5 + 9;
vector<int> adj[MxN + 9];
int depth[MxN + 9];
int sz[MxN + 9];

void dfs(const int u, const int p) {
    sz[u] = 1;
    for(int v : adj[u])
        if(v != p) {
            depth[v] = depth[u] + 1;
            dfs(v, u);
            sz[u] += sz[v];
        }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n, k;
    cin >> n >> k;
    for(int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }



    dfs(1, -1);

    vector<int> v;
    for(int i = 1; i <= n; ++i)
        v.push_back(depth[i] - sz[i] +1);
sort(v.rbegin(), v.rend());
cout << accumulate(v.begin(), v.begin() + k, 0LL);

    return 0;
}