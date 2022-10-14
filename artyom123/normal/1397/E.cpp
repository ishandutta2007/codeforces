#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double

const int INF = 2e9 + 1;
const ll INFLL = 1e18 + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    ll r1, r2, r3;
    cin >> r1 >> r2 >> r3;
    ll d; cin >> d;
    vector<ll> a(n);
    for (auto &c : a) cin >> c;
    vector<vector<ll>> dp(n, vector<ll>(2, INFLL));
    dp[0][0] = a[0] * r1 + r3;
    dp[0][1] = min(r2, (a[0] + 1) * r1);
    for (int i = 0; i + 1 < n; i++) {
        dp[i + 1][0] = min(dp[i + 1][0], dp[i][0] + d + r1 * a[i + 1] + r3);
        dp[i + 1][1] = min(dp[i + 1][1], dp[i][0] + d + min(r2, (a[i + 1] + 1) * r1));
        dp[i + 1][0] = min(dp[i + 1][0], dp[i][1] + d + a[i + 1] * r1 + r3 + 2 * d + r1);
        dp[i + 1][0] = min(dp[i + 1][0], dp[i][1] + d + r2 + d + r1 + d + r1);
        dp[i + 1][0] = min(dp[i + 1][0], dp[i][1] + d + (a[i + 1] + 2) * r1 + 2 * d + r1);
        dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + d + r2 + d + r1 + d);
        dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + d + (a[i + 1] + 1) * r1 + d + r1 + d);
        if (i == n - 2) {
            dp[i + 1][0] = min(dp[i + 1][0], dp[i][1] + d + a[i + 1] * r1 + r3 + d + r1);
        }
    }
    cout << dp[n - 1][0];
    return 0;
}