#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double

signed main() {
    int ans = 0, n;
    cin >> n;
    string s;
    cin >> s;
    vector<char> res(s.size());
    for (int i = 2; i <= s.size(); i += 2) {
        if (s[i - 1] == s[i - 2]) {
            ans++;
            res[i - 2] = 'a';
            res[i - 1] = 'b';
        }
        else {
            res[i - 1] = s[i - 1];
            res[i - 2] = s[i - 2];
        }
    }
    cout << ans << endl;
    for (int i = 0; i < s.size(); i++) {
        cout << res[i];
    }
}