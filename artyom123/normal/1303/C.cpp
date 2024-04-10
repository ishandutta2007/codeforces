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
        string s;
        cin >> s;
        int n = s.size();
        vector<set<char>> a(26);
        for (int i = 0; i < n - 1; i++) {
            a[s[i] - 'a'].insert(s[i + 1]);
            a[s[i + 1] - 'a'].insert(s[i]);
        }
        string ans = "";
        vector<int> usd(26);
        while (ans.size() < 26) {
            char now = 'a';
            int mn = INF;
            for (int i = 0; i < 26; i++) {
                if (a[i].size() < mn && !usd[i]) {
                    mn = a[i].size();
                    now = 'a' + i;
                }
            }
            ans.push_back(now);
            usd[now - 'a'] = 1;
            if (mn == 0) {
                continue;
            }
            while (1) {
                char tmp = '$';
                for (auto &p : a[now - 'a']) {
                    if (!usd[p - 'a']) {
                        ans.push_back(p);
                        tmp = p;
                        usd[p - 'a'] = 1;
                        break;
                    }
                }
                now = tmp;
                if (now == '$') {
                    break;
                }
            }
        }
        for (int i = 0; i < 25; i++) {
            a[ans[i] - 'a'].erase(ans[i + 1]);
            a[ans[i + 1] - 'a'].erase(ans[i]);
        }
        bool good = true;
        for (auto &c : a) {
            if (c.size() > 0) {
                good = false;
            }
        }
        if (good) {
            cout << "YES" << "\n" << ans << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    return 0;
}