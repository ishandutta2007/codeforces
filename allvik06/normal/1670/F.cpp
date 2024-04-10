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
const int MAXB = 62;

vector <int> fact, rfact;

inline int power(int a, int n) {
    int cur = 1;
    while (n > 0) {
        if (n & 1) {
            cur = (cur * a) % mod;
        }
        a = (a * a) % mod;
        n >>= 1;
    }
    return cur;
}

void build_f(int n) {
    fact.resize(n + 1, 1);
    rfact.resize(n + 1, 1);
    for (int i = 2; i <= n; ++i) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    rfact[n] = power(fact[n], mod - 2);
    for (int i = n - 1; i > 1; --i) {
        rfact[i] = rfact[i + 1] * (i + 1) % mod;
    }
}

inline int cnk(int n, int k) {
    return fact[n] * rfact[k] % mod * rfact[n - k] % mod;
}

inline int solve(int n, int x, int z) {
    vector <vector <int>> dp(MAXB, vector <int> (2 * n + 1));
    dp[MAXB - 1][0] = 1;
    for (int i = MAXB - 2; i >= 0; --i) {
        int num = ((z >> i) & 1);
        int pl = ((x >> i) & 1);
        for (int now = num; now <= n; now += 2) {
            for (int prev = 0; prev <= 2 * n; ++prev) {
                int new_diff = min(2 * n, 2 * prev - now + pl);
                if (new_diff >= 0) {
                    dp[i][new_diff] = (dp[i][new_diff] + dp[i + 1][prev] * cnk(n, now)) % mod;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= 2 * n; ++i) ans = (ans + dp[0][i]) % mod;
    return ans;
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int n, l, r, z;
    cin >> n >> l >> r >> z;
    build_f(n);
    cout << (solve(n, r, z) - solve(n, l - 1, z) + mod) % mod;
    return 0;
}