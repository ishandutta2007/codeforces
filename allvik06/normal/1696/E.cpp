#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <string>
#include <bitset>
#include <chrono>
#include <cmath>
#include <set>
#include <queue>
#include <array>
#include <map>
#include <iomanip>
#include <random>

using namespace std;
#define int long long
const int MAXN = 4e5 + 10;
const int mod = 1e9 + 7;

inline int power(int a, int x) {
    if (x == 0) return 1;
    if (x & 1) return a * power(a, x - 1) % mod;
    else return power(a * a % mod, x >> 1);
}
vector <int> fact, rfact;

inline int cnk(int n, int k) {
    return (fact[n] * rfact[k] % mod) * rfact[n - k] % mod;
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int n;
    cin >> n;
    n++;
    fact.resize(MAXN, 1);
    rfact.resize(MAXN, 1);
    for (int i = 2; i < MAXN; ++i) {
        fact[i] = fact[i - 1] * i % mod;
    }
    rfact[MAXN - 1] = power(fact[MAXN - 1], mod - 2);
    for (int i = MAXN - 2; i > 1; --i) {
        rfact[i] = rfact[i + 1] * (i + 1) % mod;
    }
    int ans = 0;
    int cur = 0;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    if (a[0] == 0) {
        cout << 0;
        return 0;
    }
    for (int i = n - 1; i >= 0; --i) {
        while (cur < a[i]) {
            ans = (ans + cnk(cur + i, i)) % mod;
            ++cur;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0) continue;
        ans = (ans + cnk(i + a[i] - 1, i)) % mod;
    }
    cout << (ans - 1 + mod) % mod;
}

/*

 */