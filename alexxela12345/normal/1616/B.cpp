#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;

void solve() {
    int n;
    cin >> n;
    string  s;
    cin >> s;
    int cur = 0;
    while (cur + 1 < n && (s[cur + 1] < s[cur] || (s[cur + 1] == s[cur] && s[cur] != s[0]))) {
        cur++;        
    }
    s = s.substr(0, cur + 1);
    cout << s;
    reverse(s.begin(), s.end());
    cout << s;
    cout <<  '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}