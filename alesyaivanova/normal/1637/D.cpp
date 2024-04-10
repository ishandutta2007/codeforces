#include <bits/stdc++.h>

#pragma GCC target("sse4")

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())

const int maxn = 109;
bitset<maxn * maxn> dp[maxn];
int n;
int a[maxn];
int b[maxn];

void solve() {
    cin >> n;
    int sum = 0;
    int sqsum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        sqsum += a[i] * a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        sum += b[i];
        sqsum += b[i] * b[i];
    }
    dp[0] ^= dp[0];
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i] = ((dp[i - 1] << a[i - 1]) | (dp[i - 1] << b[i - 1]));
    }
    int ans = 0;
    for (int k = sum / 2; k >= 0; k--) {
        if (dp[n][k]) {
            ans = k;
            break;
        }
    }
//    cerr << " " << sum << " " << sqsum << " " << ans << "\n";
    ans = sum * sum - 2 * ans * (sum - ans);
//    cerr << " " << ans << "\n";
    ans += (n - 1) * sqsum - sqsum;
    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}