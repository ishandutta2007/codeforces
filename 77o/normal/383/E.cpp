#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    const int N = 24;
    const int M = 1 << N;
    vector<int> dp(M);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int mask = 0;
        for (char c : s)
            mask |= 1 << (c - 'a');
        ++dp[mask];
    }
    for (int i = 0; i < N; i++)
        for (int mask = 0; mask < M; mask++)
            if (mask >> i & 1)
                dp[mask] += dp[mask ^ (1 << i)];
    int ans = 0;
    for (int mask = 0; mask < M; mask++) {
        ans ^= (n - dp[mask]) * (n - dp[mask]);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}