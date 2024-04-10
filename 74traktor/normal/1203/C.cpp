#include <bits/stdc++.h>

using namespace std;

#define int long long

int gcd(int a, int b) {
    while (a > 0 && b > 0) {
        int t = a % b;
        a = b, b = t;
    }
    return a + b;
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x = 0, y;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> y;
        x = gcd(x, y);
    }
    int ans = 0;
    for (int i = 1; i * i <= x; ++i) {
        if (x % i == 0) {
            ans += 1;
            if (i * i != x) ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}