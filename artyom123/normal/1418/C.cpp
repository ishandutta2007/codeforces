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
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &c : a) cin >> c;
        vector<vector<int>> dp(n + 1, vector<int>(2, INF));
        dp[0][1] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2; j++) {
                dp[i + 1][1 - j] = min(dp[i + 1][1 - j], dp[i][j] + a[i] * j);
                if (i + 2 <= n) dp[i + 2][1 - j] = min(dp[i + 2][1 - j], dp[i][j] + (a[i] + a[i + 1]) * j);
            }
        }
        cout << min(dp[n][0], dp[n][1]) << "\n";
    }
    return 0;
}