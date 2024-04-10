#include <bits/stdc++.h>

using namespace std;
#define ll long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string ans;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'b') ans.push_back(s[i]);
        }
        for (int i = 0; i < n; ++i) {
            if (s[i] != 'b') ans.push_back(s[i]);
        }
        cout << ans << "\n";
    }
}