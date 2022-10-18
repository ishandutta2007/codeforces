#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> order_set;

#define int int64_t
#define all(x) begin(x), end(x)

const int mod = 1e9 + 7;

int bpow(int x, int n) {
    return n ? n % 2 ? x * bpow(x, n - 1) % mod : bpow(x * x % mod, n / 2) : 1;
}

int inv(int x) {
    return bpow(x, mod - 2);
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int d[n + 1][m + 1];
    d[0][0] = 0;
    const int inv2 = inv(2);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= min(i - 1, m); j++) {
            //cout << i << ' ' << j << endl;
            d[i][j] = (d[i - 1][j] + d[i - 1][j - 1]) * inv2 % mod;
        }
        d[i][0] = 0;
        if(i <= m) {
            d[i][i] = k * i % mod;
        }
    }
    cout << d[n][m] << "\n";
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}