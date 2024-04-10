#include <bits/stdc++.h>

#define int int64_t
#define all(x) begin(x), end(x)

using namespace std;

void solve() {
    int n;
    cin >> n;
    int t = n;
    int k = 1;
    while(t % 2 == 0) {
        t /= 2;
        k++;
    }
    // t >= (2^k - 1)
    if(t + 1 > (1LL << k)) {
        cout << (1LL << k) << "\n";
    } else { // t * t <= n
        if(t == 1) {
            cout << -1 << "\n";
        } else {
            cout << t << "\n";
        }
    }
    // 0 + 1 + ... + (k-1) = k*(k-1)/2
    
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