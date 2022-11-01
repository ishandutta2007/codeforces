#include <bits/stdc++.h>


#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<vector<ll> > mat;

const ll INF = 1e15 + 10;
const ld EPS = 1e-9;
const ll MOD = 1e9 + 7;
const int N = 1e6 + 10;

vector<int> g[N];
int comp[N];
int cnt[N];

void dfs(int v, int c) {
    comp[v] = c;
    cnt[c]++;
    for (auto u: g[v])
        if (!comp[u])
            dfs(u, c);
}



void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        int v;
        if (!k) continue;
        cin >> v;
        v--;
        for (int j = 1; j < k; j++) {
            int u;
            cin >> u;
            u--;
            g[v].pb(u);
            g[u].pb(v);
        }
    }

    int cur = 1;
    for (int i = 0; i < n; i++)
        if (!comp[i])
            dfs(i, cur++);

    for (int i = 0; i < n; i++)
        cout << cnt[comp[i]] << " ";

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("a.in", "r", stdin);
    int t = 1;
    while (t--)
        solve();
}