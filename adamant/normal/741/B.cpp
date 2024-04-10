#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int maxn = 1e3 + 42;

int par[maxn], w[maxn], tw[maxn], tb[maxn], b[maxn];
int get(int v) {
    return v == par[v] ? v : par[v] = get(par[v]);
}

void uni(int a, int b) {
    a = get(a);
    b = get(b);
    if(a == b) {
        return;
    }
    par[a] = b;
    tw[b] += tw[a];
    tb[b] += tb[a];
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    iota(par, par + maxn, 0);
    int n, m, W;
    cin >> n >> m >> W;
    for(int i = 0; i < n; i++) {
        cin >> w[i];
        tw[i] = w[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        tb[i] = b[i];
    }
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        uni(a - 1, b - 1);
    }
    vector<int> group[n];
    for(int i = 0; i < n; i++) {
        group[get(i)].push_back(i);
    }
    int dp[n + 1][W + 1];
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < n; i++) {
        if(group[i].size()) {
            for(auto it: group[i]) {
                for(int j = 0; j + w[it] <= W; j++)  {
                    dp[i + 1][j + w[it]] = max(dp[i + 1][j + w[it]], dp[i][j] + b[it]);
                }
            }
        } else {
            tb[i] = 0;
            tw[i] = 0;
        }
        for(int j = 0; j + tw[i] <= W; j++) {
            dp[i + 1][j + tw[i]] = max(dp[i + 1][j + tw[i]], dp[i][j] + tb[i]);
        }
        for(int j = 1; j <= W; j++) {
            dp[i + 1][j] = max({dp[i][j], dp[i + 1][j], dp[i + 1][j - 1]});
        }
    }
    cout << dp[n][W] << endl;
    return 0;
}