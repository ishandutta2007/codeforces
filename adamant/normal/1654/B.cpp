#include <bits/stdc++.h>

#define int int64_t
#define all(x) begin(x), end(x)

using namespace std;

const int maxn = 1e5 + 42;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    int cnt[26] = {0};
    for(int i = 0; i < n; i++) {
        cnt[s[i] - 'a']++;
    }
    int i = 0;
    while(cnt[s[i] - 'a'] > 1) {
        cnt[s[i] - 'a']--;
        i++;
    }
    cout << s.substr(i) << "\n";
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}