#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

const int N = 200005;

int c[N];
vector<int> g[N];
int n;

void dfs(int u, int p, int col) {
    c[u] = col;
    for (int e : g[u]) {
        if (e == p) continue;
        dfs(e, u, 1 - col);
    }
} 

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    dfs(1, 0, 0);

    int cnt = 0;
    for (int i = 1; i <= n; i++) cnt += c[i];

    cout << min(cnt, n - cnt) - 1;



    return 0;
}