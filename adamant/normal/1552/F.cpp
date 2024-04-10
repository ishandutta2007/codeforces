#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
//using namespace __gnu_pbds;

//typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define int int64_t
#define all(x) begin(x), end(x)

const int mod = 998244353;

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

void solve() {
    int n;
    cin >> n;
    int x[n], y[n], s[n], d[n], p[n + 1];
    fill(p, p + n + 1, 0);
    int ans = 0;
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> s[i];
        int k = lower_bound(x, x + i, y[i]) - x;
        d[i] = add(sub(x[i], y[i]), sub(p[i], p[k]));
        p[i + 1] = add(p[i], d[i]);
        if(s[i]) {
            ans = add(ans, d[i]);
        }
    }
    ans = add(ans, x[n - 1] + 1);
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