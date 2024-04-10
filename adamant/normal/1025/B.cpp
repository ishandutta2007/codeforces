#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n], b[n], c[n];
    int ans = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        c[i] = a[i] / __gcd(a[i], b[i]) * b[i];
        ans = __gcd(ans, c[i]);
    }
    if(__gcd(ans, a[0]) > 1) {
        ans = __gcd(ans, a[0]);
    } else {
        ans = __gcd(ans, b[0]);
    }
    if(ans == 1) {
        cout << -1 << endl;
    } else {
        for(int i = 2; i * i <= ans; i++) {
            if(ans % i == 0) {
                cout << i << endl;
                return 0;
            }
        }
        cout << ans << endl;
    }
    return 0;
}