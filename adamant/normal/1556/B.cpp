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

const int maxn = 6e5 + 42;

void solve() {
    int n;
    cin >> n;
    int a[n];
    int cnt[2] = {0, 0};
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] %= 2;
        cnt[a[i]]++;
    }
    if(abs(cnt[0] - cnt[1]) >= 2) {
        cout << -1 << "\n";
    } else {
        int ans = 1e12;
        int tar[n];
        for(int z = 0; z <= 1; z++) {
            for(int i = 0; i < n; i++) {
                tar[i] = (i % 2) ^ z;
            }
            if(count(tar, tar + n, 0) != cnt[0]) {
                continue;
            }
            int CNa[2] = {0, 0};
            int cur = 0;
            for(int i = 0; i < n; i++) {
                int target = 2 * CNa[a[i]] + (a[i] ? !z : z);
                cur += abs(i - target);
                CNa[a[i]]++;
            }
            ans = min(ans, cur);
        }
        cout << ans / 2 << "\n";
    }
}

signed main() {
    //ignore = freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}