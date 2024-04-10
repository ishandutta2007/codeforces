#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
//using namespace __gnu_pbds;

//typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define int int64_t
#define all(x) begin(x), end(x)

const int mod = 1e9 + 7;

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
    int n, k;
    cin >> n >> k;
    int x[k + 1], y[k + 1];
    int seg[2 * n];
    fill(seg, seg + 2 * n, 0);
    for(int i = 1; i <= k; i++) {
        cin >> x[i] >> y[i];
        x[i]--, y[i]--;
        seg[x[i]] = seg[y[i]] = i;
    }
    int ans = 0;
    int t = n - k - 1;
    int idx = k + 1;
    for(int i = 0; i < 2 * n; i++) {
        vector<int> cnt(n + 1);
        for(int j = (i + 1) % (2 * n); ; j = (j + 1) % (2 * n)) {
            if(seg[j] == seg[i]) {
                if(seg[j]) {
                    break;
                } else if(cnt[0] == t) {
                    seg[j] = seg[i] = idx++;
                    t--;
                    break;
                }
            }
            cnt[seg[j]]++;
        }
    }
    for(int i = 0; i < 2 * n; i++) {
        vector<int> cnt(n + 1);
        for(int j = (i + 1) % (2 * n); ; j = (j + 1) % (2 * n)) {
            if(seg[j] == seg[i]) {
                break;
            }
            cnt[seg[j]]++;
        }
        for(int i = 1; i <= n; i++) {
            ans += cnt[i] % 2;
        }
    }
    cout << ans / 4 << "\n";
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