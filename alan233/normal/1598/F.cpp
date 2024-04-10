// naive problems.
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 20;
int dp[maxn];
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<string> s(n);
    vector<int> sum(n), ms(n);
    vector<vector<int>> mp(n);
    for (int i = 0; i < n; i += 1) {
        cin >> s[i];
        mp[i].resize(s[i].size() + 1);
        for (char x : s[i]) {
            if (x == '(') sum[i] += 1; else sum[i] -= 1;
            ms[i] = min(sum[i], ms[i]);
            if (sum[i] <= ms[i]) mp[i][-sum[i]] += 1;
        }
    }
    vector<int> ssum(1 << n), dp(1 << n);
    int ans = 0;
    for (int i = 1; i < (1 << n); i += 1) {
        dp[i] = INT_MIN;
        for (int j = 0; j < n; j += 1) if ((i >> j) & 1) {
            ssum[i] += sum[j];
            if (ssum[i ^ (1 << j)] >= 0) {
                int pans = dp[i ^ (1 << j)] + (ssum[i ^ (1 << j)] <= s[j].size() ? mp[j][ssum[i ^ (1 << j)]] : 0);
                ans = max(ans, pans);
                if (ssum[i ^ (1 << j)] + ms[j] >= 0) dp[i] = max(pans, dp[i]);
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << ans;
    return 0;
}