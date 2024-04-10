#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int mod = 998244353;

int bpow(int x, int n) {
    return n > 0 ? n % 2 ? x * bpow(x, n - 1) % mod : bpow(x * x % mod, n / 2) : 1;
}

void solve() {
    int n;
    cin >> n;
    int a[n];
    int mxl = 1e9, mnr = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(i == 0) {
            mxl = a[i];
        } else {
            mxl = min(mxl, a[i] - mnr);
            mnr = max(mnr, a[i] - mxl);
        }
    }
    cout << (mxl < 0 ? "NO\n" : "YES\n");
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