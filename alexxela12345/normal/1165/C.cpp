#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    string s;
    cin >> n >> s;
    string ans;
    for (int i = 0; i < n; i++) {
        if (ans.size() % 2 == 0) {
            ans.push_back(s[i]);
        } else if (ans.back() != s[i]) {
            ans.push_back(s[i]);
        }
    }
    if (ans.size() % 2 == 1) {
        ans.pop_back();
    }
    cout << n - ans.size() << endl << ans << endl;
    return 0;
}