#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
const int maxn = (int) 1e6 + 10;
const int mod = (int) 1e9 + 7;
ll dp[55][55][2];
ll c[55][55];
int N, K;
ll rec(int n, int k, int t) {
    if(k < 0) return 0;
    if(n == 1) {
        if(k > 0) return 0;
        if(t) return 0;
        return 1;
    }
    if(n == 2) {
        if(k != 1) return 0;
        if(t != 1) return 0;
        return 1;
    }
    ll &res = dp[n][k][t];
    if(res != -1) return res;
    res = 0;
    if(t) {
        res = rec(n-1, k - 1, 0) * 1ll * (n-1)  % mod;
    } else {
        res = rec(n - 1, k, 1) * 1ll * (n-1) % mod;
    }
    for(int x = 1; x <= n-2; x++) {
        ll cur = 0;
        for(int kk = 0; kk <= k; kk++) {
            if(t) {
                cur = (cur + rec(x, kk, 1) * rec(n-1-x, k - kk - 1, 0)) % mod;
                cur = (cur + rec(x, kk, 0) * rec(n-1-x, k - kk - 1, 0)) % mod;
                cur = (cur + rec(x, kk, 0) * rec(n-1-x, k - kk - 1, 1)) % mod;
            } else {
                cur = (cur + rec(x, kk, 1) * rec(n-1-x, k - kk, 1)) % mod;
            }
        }
        cur = cur * c[n-2][x] % mod;
        cur = cur * x % mod;
        cur = cur * (n-1-x) % mod;
        res = (res + cur) % mod;
    }
    return res;
}
void solve() {
    cin >> N >> K;
    memset(dp, -1, sizeof dp);
    for(int i = 0; i <= N; i++) {
        for(int j = 1; j < i; j++) {
            c[i][j] = (c[i-1][j] + c[i-1][j-1]) % mod;
        }
        c[i][0] = c[i][i] = 1;
    }
    cout << (rec(N, K, 0) + rec(N, K, 1)) % mod << "\n";
}

int main() {
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}