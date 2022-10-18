#include <bits/stdc++.h>

using namespace std;

#define int int64_t

// 1100
// 00
// 0011

int mysolve(int u, int v) {
    const int logn = 35;
    bitset<logn> U(u), V(v);
    int dp[logn][logn] = {0};
    dp[0][0] = 1;
    for(int j = 0; j < logn - 1; j++) {
        if(U[j] == V[j]) {
            dp[j + 1][0] = dp[j][0];
            for(int k = 1; k < logn - 1; k++) {
                dp[j + 1][k] = dp[j][k] | dp[j][k + 1];
            }
        } else if(U[j] == 0 && V[j] == 1) {
            for(int k = 1; k < logn; k++) {
                dp[j + 1][k - 1] = dp[j][k];
            }
        } else if(U[j] == 1 && V[j] == 0) {
            for(int k = 1; k < logn; k++) {
                dp[j + 1][k] = dp[j][k - 1] | dp[j][k];
            }
        }
    }
    return !dp[logn - 1][0];
}

map<int, int> stored[1001];

int brutesolve(int u, int v) {
    if(u > v) {
        return 1;
    } else if(u == v) {
        return 0;
    } else if(stored[u].count(v)) {
        return stored[u][v];
    }
    for(int w = u; w; w = u & (w - 1)) {
        if(!brutesolve(u + w, v)) {
            return stored[u][v] = 0;
        }
    }
    return stored[u][v] = 1;
}

void solve() {
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        cout << (mysolve(u, v) ? "NO" : "YES") << "\n";
    }
    
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }
}