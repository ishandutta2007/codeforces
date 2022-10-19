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

inline int power(int a, int n) {
    int cur = 1;
    while (n) {
        if (n & 1) {
            cur = cur * a % mod;
        }
        a = a * a % mod;
        n >>= 1;
    }
    return cur;
}

void solve1() {
    int n;
    cin >> n;
    vector <int> fact(n + 1, 1), rfact(n + 1, 1);
    for (int i = 2; i <= n; ++i) fact[i] = fact[i - 1] * i % mod;
    rfact[n] = power(fact[n], mod - 2);
    for (int i = n - 1; i > 1; --i) rfact[i] = rfact[i + 1] * (i + 1) % mod;

    auto cnk = [&](int nn, int kk) {
        return fact[nn] * rfact[kk] % mod * rfact[nn - kk] % mod;
    };

    vector <int> dp1(n + 1, 1), dp2(n + 1);
    for (int i = 2; i <= n; ++i) {
        dp1[i] = (dp1[i - 1] + (i - 1) * dp1[i - 2]) % mod;
    }
    dp2[0] = 1;
    for (int i = 2; i <= n; ++i) {
        dp2[i] = (dp2[i - 2] * (i - 1)) % mod;
    }
    int ans = 0;
    for (int k = 0; k * 4 <= n; ++k) {
        int cnt_p = k * 2;
        int cnt = cnk(n - cnt_p, cnt_p);
        int now = cnt * dp2[cnt_p] % mod * power(2, k) % mod;
        now = now * dp1[n - k * 4] % mod;
        ans = (ans + now) % mod;
    }
    cout << ans << "\n";
}

void solve2() {
    int n;
    cin >> n;
    vector <int> p;
    for (int i = 1; i <= n; ++i) p.push_back(i);
    int ans = 0;
    do {
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            if (abs((i + 1) - p[p[i] - 1]) > 1) {
                ok = false;
                break;
            }
        }
        ans += ok;
    } while (next_permutation(p.begin(), p.end()));
    cout << ans;
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
            solve1();
        }
        //  while (true) {}
    } else {

    }
}

/*

 */