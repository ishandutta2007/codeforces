#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

bool is_pal(string s) {
    return s == string(s.rbegin(), s.rend());
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int ans = 0;
    int n = s.size();
    for(int i = 0; i < n; i++) {
        for(int j = 1; i + j <= n; j++) {
            string t = s.substr(i, j);
            if(!is_pal(t)) {
                ans = max(ans, (int)t.size());
            }
        }
    }
    cout << ans << endl;
    return 0;
}