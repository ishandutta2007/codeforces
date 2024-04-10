#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double
#define mp make_pair
#define ull unsigned long long

const int INF = 1e9 + 1;
const ll INFLL = (ll)1e18 + 1;
const ll mod = 998244353;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> x(n), y(n), s(n);
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i] >> s[i];
    vector<int> dp(n), pr(n + 1);
    for (int i = 0; i < n; i++) {
        int j = lower_bound(all(x), y[i]) - x.begin();
        dp[i] = (pr[i] - pr[j] + x[i] - y[i] + 2 * mod) % mod;
        pr[i + 1] = (pr[i] + dp[i]) % mod;
    }
    ll ans = x[n - 1] + 1;
    for (int i = 0; i < n; i++) {
        if (s[i]) ans += dp[i];
    }
    cout << ans % mod;
    return 0;
}