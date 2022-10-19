#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cassert>
#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <random>
#include <iomanip>
#include <chrono>
#include <bitset>
#include <queue>
#include <complex>
#include <functional>
#include <unordered_map>

using namespace std;
#define int long long
const int mod = 998244353;

inline int power(int x, int n) {
    int ans = 1;
    while (n) {
        if (n & 1) {
            ans = ans * x % mod;
        }
        x = x * x % mod;
        n >>= 1;
    }
    return ans;
}

vector <int> f, rf;

void build(int n) {
    f.assign(n + 1, 1);
    rf.assign(n + 1, 1);
    for (int i = 2; i <= n; ++i) f[i] = f[i - 1] * i % mod;
    rf[n] = power(f[n], mod - 2);
    for (int i = n - 1; i > 1; --i) rf[i] = rf[i + 1] * (i + 1) % mod;
}

inline int cnk(int n, int k) {
    if (n < k) return 0;
    return f[n] * rf[k] % mod * rf[n - k] % mod;
}

inline void solve() {
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    build(n);
    int ans = 1, l = 0, r = n - 1;
    while (true) {
        if (l == r) break;
        int l_sum = a[l++], r_sum = a[r--];
        while (l <= r && l_sum != r_sum) {
            if (l_sum < r_sum) l_sum += a[l++];
            else r_sum += a[r--];
        }
        if (l_sum != r_sum) break;
        int cl = 0, cr = 0;
        while (a[l] == 0 && l <= r) {
            ++cl;
            l++;
        }
        while (a[r] == 0 && l <= r) {
            ++cr;
            r--;
        }
        if (l > r) {
            int tmp = 0;
            for (int k = 0; k <= cl + 1; ++k) {
                tmp = (tmp + cnk(cl + 1, k)) % mod;
            }
            ans = ans * tmp % mod;
            break;
        }
        int tmp = 0;
        for (int k = 0; k <= min(cl, cr) + 1; ++k) {
            int val = cnk(cl + 1, k) * cnk(cr + 1, k) % mod;
            tmp = (tmp + val) % mod;
        }
        ans = ans * tmp % mod;
    }
    cout << ans << "\n";
}

signed main(int32_t argc, char **argv) {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    if (1) {
        int t = 1;
        cin >> t;
        while (t--) {
            solve();
        }
        //  while (true) {}
    }
}

/*

 */