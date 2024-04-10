#include <bits/stdc++.h>

using namespace std;
#define ll long long
const ll INF = 1e16;
#define f first
#define s second

void solve1(int n, ll r1, ll r2, ll r3, ll d, vector <ll>& a) {
    vector <pair <ll, ll>> dp(n, {INF, INF});
    dp[0].f = min(r1, r3) * a[0] + r3;
    dp[0].s = min(min(r1, r3) * (a[0] + 1), r2);
    for (int i = 1; i < n; ++i) {
        ll v1 = dp[i - 1].f + d + min(r1, r3) * a[i] + r3;
        ll v2 = dp[i - 1].f + d + min(min(r1, r3) * (a[i] + 1), r2) + 2 * d + min(min(r1, r3), r2);
        ll v3 = dp[i - 1].s + d + min(min(r1, r2) * (a[i] + 1), r2) + d + min(min(r1, r3), r2) + d + min(min(r1, r3), r2);
        dp[i].f = min(min(v1, v2), v3);
        ll v4 = dp[i - 1].f + d + min(min(r1, r3) * (a[i] + 1), r2);
        ll v5 = dp[i - 1].s + d + min(min(r1, r3) * (a[i] + 1), r2) + d + min(min(r1, r3), r2) + d;
        dp[i].s = min(v4, v5);
        if (i == n - 1) {
            ll v6 = dp[i - 1].s + d + min(r1, r3) * a[i] + r3 + d + min(min(r1, r3), r2);
            dp[i].f = min(dp[i].f, v6);
        }
    }
    cout << dp[n - 1].f;
}

int solve2() {

}

signed main (){
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    if (1) {
        int n;
        ll r1, r2, r3, d;
        cin >> n >> r1 >> r2 >> r3 >> d;
        vector <ll> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        solve1(n, r1, r2, r3, d, a);
    }
    else {
        int t;
        cin >> t;
        while (t--) {

        }
    }
}