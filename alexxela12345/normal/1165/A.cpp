#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x, y;
    cin >> n >> x >> y;
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    while (s.size() < x) {
        s += "0";
    }
    while (s.size() > x) {
        s.pop_back();
    }
    int ans = 0;
    for (int i = 0; i < x; i++) {
        if (i == y) {
            if (s[i] == '0') {
                ans++;
            } 
        } else if (s[i] == '1') {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}