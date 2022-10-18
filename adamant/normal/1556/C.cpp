#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
//using namespace __gnu_pbds;

//typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define int int64_t
#define all(x) begin(x), end(x)

int mod = 998244353;

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

const int maxn = 1e3 + 42;

int lbal[maxn][maxn], rbal[maxn][maxn];

void solve() {
    int n;
    cin >> n;
    int c[n];
    for(int i = 0; i < n; i++) {
        cin >> c[i];
        c[i] = (i % 2 ? -1 : 1) * c[i];
    }
    int ans = 0;
    for(int i = 0; i + 1 < n; i += 2) {
        ans += min(abs(c[i]), abs(c[i + 1]));
    }
    for(int i = 0; i < n; i++) {
        int bal = 0;
        for(int j = i; j < n; j++) {
            bal += c[j];
            lbal[i][j] = j == i ? bal : min(bal, lbal[i][j - 1]);
        }
    }
    for(int i = 0; i < n; i++) {
        int bal = 0;
        for(int j = i; j >= 0; j--) {
            bal -= c[j];
            rbal[j][i] = j == i ? bal : min(bal, rbal[j + 1][i]);
        }
    }
    for(int i = 1; i < n; i += 2) {
        for(int j = i + 1; j + 1 < n; j += 2) {
            ans += min(
                max(abs(c[i - 1]) + lbal[i][j] + 1, (int)0), 
                max(abs(c[j + 1]) + rbal[i][j] + 1, (int)0)
            );
        }
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