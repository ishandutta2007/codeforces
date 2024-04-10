#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF = 2e18;

int main() {
    ios_base::sync_with_stdio(0);
    ll n, r1, r2, r3, d;
    cin >> n >> r1 >> r2 >> r3 >> d;
    vector<ll> a(n), t1(n), t2(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    ll ans = INF;
    for (int i = 0; i < n; i++) {
        t1[i] = a[i] * r1 + r3;
        t2[i] = min(a[i] * r1 + r1, r2) + r1;
    }
    vector<ll> post(n);
    for (int i = n - 1; i >= 0; i--) {
        if(i == n - 1) post[i] = min(t1[i], t2[i] + 2 * d);
        else post[i] = post[i + 1] + min(t1[i], t2[i]) + d;
    }
    ans = min(ans, post[0] + (n - 1) * d);
    vector<vector<ll>> dp(n, vector<ll>(2, INF));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            if (i == 0) {
                if (j == 0) dp[i][j] = min(t1[i], t2[i] + 2 * d);
                else dp[i][j] = t2[i];
            } else {
                if (j == 0) dp[i][j] = min(dp[i - 1][0] + min(t1[i], t2[i] + 2 * d), dp[i - 1][1] + t2[i] + 2 * d);
                else dp[i][j] = dp[i - 1][0] + t2[i];
            }
            if (j == 0) {
                if (i != n - 1) ans = min(ans, (n - 1) * d + dp[i][j] + post[i + 1]);
                else ans = min(ans, (n - 1) * d + dp[i][j]);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}