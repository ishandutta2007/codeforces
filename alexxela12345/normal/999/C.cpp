#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    map<int, int> m;
    for (char el : s) {
        m[(int) el - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (m[i] < k) {
            k -= m[i];
            m[i] = 0;
        } else {
            m[i] -= k;
            break;
        }
    }
    string ans;
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.size(); i++) {
        if (m[s[i] - 'a'] > 0) {
            m[s[i] - 'a']--;
            ans += s[i];
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans;

    return 0;    
}