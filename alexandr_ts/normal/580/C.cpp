#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb(a) push_back(a)

using namespace std;

typedef long long ll;

const ll N = 1e6;

vector <int> g[N];
bool used[N];
int ans = 0;
bool cat[N];

void dfs(int v, int cnt, int m) {
    //cout << v << " " << cnt << endl;
    used[v] = true;
    if (cnt > m)
        return;
    if (g[v].size() == 1 && v && (!cat[v] || cnt < m)) {
        //cout << cnt << endl;
        ans++;
        return;
    }
    fr(i, g[v].size())
        if (!used[g[v][i]])
            dfs(g[v][i], cat[v] ? cnt + 1 : 0, m);
}

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    int n, m, v, u;
    cin >> n >> m;
    fr(i, n) {
        cin >> v;
        if (v)
            cat[i] = true;
    }
    fr(i, n - 1) {
        cin >> v >> u;
        g[--v].pb(--u);
        g[u].pb(v);
    }

    dfs(0, 0, m);
    cout << ans;
}