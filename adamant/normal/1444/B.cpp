#include <bits/stdc++.h>

using namespace std;

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
    return (a * b) % mod;
}

int bpow(int x, int n) {
    return n ? n % 2 ? mul(x, bpow(x, n - 1)) : bpow(mul(x, x), n / 2) : 1;
}

int inv(int x) {
    return bpow(x, mod - 2);
}

int fact(int n) {
    return n ? mul(n, fact(n - 1)) : 1;
}

int rfact(int n) {
    return inv(fact(n));
}

int nCr(int n, int r) {
    return mul(fact(n), mul(rfact(n - r), rfact(r)));
}


void solve() {
    int n;
    cin >> n;
    int a[2 * n];
    for(int i = 0; i < 2 * n; i++) {
        cin >> a[i];
    }
    sort(a, a + 2 * n);
    int ans = 0;
    for(int i = 0; i < 2 * n; i++) {
        if(i < n) {
            ans = sub(ans, a[i]);
        } else {
            ans = add(ans, a[i]);
        }
    }
    cout << mul(ans, nCr(2 * n, n)) << "\n";
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    t = 1; //cin >> t;
    while(t--) {
        solve();
    }
}