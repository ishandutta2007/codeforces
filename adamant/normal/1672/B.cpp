#include <bits/stdc++.h>

#define int int64_t

using namespace std;

void solve() {
    string s;
    cin >> s;
    int bal = 0;
    for(auto c: s) {
        if(c == 'A') {
            bal++;
        } else {
            bal--;
        }
        if(bal < 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << (s.back() == 'B' ? "YES\n" : "NO\n");
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}