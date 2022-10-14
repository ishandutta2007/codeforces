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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int x, y, z;
    cin >> x >> y >> z;
    vector<int> r(x), g(y), b(z);
    for (auto &c : r) cin >> c;
    for (auto &c : g) cin >> c;
    for (auto &c : b) cin >> c;
    sort(all(r)); sort(all(g)); sort(all(b));
    reverse(all(r)); reverse(all(g)); reverse(all(b));
    vector<vector<vector<ll>>> dp(x + 1, vector<vector<ll>>(y + 1, vector<ll>(z + 1)));
    ll ans = 0;
    for (int i = 0; i <= x; i++) {
        for (int j = 0; j <= y; j++) {
            for (int k = 0; k <= z; k++) {
                if (i && j) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k] + r[i - 1] * g[j - 1]);
                if (j && k) dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k - 1] + g[j - 1] * b[k - 1]);
                if (i && k) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + r[i - 1] * b[k - 1]);
                ans = max(ans, dp[i][j][k]);
            }
        }
    }
    cout << ans;
    return 0;
}