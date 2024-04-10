#include<bits/stdc++.h>

using namespace std;

#define int long long

int gcd(int a, int b) {
    while (a > 0 && b > 0) {
        int c = a % b;
        a = b, b = c;
    }
    return a + b;
}

inline void solve() {
    int r, b, k;
    cin >> r >> b >> k;
    if (r * (k - 1) + gcd(r, b) < b || b * (k - 1) + gcd(r, b) < r) {
        cout << "REBEL" << '\n';
    }
    else cout << "OBEY" << '\n';
}

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}