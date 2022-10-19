#include <bits/stdc++.h>

//#define int long long
//#define double long double
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
using namespace std;

const int maxn = 300000;
vector<int> g[maxn];
int used[maxn];
void dfs(int v) {
    used[v] = 1;
    for (auto u : g[v]) {
        if (!used[u]) {
            dfs(u);
        }
    }
}

vector<int> ans;
int useda[maxn];
void dfs2(int v) {
    used[v] = 1;
    bool ch = 1;
    for (auto u: g[v]) {
        if (useda[u]) {
            ch = 0;
        }
    }
    if (ch) {
        ans.pb(v);
        useda[v] = 1;
    }
    for (auto u: g[v]) {
        if (!used[u]) {
            dfs2(u);
        }
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            g[i] = {};
            used[i] = 0;
        }
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            g[u].pb(v);
            g[v].pb(u);
        }
        dfs(0);
        bool f = 0;
        for (int i = 0; i < n; ++i) {
            if (used[i] == 0) {
                f = 1;
            }
        }
        if (f)  {
            cout << "NO\n";
        } else {
            ans.clear();
            for (int i = 0; i < n; ++i) {
                useda[i] = 0;
                used[i]  = 0;
            }
            dfs2(0);
            cout << "YES\n";
            cout << ans.size() << '\n';
            for (auto i: ans) {
                cout << i+1 << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}