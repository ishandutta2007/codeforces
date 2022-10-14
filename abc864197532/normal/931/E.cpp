#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    vector <string> abc[26];
    int n = s.length();
    for (int i = 0; i < n; ++i) {
        abc[s[0] - 'a'].push_back(s);
        rotate(s.begin(), s.begin() + 1, s.end());
    }
    double ans = 0;
    for (int r = 0; r < 26; ++r) if (abc[r].size()) {
        cout << '\n';
        int mx = 0;
        for (int i = 1; i < n; ++i) {
            vector <int> cnt(26, 0);
            int tmp = 0;
            for (string &s : abc[r]) {
                cnt[s[i] - 'a']++;
                if (cnt[s[i] - 'a'] == 1) tmp++;
                else if (cnt[s[i] - 'a'] == 2) tmp--;
            }
            mx = max(mx, tmp);
        }
        ans += 1.0 * mx / n;
    }
    cout << fixed << setprecision(10) << ans << endl;
}