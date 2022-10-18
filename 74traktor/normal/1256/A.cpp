#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int a, b, n, s;
    cin >> a >> b >> n >> s;
    if (a * n >= s) {
        if (s % n <= b) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    else {
        if (s - a * n <= b) {
            cout << "YES" << '\n';
        }
        else cout << "NO" << '\n';
    }
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}