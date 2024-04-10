#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define ld long double
#define pb emplace_back
#define pii pair<int, int>

const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        /// x -> (x + 1)
        ll left = 0, right = INF;
        while (right - left > 1) {
            ll mid = (left + right) / 2;
            if (a - b * min(c, mid * d) > 0) left = mid;
            else right = mid;
        }
        if (left == INF - 1) {
            cout << -1 << "\n";
            continue;
        }
        if (left == 0) {
            cout << a << "\n";
            continue;
        }
        ll x = left + 1;
        ll ans = a * x;
        ll k = (c + d - 1) / d; /// c <= k*d
        ll cnt1 = max(0LL, x - 1 - (k - 1));
        ll cnt2 = x - 1 - cnt1;
        ll sum1 = c * cnt1;
        ll sum2 = 0;
        if (cnt2 > 0) {
            ll p = min(k - 1, cnt2);
            sum2 = ((p + 1) * d * p) / 2;
        }
        cout << ans - b * sum1 - b * sum2 << "\n";
    }
    return 0;
}