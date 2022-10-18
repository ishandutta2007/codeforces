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

const int maxn = 1e6 + 42;

int F[maxn], RF[maxn];

int fact(int n) {
    return F[n] ? F[n] : F[n] = n ? n * fact(n - 1) % mod : 1;
}
int rfact(int n) {
    return RF[n] ? RF[n] : RF[n] = inv(fact(n));
}

int nCr(int n, int r) {
    return fact(n) * rfact(r) % mod * rfact(n - r) % mod;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    const int inv2 = inv(2);
    int ans = 0;
    for(int i = 1; i <= m; i++) {
        ans = (ans + (i + 1) * nCr(n - i, m - i) % mod * bpow(inv2, n - i + 1) % mod) % mod;
    }
    cout << ans * k % mod << endl;
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