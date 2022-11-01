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

vector<int> g[N];
int c[N];

void dfs(int v, int col) {
    c[v] = col;
    for (auto u: g[v])
        if (!c[u])
            dfs(u, 3 - col);
}

int v1[N], u1[N];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int v, u;
        cin >> v >> u;
        v1[i] = v, u1[i] = u;
        g[--v].pb(--u);
        g[u].pb(v);
        g[2 * i].pb(2 * i + 1);
        g[2 * i + 1].pb(2 * i);
    }

    for (int i = 0; i < 2 * n; i++)
        if (!c[i])
            dfs(i, 1);
    for (int i = 0; i < n; i++)
        cout << c[v1[i] - 1] << " " << c[u1[i] - 1] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("a.in", "r", stdin);
    solve();

}