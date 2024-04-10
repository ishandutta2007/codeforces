#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fc first
#define sc second
#define endl '\n'
#define ll long long
#define forn(i, n) for(int i = 0; i < (int) (n); i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

int u, v;
const int MAXN = (int) 1e5 + 7;
bool used[MAXN];
int color[MAXN];
vector <int> g[MAXN];
int cnt[MAXN];

void dfs(int v, int c) {
    used[v] = 1;
    color[v] = c;
    for (auto to : g[v]) {
        if (!used[to]) {
            dfs(to, (c == 1 ? 2 : 1));
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    #ifdef __linux__
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    vector <pair <int, int> > e;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        e.pb({u, v});
        g[u].pb(v);
        g[v].pb(u);   
    }
    vector <int> cnt(3);
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            dfs(i, 1);
        }
        cnt[color[i]]++;
    }
    for (int i = 0; i < m; i++) {
        u = e[i].fc;
        v = e[i].sc;
        if (color[u] == color[v]) {
            cout << -1 << endl;
            return 0;
        } 
    }
    for (int p = 1; p <= 2; p++) {
        cout << cnt[p] << endl;
        for (int i = 1; i <= n; i++) {
            if (color[i] == p) {
                cout << i << " ";
            }
        }
        cout << endl;
    }
}