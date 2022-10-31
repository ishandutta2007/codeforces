#include<bits/stdc++.h>

using namespace std;

#define int long long
int const maxn = 4005;
int a[maxn], m, cur;
int dp[maxn][maxn];
int inf = 1e18;
int Sz[maxn], f[maxn];

int dfs(int l, int r) {
    if (l == r) {
        cur++;
        dp[cur][1] = (m - 1) * a[l];
        dp[cur][0] = 0;
        Sz[cur] = 1;
        return cur;
    }
    int pos = l;
    for (int i = l; i <= r; ++i) {
        if (a[i] < a[pos]) pos = i;
    }
    if (pos == l || pos == r) {
        int c;
        if (pos == l) c = dfs(l + 1, r);
        else c = dfs(l, r - 1);
        cur++;
        for (int sz = 0; sz <= Sz[c] + 1; ++sz) {
            f[sz] = -inf;
        }
        for (int sz = 0; sz <= Sz[c]; ++sz) {
            f[sz] = max(f[sz], dp[c][sz]);
            f[sz + 1] = max(f[sz + 1], dp[c][sz] - 2 * (sz + 1) * a[pos] + a[pos] + a[pos] * m);
        }
        for (int sz = 0; sz <= Sz[c] + 1; ++sz) {
            dp[cur][sz] = f[sz];
        }
        Sz[cur] = Sz[c] + 1;
    }
    else {
        int c1 = dfs(l, pos - 1), c2 = dfs(pos + 1, r);
        cur++;
        for (int sz = 0; sz <= Sz[c1] + Sz[c2] + 1; ++sz) {
            f[sz] = -inf;
        }
        for (int sz1 = 0; sz1 <= Sz[c1]; ++sz1) {
            for (int sz2 = 0; sz2 <= Sz[c2]; ++sz2) {
                f[sz1 + sz2] = max(f[sz1 + sz2], dp[c1][sz1] + dp[c2][sz2] - 2 * sz1 * sz2 * a[pos]);
                f[sz1 + sz2 + 1] = max(f[sz1 + sz2 + 1], dp[c1][sz1] + dp[c2][sz2] - 2 * (sz1 + 1) * (sz2 + 1) * a[pos] + a[pos] + a[pos] * m);
            }
        }
        for (int sz = 0; sz <= Sz[c1] + Sz[c2] + 1; ++sz) {
            dp[cur][sz] = f[sz];
        }
        Sz[cur] = Sz[c1] + Sz[c2] + 1;
    }
    return cur;
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int node = dfs(1, n);
    cout << dp[node][m] << '\n';
    return 0;
}