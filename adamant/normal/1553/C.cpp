#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
//using namespace __gnu_pbds;

//typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define all(x) begin(x), end(x)

#define int int64_t
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
    string s;
    cin >> s;
    int n = s.size();
    int ans = n;
    for(int msk = 0; msk < (1 << n); msk++) {
        int C[2] = {0, 0};
        for(int i = 0; i < n; i++) {
            int c = (i % 2);
            C[c] += (s[i] == '?' ? ((msk >> i) & 1) : s[i] - '0');
            if(C[c] > (n - i) / 2 + C[!c]) {
                //cout << i << ' ' << n << endl;
                ans = min(ans, i + 1);
                break;
            }
            if(C[!c] > (n - i - 1) / 2 + C[c]) {
                //cout << i << ' ' << n << endl;
                ans = min(ans, i + 1);
                break;
            }
        }
    }
    cout << ans << "\n";
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