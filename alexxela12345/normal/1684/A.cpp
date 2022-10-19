#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;

void solve() {
    string s;
    cin >> s;
    if (s.size() == 2) {
        cout << s.back() << endl;
    } else {
        cout << *min_element(s.begin(), s.end()) << endl;
    }
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