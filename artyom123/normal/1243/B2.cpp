#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        vector<int> cnt(26);
        for (auto &c : s) {
            cnt[c - 'a']++;
        }
        for (auto &c : t) {
            cnt[c - 'a']++;
        }
        bool good = true;
        for (auto &c : cnt) {
            if (c % 2 != 0) {
                good = false;
            }
        }
        if (good) {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
            continue;
        }
        vector<pair<int, int>> ans;
        for (int i = 0; i < n; i++) {
            if (s[i] == t[i]) continue;
            for (int j = i + 1; j < n; j++) {
                if (s[j] == s[i]) {
                    ans.push_back({j, i});
                    swap(s[j], t[i]);
                    break;
                }
            }
            if (s[i] == t[i]) continue;
            for (int j = i + 1; j < n; j++) {
                if (t[j] == s[i]) {
                    ans.push_back({n - 1, j});
                    ans.push_back({n - 1, i});
                    swap(s[n - 1], t[j]);
                    swap(s[n - 1], t[i]);
                    break;
                }
            }
        }
        cout << ans.size() << "\n";
        for (auto &c : ans) {
            cout << c.first + 1 << " " << c.second + 1 << "\n";
        }
    }
    return 0;
}