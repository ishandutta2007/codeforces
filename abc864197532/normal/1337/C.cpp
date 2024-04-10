#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>
#define X first
#define Y second
const int N = 200000;
vector <int> adj[N];
int depth[N], sz[N];

void dfs(int v, int pa) {
    depth[v] = ~pa ? depth[pa] + 1 : 1;
    sz[v] = 1;
    for (int u : adj[v]) if (u != pa) {
        dfs(u, v);
        sz[v] += sz[u];
    }
}

int main () {
    int n, u, v, k;
    cin >> n >> k;
    fop (i,0,n - 1) {
        cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(0, -1);
    vector <lli> tmp(n);
    fop (i,0,n) tmp[i] = sz[i] - depth[i];
    sort(tmp.begin(), tmp.end());
    cout << accumulate(tmp.begin() + k, tmp.end(), 0ll) << endl;
}