#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
//using namespace __gnu_pbds;

//typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define int int64_t
#define all(x) begin(x), end(x)

int mod = 1e9 + 7;

int add(int a, int b) {
    return (a + b) % mod;
}
int sub(int a, int b) {
    return (a + mod - b) % mod;
}
int mul(int a, int b) {
    return a * b % mod;
}
int bpow(int x, int n) {
    return n ? n % 2 ? mul(x, bpow(x, n - 1)) : bpow(mul(x, x), n / 2) : 1;
}
int inv(int x) {
    return bpow(x, mod - 2);
}

int bit(int msk, int i) {
    return (msk >> i) & 1;
}

void solve() {
    int n;
    cin >> n;
    int a[n];
    int G[n][n];
    for(int i = 0; i < n; i++) {
        G[i][i] = 0;
        cin >> a[i];
        for(int j = 0; j < i; j++) {
            G[i][j] = mul(a[i], inv(add(a[i], a[j])));
            G[j][i] = mul(a[j], inv(add(a[i], a[j])));
        }
    }
    const int sz = 1 << n;
    int P[sz];
    int ans = 0;
    for(int i = 1; i < sz; i++) {
        int prod = 1;
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                if(bit(i, j) && !bit(i, k)) {
                    prod = mul(prod, G[j][k]);
                }
            }
        }
        P[i] = prod;
        for(int s = i & (i - 1); s; s = i & (s - 1)) {
            int prod = 1;            
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < n; k++) {
                    if(bit(i, j) && !bit(i, k) && !bit(s, j)) {
                        prod = mul(prod, G[j][k]);
                    }
                }
            }
            P[i] = sub(P[i], mul(P[s], prod));
        }
        ans = add(ans, mul(__builtin_popcount(i), P[i]));
    }
    cout << ans << "\n";
}

signed main() {
    //ignore = freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    t = 1;//cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}