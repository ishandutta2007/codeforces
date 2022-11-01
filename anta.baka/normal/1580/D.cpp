#ifndef DEBUG
#pragma GCC optimize("O3")
#endif

#include <bits/stdc++.h>

#define pb push_back
#define sz(a) (int)(a).size()

using namespace std;
using ll = long long;

const int N = 4001;
const ll inf = 1e18 + 228;

int n, m;
int a[N];
ll dp[N][N];
int sz[N];

int dfs(int l, int r) {
    int v = l;
    for (int i = l; i <= r; i++) {
        if (a[i] < a[v]) {
            v = i;
        }
    }
    sz[v] = 1;
    int lv = -1;
    if (l < v) {
        lv = dfs(l, v - 1);
        sz[v] += sz[lv];
    }
    int rv = -1;
    if (v < r) {
        rv = dfs(v + 1, r);
        sz[v] += sz[rv];
    }
    if (lv != -1 && rv != -1) {
        for (int i = 0; i <= sz[lv]; i++) {
            for (int j = 0; j <= sz[rv]; j++) {
                dp[v][i + j] = max(dp[v][i + j], dp[lv][i] + dp[rv][j] - 2LL * a[v] * i * j);
            }
        }
    } else if (lv != -1 || rv != -1) {
        int u = (lv != -1 ? lv : rv);
        for (int i = 0; i <= sz[u]; i++) {
            dp[v][i] = dp[u][i];
        }
    }
    for (int i = sz[v] - 1; i >= 0; i--) {
        if (dp[v][i] > -inf) {
            dp[v][i + 1] = max(dp[v][i + 1], dp[v][i] + 1LL * m * a[v] - 1LL * (2 * i + 1) * a[v]);
        }
    }
    return v;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < N; i++) {
        for (int j = 1; j < N; j++) {
            dp[i][j] = -inf;
        }
    }

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int root = dfs(0, n - 1);
    cout << dp[root][m] << endl;

    cout.flush();
    return 0;
}