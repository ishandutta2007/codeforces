#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
int n, m, p;
ll a[200000];
mt19937 rng(880301);
int dp[1 << 15];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> p;
    uniform_int_distribution<int> U(0, n - 1);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        // m <= 60;
        for (int j = 0; j < m; ++j) a[i] = a[i] * 2 + (s[j] - '0');
    }
    // p <= 15;
    int ans = 0; ll ansv = 0;
    for (int trials = 1; trials <= 40; ++trials) {
        const int x = U(rng);
        if (a[x] == 0) continue;
        vector<int> pos;
        for (int j = 0; j < m; ++j) {
            if ((a[x] >> j) & 1) pos.push_back(j);
        }
        const int B = (int)pos.size();
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; ++i) {
            int mask = 0;
            for (int j = 0; j < B; ++j) {
                if ((a[i] >> pos[j]) & 1) mask |= 1 << j;
            }
            dp[mask] += 1;
        }
        for (int j = 0; j < B; ++j) {
            for (int k = 0; k < (1 << B); ++k) {
                if ((~k >> j) & 1) {
                    dp[k] += dp[k ^ (1 << j)];
                }
            }
        }
        /*
        cerr << x << '\n';
        for (int k = 0; k < (1 << B); ++k) cerr << dp[k] << ' ';
        cerr << '\n';
        */
        for (int k = 0; k < (1 << B); ++k) {
            if (dp[k] >= (n + 1) / 2) {
                // cerr << x << ' ' << k << '\n';
                int pc = __builtin_popcount(k);
                if (pc >= ans) {
                    ans = pc, ansv = 0;
                    for (int j = 0; j < B; ++j) {
                        if ((k >> j) & 1) ansv |= 1LL << pos[j];
                    }
                }
            }
        }
        
    }
    // cerr << ans << '\n';
    for (int i = m - 1; i >= 0; --i) {
        cout << (ansv >> i) % 2;
    }
    cout << endl;
    return 0;
}