#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<vector<ll> > mat;

const ld PI = acos(-1);
const int INF = 1e9;
const int LOG = 30;
const int N = 2e5 + 10;

bool used[N];
int sz[N];
vector<int> g[N];

void calcSz(int v, int par) {
    sz[v] = 1;
    for (auto u: g[v]) {
        if (!used[u] && u != par) {
            calcSz(u, v);
            sz[v] += sz[u];
        }
    }
}

int ans[N];

void dfs(int v, int par, int siz, int lvl) {
    bool fnd = false;
    for (auto u: g[v]) {
        if (used[u] || u == par) continue;
        if (sz[u] >= (siz + 1) / 2) {
            dfs(u, v, siz, lvl);
            fnd = true;
            break;

        }
    }
    if (!fnd) {
        used[v] = true;
        ans[v] = lvl;
        for (auto u: g[v]) {
            if (!used[u]) {
                calcSz(u, v);
                dfs(u, v, sz[u], lvl + 1);
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;
        g[--v].pb(--u);
        g[u].pb(v);
    }
    calcSz(0, -1);
    dfs(0, -1, n, 0);
    for (int i = 0; i < n; i++)
        cout << (char)('A' + ans[i]) << " ";

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("a.in", "r", stdin);
    solve();

}