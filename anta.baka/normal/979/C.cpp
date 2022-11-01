#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
const int maxn = 3e5;

int n, x, y;
vector<int> g[maxn];
vector<int> cur, path;
int tsz[maxn];

void dfs(int v, int p) {
    cur.push_back(v);
    if(v == y) path = cur;
    for(int to : g[v])
        if(to != p) dfs(to, v);
    cur.pop_back();
}

void dfs1(int v, int p) {
    tsz[v] = 1;
    for(int to : g[v])
        if(to != p && to != path[1] && to != path[sz(path) - 2]) {
            dfs1(to, v); tsz[v] += tsz[to];
        }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    cin >> n >> x >> y; x--; y--;
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        g[u].push_back(v); g[v].push_back(u);
    }
    dfs(x, -1); dfs1(x, -1); dfs1(y, -1);
    cout << ll(n) * (n - 1) - tsz[x] * ll(tsz[y]);
}