#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb emplace_back

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        vector<string> ans(k);
        for (int i = 0; i < k; i++) {
            ans[i] += s[i];
        }
        if (ans[0] != ans[k - 1]) {
            cout << ans[k - 1] << "\n";
            continue;
        }
        vector<int> cnt(26);
        for (auto &c : s) {
            cnt[c - 'a']++;
        }
        int r = 0;
        for (auto &c : cnt) {
            if (c > 0) r++;
        }
        if (r == 1) {
            for (int i = k; i < s.size(); i++) {
                ans[i % k] += s[i];
            }
            cout << ans[0] << "\n";
            continue;
        }
        for (int i = 0; i < 26; i++) {
            if (cnt[i] > 0) {
                cnt[i] -= k;
                break;
            }
        }
        r = 0;
        for (auto &c : cnt) {
            if (c > 0) r++;
        }
        if (r == 1) {
            for (int i = k; i < s.size(); i++) {
                ans[i % k] += s[i];
            }
            cout << ans[0] << "\n";
            continue;
        } else {
            cout << ans[0];
            for (int i = k; i < s.size(); i++) {
                cout << s[i];
            }
            cout << "\n";
        }
    }
    return 0;
}