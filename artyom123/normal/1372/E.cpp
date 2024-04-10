#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define ld long double

const int INF = 2e9 + 1;
const ll INFLL = 1e18 + 1;
const int mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(m, vector<int>(m));
    vector<vector<pair<int, int>>> a(m);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        while (k--) {
            int l, r;
            cin >> l >> r;
            l--; r--;
            for (int c = l; c <= r; c++) a[c].pb(l, r);
        }
    }
    for (int len = 1; len <= m; len++) {
        for (int l = 0; l + len <= m; l++) {
            int r = l + len - 1;
            for (int k = l; k <= r; k++) {
                int cnt = 0;
                for (auto &c : a[k]) cnt += (c.fi >= l && c.se <= r);
                dp[l][r] = max(dp[l][r], cnt * cnt + (k > l ? dp[l][k - 1] : 0) + (k < r ? dp[k + 1][r] : 0));
            }
        }
    }
    cout << dp[0][m - 1];
    return 0;
}