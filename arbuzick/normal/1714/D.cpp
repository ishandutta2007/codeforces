#include <bits/stdc++.h>

using namespace std;

void solve() {
    string t;
    cin >> t;
    int n;
    cin >> n;
    vector<string> s(n);
    set<string> used;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        used.insert(s[i]);
    }
    vector<int> dp(t.size() + 1, -1);
    vector<pair<int, int>> pr(t.size() + 1, make_pair(-1, -1));
    dp[0] = 0;
    for (int i = 0; i < (int)t.size(); ++i) {
        if (dp[i] == -1) {
            continue;
        }
        string nw = "";
        for (int j = i; j < i + 10 && j < (int)t.size(); ++j) {
            nw += t[j];
            if (used.count(nw) && (dp[j + 1] == -1 || dp[j + 1] > dp[i] + 1)) {
                dp[j + 1] = dp[i] + 1;
                pr[j + 1] = {i, j + 1};
            }
        }
        for (int j = (int)t.size() - 1; j >= i; --j) {
            if (dp[j + 1] != -1 && (dp[j + 1] < dp[j] || dp[j] == -1)) {
                dp[j] = dp[j + 1];
                pr[j] = pr[j + 1];
            }
        }
    }
    cout << dp[t.size()] << '\n';
    int pos = t.size();
    while (pr[pos].first != -1) {
        string nw = "";
        for (int i = pr[pos].first; i < pr[pos].second; ++i) {
            nw += t[i];
        }
        for (int j = 0; j < n; ++j) {
            if (s[j] == nw) {
                cout << j + 1 << ' ' << pr[pos].first + 1 << '\n';
                break;
            }
        }
        pos = pr[pos].first;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}