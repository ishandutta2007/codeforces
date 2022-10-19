#include <iostream>
#include <vector>
#include <set>
#include <chrono>
#include <map>
#include <algorithm>

using namespace std;
#define int long long
const int MAXN = 1e6;
const int mod = 1e9 + 7;

int power(int a, int x) {
    if (x == 0) return 1;
    if (x & 1) return (a * power(a, x - 1)) % mod;
    else return power((a * a) % mod, x >> 1);
}

vector <int> facts;

inline int C(int n, int k) {
    if (n < k) return 0;
    return (facts[n] * power(facts[k], mod - 2) % mod) * power(facts[n - k], mod - 2) % mod;
}

signed main() {
    if (0) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    facts.resize(MAXN + 1);
    facts[0] = 1;
    for (int i = 1; i <= MAXN; ++i) facts[i] = (facts[i - 1] * i) % mod;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        if (n == m) {
            cout << n * k % mod << "\n";
            continue;
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int val = (i + 1) * k % mod, rev = power(power(2, n - i - 1), mod - 2);
            int cnt = C(n - i - 2, n - m - 1);
            ans += (cnt * val % mod) * rev % mod;
            ans %= mod;
        }
        cout << ans << "\n";
    }
}