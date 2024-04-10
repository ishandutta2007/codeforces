#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 1;

string solve(int n, string s) {
    for (char c = '1'; c <= '9'; c++) {
        string ans = "", s1 = "", s2 = "";
        for (int i = 0; i < n; i++) {
            if (s[i] > c) {
                if (s2.size() == 0 || s2.back() <= s[i]) {
                    ans += '2';
                    s2.push_back(s[i]);
                } else {
                    break;
                }
            }
            if (s[i] == c) {
                if (s2.size() == 0 || s2.back() <= s[i]) {
                    ans += '2';
                    s2.push_back(s[i]);
                } else {
                    ans += '1';
                    s1.push_back(s[i]);
                }
            }
            if (s[i] < c) {
                if (s1.size() == 0 || s1.back() <= s[i]) {
                    ans += '1';
                    s1.push_back(s[i]);
                } else {
                    break;
                }
            }
        }
        if (ans.size() == n) {
            return ans;
        }
    }
    return "-";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << solve(n, s) << "\n";
    }
    return 0;
}