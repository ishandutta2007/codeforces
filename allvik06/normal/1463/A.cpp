#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        if ((a + b + c) % 9 == 0 && (a + b + c) / 9 <= min(a, min(b, c))) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
}