#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define fi first
#define se second
#define ll long long

const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if (min(r1, r2) >= max(l1, l2)) {
            ll total = (ll)n * (min(r1, r2) - max(l1, l2));
            if (total >= k) {
                cout << 0 << "\n";
                continue;
            }
            k -= total;
            if (k <= (ll)n * (max(r1, r2) - min(l1, l2)) - total) {
                cout << k << "\n";
                continue;
            }
            ll ans = (ll)n * (max(r1, r2) - min(l1, l2)) - total;
            k -= ans;
            cout << ans + k * 2 << "\n";
        } else {
            ll ans = INFLL;
            for (int x = 1; x <= n; x++) {
                ll k1 = k;
                ll now = (ll)x * (max(l1, l2) - min(r1, r2));
                if (k1 <= (ll)x * (max(r1, r2) - min(l1, l2))) {
                    ans = min(ans, now + k);
                    continue;
                }
                now += (ll)x * (max(r1, r2) - min(l1, l2));
                k1 -= (ll)x * (max(r1, r2) - min(l1, l2));
                ans = min(ans, now + 2 * k1);
            }
            cout << ans << "\n";
        }
    }
    return 0;
}