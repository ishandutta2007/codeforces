#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e9 + 7;
const int M = 321;
const int N = 3e5 + 10;
const int POW = 20;

vector <int> g[N];
int par[N], h1[N], h2[N];
bool used[N];

void dfs(int v, int p) {
    par[v] = p;
    used[v] = true;
    for (auto t: g[v])
        if (!used[t]) {
            dfs(t, v);
            h2[v] = max(h2[v], h2[t]);
        }
    h2[v]++;
}

void dfs2(int v, int h) {
    h1[v] = h;
    for (auto t: g[v])
        if (t != par[v])
            dfs2(t, h + 1);
}

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    int n, x;
    cin >> n >> x;
    x--;
    fr(i, n - 1) {
        int v, u;
        cin >> v >> u;
        g[--v].pb(--u);
        g[u].pb(v);
    }

    dfs(0, -1);
    fill(used, used + n, false);
    dfs2(0, 0);

    int cur = x;
    while (par[cur] != -1 && h1[x] - h1[par[cur]] < h1[par[cur]] - h1[0])
        cur = par[cur];

    cout << 2 * (h1[cur] - h1[0] + h2[cur] - 1);
}