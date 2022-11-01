#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e6 + 3;
const ll MOD = 1e9 + 7;
const ll INF = 2e9 + 10;

vector <int> g[N];

bool pet[N];

bool used[N];

void dfs(int v) {
    used[v] = true;
    fr(i, g[v].size())
        if (!used[g[v][i]])
            dfs(g[v][i]);
}

bool ed(int v, int u) {
    auto t = lower_bound(g[v].begin(), g[v].end(), u);
    return (t != g[v].end() && *t == u);
}

int v[N], u[N];

int main() {
    ios_base::sync_with_stdio(false);
    //freopen("a.in", "r", stdin);
    ll n, m;
    cin >> n >> m;

    ll cntP = 0;

    fr(i, m) {

        cin >> v[i] >> u[i];
        if (v[i] == u[i]) {
            pet[v[i] - 1] = true;
            cntP++;
            continue;
        }
        g[--v[i]].pb(--u[i]);
        g[u[i]].pb(v[i]);
    }

    fr(i, n)
        sort(g[i].begin(), g[i].end());

    fr(i, n)
        if (g[i].size()) {
            dfs(i);
            break;
        }
    fr(i, n)
        if (!used[i] && (g[i].size() >= 1 || pet[i])) {
            cout << 0;
            return 0;
        }

    ll ans = 0;
    fr(i, n)
        ans += ((ll)g[i].size()) * ((ll)g[i].size() - 1) / 2;
    ans += cntP * (cntP - 1) / 2;
    ans += cntP * (m - cntP);
    cout << ans;
}