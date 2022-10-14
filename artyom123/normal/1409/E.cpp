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
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> x(n);
        for (int i = 0; i < n; i++) {
            cin >> x[i];
        }
        for (int i = 0; i < n; i++) {
            int l; cin >> l;
        }
        sort(all(x));
        vector<int> dp(n + 1);
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = dp[i + 1];
            int ind = (upper_bound(all(x), x[i] + k) - x.begin());
            dp[i] = max(dp[i], ind - i);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int ind = (upper_bound(all(x), x[i] + k) - x.begin());
            ans = max(ans, ind - i + dp[ind]);
        }
        cout << ans << "\n";
    }
    return 0;
}