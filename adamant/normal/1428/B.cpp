#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)

const int maxn = 1000;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    set<char> ch(all(s));
    if(ch.size() == 1 || ch == set<char>{'-', '>'} || ch == set<char>{'-', '<'}) {
        cout << n << endl;
    } else {
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans += s[i] == '-' || s[(i + 1) % n] == '-';
        }
        cout << ans << endl;
    }
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