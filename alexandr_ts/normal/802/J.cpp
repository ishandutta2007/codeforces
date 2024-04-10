#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; ++i)
#define pb push_back
#define mp make_pair
#define frab(i, a, b) for (ll i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const int INF = 2e9 + 10;
const ld EPS = 1e-9;
const int M = 1e2 + 12;
const int N = 4e5 + 10;

vector <pair <int, int> > g[N];

int d[N];

void dfs(int v, int par) {
    for (auto t: g[v])
        if (t.first != par)
            dfs(t.first, v);
    int mx = 0;
    for (auto t: g[v])
        if (t.first != par)
            mx = max(mx, d[t.first] + t.second);
    d[v] = mx;
}

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    fr(i, n - 1) {
        int v, u, c;
        cin >> v >> u >> c;
        g[v].pb(mp(u, c));
        g[u].pb(mp(v, c));
    }

    dfs(0, -1);
    cout << d[0];

}