#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pii pair<int, int>

void solve() {
    int n;
    cin >> n;
    if (n % 2050 != 0) {
        cout << -1 << '\n';
    } else {
        int val = n / 2050;
        int ans = 0;
        while (val > 0) {
            ans += val % 10;
            val /= 10;
        }
        cout << ans << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}