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
    string s, t;
    cin >> s >> t;
    int n = s.size();
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            string A = s.substr(i, j - i + 1);
            if(A.size() <= t.size()) {
                int k = t.size() - A.size();
                if(j - k >= 0) {
                    auto B = s.substr(j - k, k);
                    //cout << A << ' ' << B << endl;
                    A += string(B.rbegin(), B.rend());
                    if(A == t) {
                        cout << "YES\n";
                        return;
                    }
                }
            }
        }
    }
    cout << "NO\n";
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