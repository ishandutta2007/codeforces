#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include<cp/debugger.hpp>
#else 
#define debug(...) 42
#endif

const int MOD = 1000000007;

int add(int x, int y) {
    return (x + y) % MOD;
}

int mult(int x, int y) {
    return 1LL * x * y % MOD;
}

int sub(int x, int y) {
    return (x - y + MOD) % MOD;
}

int power(int x, int y) {
    int res = 1;
    while (y) {
        if (y % 2) res = mult(res, x);
        y >>= 1;
        x = mult(x, x);
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> p2(n + 1);
    p2[0] = 1;
    for (int i = 1; i <= n; i++) p2[i] = mult(p2[i - 1], 2);
    vector<int> f(n + 1), pref(n + 1);
    f[0] = 1, pref[0] = 1;;
    for (int i = 1; i <= n; i++) {
        int rem = n - i;
        int lowest = max(1, i - rem + 2);
        // get sum from lowest - 1 to i - 1
        f[i] = sub(pref[i - 1], (lowest - 1 == 0 ? 0 : pref[lowest - 2]));
        if (lowest == 1) f[i] = add(f[i], 1);
        pref[i] = add(pref[i - 1], f[i]);
    }
    int ip2n = power(power(2, n), MOD - 2);
    for (int i = n; i >= 1; i--) {
        int base = (i == 1 ? 2 : 1);
        int from = (i + n) / 2;
        int rem = n - from;
        cout << mult(mult(f[i - 1], ip2n), mult(base, p2[rem])) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}