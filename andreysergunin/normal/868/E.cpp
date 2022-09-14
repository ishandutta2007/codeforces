// MIPT Shock Content
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <cassert>
#include <unordered_map>
#include <fstream>
#include <random>
#include <cstring>
#include <complex>
#include <bitset>
 
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
typedef complex<ld> Complex;

mt19937 rr(random_device{}());

const int MAXN = 55;
const int INF = 1e9;

int dp[2 * MAXN][MAXN][MAXN];

vector<int> g[MAXN];
int wg[MAXN][MAXN];
int id[MAXN][MAXN];

int t[MAXN];
vector<pii> e;

int dfs0(int v, int p = -1) {
    for (int u : g[v]) {
        if (u == p) {
            continue;
        }
        t[v] += dfs0(u, v);
    }
    return t[v];
}

int solve(int u, int v, int x, int y) {
    // cout << u << " " << v << " " << x << " " << y << " "  << endl;
    if (x + y == 0) {
        return 0;
    }
    if (x == 0) {
        return INF;
    }
    if (dp[id[u][v]][x][y] != INF) {
        return dp[id[u][v]][x][y];
    }
    if (sz(g[v]) == 1) {
        return dp[id[u][v]][x][y] = solve(v, u, y, 0) + wg[u][v];
    }

    int k = x + y;

    int ans = 0;
    for (int w : g[v]) {
        if (w == u) {
            continue;
        }

        int lf = 0, rg = x;
        while (rg - lf > 1) {
            int cnt = (lf + rg) / 2;
            int h = cnt;
            for (int s : g[v]) {
                if (s == u || s == w) {
                    continue;
                }
                for (int p = 0; p <= x - h; ++p) {
                    if (solve(v, w, cnt, k - cnt) > solve(v, s, p, k - p)) {
                        h += p - 1;
                        break;
                    }
                    if (p == x - h) {
                        h = x; 
                        break;
                    }
                }
            }
            if (h == x) {
                rg = cnt;
            } else {
                lf = cnt;
            }
        }
        ans = max(ans, solve(v, w, rg, k - rg) + wg[u][v]);
    }
    return dp[id[u][v]][x][y] = ans;
}

int main() {

    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; ++i)  {
        int u, v, weight;
        cin >> u >> v >> weight;
        --u; --v;
        g[u].push_back(v);
        wg[u][v] = weight;
        g[v].push_back(u);
        wg[v][u] = weight;
        e.push_back({u, v});
        id[u][v] = 2 * i;
        e.push_back({v, u});
        id[v][u] = 2 * i + 1;
    }

    int s;
    cin >> s;
    --s;
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        --x;
        ++t[x];
    }

    for (int i = 0; i < 2 * n - 2; ++i) {
        for (int j = 0; j <= m; ++j) {
            for (int k = 0; k <= m; ++k) {
                dp[i][j][k] = INF;
            }
        }
    }

    dfs0(s);

    int ans = INF;
    for (int u : g[s]) {
        ans = min(ans, solve(s, u, t[u], m - t[u]));
    }

    cout << ans << endl;

}