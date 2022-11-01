#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 3e2 + 10;
const int INF = 2e9 + 1;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-8;
const int MAX = 5e6 + 1;
const int MAX2 = 1e4;

vector <int> g[N][N];
bool used[N];

void dfs(int v, int col) {
    used[v] = true;
    fr(i, (int)g[col][v].size())
        if (!used[g[col][v][i]])
            dfs(g[col][v][i], col);
}

int main() {
    //freopen("input.txt", "r", stdin);
    int n, m, v, u, col;
    cin >> n >> m;
    fr(i, m) {
        cin >> v >> u >> col;
        g[col][--v].pb(--u);
        g[col][u].pb(v);
    }

    int q;
    cin >> q;
    fr(i, q) {
        cin >> v >> u;
        v--, u--;
        int ans = 0;
        fr(col, m + 1) {
            fill(used, used + n + 1, false);
            dfs(v, col);
            if (used[u])
                ans++;
        }
        cout << ans << endl;
    }


}