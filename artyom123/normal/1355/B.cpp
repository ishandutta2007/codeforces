#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb emplace_back
#define all(x) (x).begin(), (x).end()

const int INF = 1e9 + 1;

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
        sort(all(a));
        int ans = 0;
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; i++) {
            if (a[i - 1] > i) continue;
            dp[i] = 1 + dp[i - a[i - 1]];
        }
        for (auto &c : dp) ans = max(ans, c);
        cout << ans << "\n";
    }
    return 0;
}