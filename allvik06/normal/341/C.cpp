#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <array>
#include <map>
#include <utility>
#include <set>
#include <cassert>

using namespace std;
#define int long long
const int mod = 1e9 + 7;
vector <int> f, rf;

inline int power(int a, int n) {
    if (n == 0) return 1;
    if (n & 1) return power(a, n - 1) * a % mod;
    else return power(a * a % mod, n >> 1);
}

inline void calc_f(int n) {
    f.resize(n + 1, 1);
    for (int i = 2; i <= n; ++i) {
        f[i] = (f[i - 1] * i) % mod;
    }
    rf.resize(n + 1, 1);
    rf[n] = power(f[n], mod - 2);
    for (int i = n - 1; i > 1; --i) {
        rf[i] = (rf[i + 1] * (i + 1)) % mod;
    }
}

inline int cnk(int n, int k) {
    return (f[n] * rf[k] % mod) * rf[n - k] % mod;
}

signed main() {
    int n;
    cin >> n;
    calc_f(n);
    vector <int> bad(n), c(n);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x == -1) {
            bad[i] = 1;
        } else {
            c[x - 1] = 1;
        }
    }
    int ans = 0, cnt_bad = 0, cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (bad[i] == 1 && c[i] == 0) ++cnt_bad;
        if (bad[i] == 1) ++cnt;
    }
    for (int i = 1; i <= cnt_bad; ++i) {
        int cur = cnk(cnt_bad, i) * f[cnt - i] % mod;
        if (i & 1) {
            ans = (ans + cur) % mod;
        } else {
            ans = (ans - cur + mod) % mod;
        }
    }
    ans = (f[cnt] - ans + mod) % mod;
    cout << ans;
    return 0;
}