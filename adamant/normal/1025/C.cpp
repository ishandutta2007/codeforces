#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    s = s + s;
    int cur = 1;
    int ans = 1;
    for(int i = 1; i < s.size(); i++) {
        if(s[i] == s[i - 1]) {
            cur = 1;
        } else {
            cur++;
        }
        ans = max(ans, cur);
    }
    cout << min<int>(ans, s.size() / 2) << endl;
    return 0;
}