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
vector <int> color, ans, ans2;

void dfs1 (int v, int pa) {
    ans[v] = color[v];
    for (int u : adj[v]) {
        if (u == pa) continue;
        dfs1(u, v);
        ans[v] += max(0, ans[u]);
    }
}

void dfs2 (int v, int pa) {
    ans2[v] = ans[v];
    if (~pa) ans2[v] += max(0, ans2[pa] - max(ans[v], 0));
    for (int u : adj[v]) {
        if (u == pa) continue;
        dfs2(u, v);
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, u, v;
    cin >> n;
    color.resize(n);
    ans.resize(n);
    ans2.resize(n);
    fop (i,0,n) {
        cin >> color[i];
        if (!color[i]) color[i] = -1;
    }
    fop (i,0,n-1) {
        cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs1(0, -1);
    dfs2(0,- 1);
    fop (i,0,n) cout << ans2[i] << " \n"[i == n - 1];
}