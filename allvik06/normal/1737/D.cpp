#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cassert>
#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <random>
#include <iomanip>
#include <chrono>
#include <bitset>
#include <queue>
#include <complex>
#include <functional>
#include <unordered_map>

using namespace std;
#define ll long long
const int INF = 1e9 + 1;
const ll BINF = 1e15;
const int MAXN = 500;
int w[MAXN][MAXN];
int f[MAXN][MAXN];

inline void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            w[i][j] = f[i][j] = INF;
        }
    }
    for (int i = 0; i < m; ++i) {
        int x, y, e;
        cin >> x >> y >> e;
        --x;
        --y;
        w[x][y] = w[y][x] = min(w[x][y], e);
        f[x][y] = f[y][x] = 1;
    }
    for (int i = 0; i < n; ++i) f[i][i] = 0;
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }
    ll ans = BINF;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (w[i][j] == INF) continue;
            ans = min(ans, (ll)(f[0][i] + f[j][n - 1] + 1) * w[i][j]);
            for (int k = 0; k < n; ++k) {
                ans = min(ans, (ll)w[i][j] * (f[0][k] + f[k][n - 1] + f[i][k] + 2));
            }
        }
    }
    cout << ans << "\n";
}

signed main(int32_t argc, char **argv) {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    if (1) {
        int t = 1;
        cin >> t;
        while (t--) {
            solve();
        }
        //  while (true) {}
    } else {

    }
}

/*

 */