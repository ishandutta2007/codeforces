#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define ll long long
const int mod = 998244353;
const int alpha = 18;

inline int add(int a, int b) {
    if (a + b >= mod) return a + b - mod;
    return a + b;
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt_q = 0;
    for (char c: s) {
        if (c == '?') ++cnt_q;
    }
    int dp[1 << alpha][alpha + 1];
    int p[n + 1][alpha + 1];
    for (int i = 0; i <= alpha; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (j == 0) p[j][i] = 1;
            else p[j][i] = (ll) p[j - 1][i] * (ll) i % mod;
        }
    }
    for (int c = 0; c < n; ++c) {
        int cnt = cnt_q, mask = 0;
        for (int l = 0; c - l >= 0 && c + l < n; ++l) {
            if (l > 0) {
                char le = s[c - l];
                char ri = s[c + l];
                if (le == '?' && ri == '?') --cnt;
                else if (le == '?') {
                    --cnt;
                    mask |= (1 << ri - 'a');
                } else if (ri == '?') {
                    --cnt;
                    mask |= (1 << le - 'a');
                } else {
                    if (le != ri) break;
                }
            }
            for (int len = 0; len <= alpha; ++len) {
                dp[mask][len] = add(dp[mask][len], p[cnt][len]);
            }
        }
        cnt = cnt_q;
        mask = 0;
        for (int l = 0; c - l >= 0 && c + l + 1 < n; ++l) {
            char le = s[c - l];
            char ri = s[c + l + 1];
            if (le == '?' && ri == '?') --cnt;
            else if (le == '?') {
                --cnt;
                mask |= (1 << ri - 'a');
            } else if (ri == '?') {
                --cnt;
                mask |= (1 << le - 'a');
            } else {
                if (le != ri) break;
            }
            for (int len = 0; len <= alpha; ++len) {
                dp[mask][len] = add(dp[mask][len], p[cnt][len]);
            }
        }
    }
    for (int i = 0; i < alpha; ++i) {
        for (int mask = 0; mask < (1 << alpha); ++mask) {
            if ((mask >> i) & 1) continue;
            for (int len = 0; len <= alpha; ++len) {
                dp[mask | (1 << i)][len] = add(dp[mask | (1 << i)][len], dp[mask][len]);
            }
        }
    }
    int q;
    cin >> q;
    while (q--) {
        string qs;
        cin >> qs;
        int mask = 0;
        for (char c : qs) {
            mask |= (1 << c - 'a');
        }
        cout << dp[mask][(int)qs.size()] << "\n";
    }
}