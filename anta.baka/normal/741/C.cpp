#pragma GCC optimize("Ofast")
#pragma GCC terget("sse,sse2,sse3,sse4,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
using ll = long long;
const int maxn = 1e5;

int n, a[maxn], b[maxn], col[2 * maxn];
vector<int> g[2 * maxn];
vector<bool> was;

void dfs(int v) {
    for(int to : g[v])
        if(!was[to]) {
            col[to] = !col[v];
            was[to] = true;
            dfs(to);
        }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
    }
    for(int i = 0; i < n; i++) {
        int u = 2 * i, v = 2 * i + 1;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    was.assign(2 * n, false);
    for(int u = 0; u < 2 * n; u++)
        if(!was[u]) {
            dfs(u);
        }
    for(int i = 0; i < n; i++) cout << col[a[i]] + 1 << ' ' << col[b[i]] + 1 << '\n';
}