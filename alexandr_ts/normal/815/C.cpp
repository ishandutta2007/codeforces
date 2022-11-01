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
const ll INF = 1e15 + 10;
const int LOG = 30;
const ll MOD = 1e9 + 7;
const int N = 5e3 + 10;

vector<int> g[N];

ll d1[N][N];
ll d2[N][N];
int sz[N];
int c[N], d[N];

void dfs(int v) {
    if (g[v].size() == 0) {
        d1[v][0] = 0;
        d1[v][1] = c[v] - d[v];
        d2[v][0] = 0;
        d2[v][1] = c[v];
        sz[v] = 1;
        return;
    }

    sz[v] = 1;

    int bigCh = -1;
    for (auto u: g[v]) {
        dfs(u);
        sz[v] += sz[u];
        if (bigCh == -1 || sz[bigCh] < sz[u])
            bigCh = u;
    }

    fill(d1[v], d1[v] + sz[v] + 10, INF);
    fill(d2[v], d2[v] + sz[v] + 10, INF);

    //d1[v][0] = 0;

    for (int i = sz[bigCh]; i >= 0; i--) {
        d1[v][i + 1] = d1[bigCh][i] + c[v] - d[v];
        d2[v][i] = d2[bigCh][i];
    }
    for (int i = sz[bigCh] + 1; i >= 1; i--) {
        d2[v][i] = min(d2[v][i], d2[v][i - 1] + c[v]);
    }

    for (auto u: g[v]) {
        if (u == bigCh) continue;
        for (int j = sz[v]; j >= 1; j--) {
            for (int i = 1; i <= min(j, sz[u]); i++) {
                d1[v][j] = min(d1[v][j], d1[u][i] + d1[v][j - i]);
                d2[v][j] = min(d2[v][j], d2[u][i] + d2[v][j - i]);
            }
        }
    }
    for (int i = sz[v]; i >= 0; i--) {
        d1[v][i] = min(d1[v][i], d2[v][i]);
    }
}

void solve() {
    int n, b;
    cin >> n >> b;
    for (int i = 0; i < n; i++) {
        if (!i) {
            cin >> c[i] >> d[i];
        } else {
            int par;
            cin >> c[i] >> d[i] >> par;
            g[par - 1].pb(i);
        }
    }

    dfs(0);

//    for (int j = 0; j < n; j++) {
//        cout << endl;
//        cout << "v: " << j + 1 << endl;
//
//        for (int i = 0; i <= sz[j] + 2; i++) cout << d1[j][i] << " ";cout << endl;
//        for (int i = 0; i <= sz[j] + 2; i++) cout << d2[j][i] << " ";cout << endl;
//    }

    for (int i = sz[0]; i >= 0; i--) {
        if (min(d1[0][i], d2[0][i]) <= b) {
            cout << i;
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("a.in", "r", stdin);
    solve();

}