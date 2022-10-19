#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;

void solve() {
    string s;
    cin >> s;
    int bal = 0;
    for (auto el : s) {
        if (el == 'A') {
            bal += 1;
        } else {
            bal -= 1;
        }
        if (bal < 0 ){
            cout << "NO" << endl;
            return;
        }
    }
    if (s.back() == 'A') {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
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