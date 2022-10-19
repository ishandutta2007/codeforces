#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, p;
    cin >> n >> m >> p;

    int mx = 0;
    string res(m, '0');
    vector<string> s(n);

    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    for (int rep = 0; rep < 30; rep++) {
        int foo = rng() % n;
        vector<int> on_bits;
        for (int i = 0; i < m; i++) {
            if (s[foo][i] == '1') on_bits.push_back(i);
        }
        vector<int> dp(1 << (on_bits.size()), 0);
        for (int i = 0; i < n; i++) {
            int mask = 0;
            for (int j = 0; j < on_bits.size(); j++) {
                if (s[i][on_bits[j]] == '1') mask += (1 << j);
            }
            dp[mask]++;
        }
        for (int i = 0; i < on_bits.size(); i++) {
            for (int mask = (1 << on_bits.size()) - 1; mask >= 0; mask--) {
                if ((mask & (1 << i)) == 0) {
                    dp[mask] += dp[mask ^ (1 << i)];
                }
            }
        }
        for (int mask = 0; mask < (1 << on_bits.size()); mask++) {
            if (dp[mask] >= (n + 1) / 2) {
                if (__builtin_popcount(mask) > mx) {
                    mx = __builtin_popcount(mask);
                    res = string(m, '0');
                    for (int i = 0; i < on_bits.size(); i++) {
                        if (mask & (1 << i)) {
                            res[on_bits[i]] = '1';
                        }
                    }
                }
            }
        }
    }
    
    cout << res << '\n';

    return 0;
}