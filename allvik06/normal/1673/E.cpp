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

inline int cnk(int n, int k) {
    while (n || k) {
        int val_n = n % 2, val_k = k % 2;
        n >>= 1;
        k >>= 1;
        if (val_n < val_k) return 0;
    }
    return 1;
}

const int MOD = (1 << 20);

void solve1() {
    int n, k;
    cin >> n >> k;
    int kk = k;
    k = max(0LL, k - 2);
    vector <int> flex(n), a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    if (k == 0) flex[0] = 1;
    for (int i = 1; i < n; ++i) {
        if (k > 0) flex[i] = cnk(i - 1, k - 1);
    }
    vector <int> ans(MOD);
    for (int i = 1; i < n; ++i) {
        int cur = a[i];
        for (int r = i; r < n - 1; ++r) {
            if (r > i) {
                if (a[r] >= 20) break;
                cur *= (1LL << a[r]);
                if (cur >= MOD) break;
            }
            int cnt = n - 1 - (r - i + 2);
            if (flex[cnt]) ans[cur] ^= 1;
        }
    }
    k = max(kk - 1, 0LL);
    if (k == 0) flex[0] = 1;
    else flex[0] = 0;
    for (int i = 1; i < n; ++i) {
        if (k > 0) flex[i] = cnk(i - 1, k - 1);
        else flex[i] = 0;
    }
    int cur = a[0];
    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            if (a[i] >= 20) break;
            cur *= (1LL << a[i]);
            if (cur >= MOD) break;
        }
        if (i == n - 1) {
            if (kk == 0) ans[cur] ^= 1;
            break;
        }
        int cnt = n - i - 2;
        if (flex[cnt]) ans[cur] ^= 1;
    }
    cur = 1;
    for (int i = n - 1; i > 0; --i) {
        if (a[i] * cur < MOD) {
            int cnt = i - 1;
            if (flex[cnt]) ans[a[i] * cur] ^= 1;
        }
        if (a[i] >= 20) break;
        cur *= (1LL << a[i]);
        if (cur >= MOD) break;
    }
    int f = 0;
    for (int i = MOD - 1; i > 0; --i) {
        if (ans[i]) {
            f = i;
            break;
        }
    }
    for (int i = f; i >= 0; --i) cout << ans[i];
}

signed main(int32_t argc, char **argv) {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    if (1) {
        int t = 1;
        //cin >> t;
        while (t--) {
            solve1();
        }
        //  while (true) {}
    } else {

    }
}

/*

 */