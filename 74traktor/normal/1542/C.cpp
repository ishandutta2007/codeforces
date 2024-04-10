#include<bits/stdc++.h>

using namespace std;

long long lcm(long long x, long long y) {
    return x * y / __gcd(x, y);
}

main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, ans = 0, mod = 1000000007;
        cin >> n;
        vector < pair < long long, long long > > good;
        long long x = 1;
        for (long long i = 1;; ++i) {
            x = lcm(i, x);
            good.push_back({i, x});
            if (x > n) break;
        }
        for (int i = (int)good.size() - 2; i >= 0; --i) {
            ans += (good[i].first + 1) * (n / good[i].second - n / good[i + 1].second);
            ans %= mod;
        }
        cout << ans << '\n';
    }
}