#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    while (a > 0 && b > 0) {
        int c = a % b;
        a = b, b = c;
    }
    return a + b;
}

void solve() {
    int a, b;
    cin >> a >> b;
    if (gcd(a, b) == 1) cout << "Finite" << '\n';
    else cout << "Infinite" << '\n';
}

main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}