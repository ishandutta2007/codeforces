#include <bits/stdc++.h>
 
using namespace std;

#define all(x) begin(x), end(x)
#define int int64_t

const int mod = 998244353;

int fact(int n) {
    return n ? n * fact(n - 1) % mod : 1;
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n + 1];
    a[0] = a[1] = 0;
    for(int i = 2; i <= n; i++) {
        a[i] = i * (a[i - 1] + 1) % mod;
    }
    cout << (fact(n) * n % mod - a[n] + mod) % mod << endl;
    return 0;
}