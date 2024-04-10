#include <bits/stdc++.h>
using namespace std;
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
using ll = long long;
const int maxn = 1e6, INF = 1e9;
using ld = double;

int dp[5000][5001][2];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    int n; cin >> n;
    if(n == 1) return cout << 0, 0;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++)
        for(int j = 0; j <= (n + 1) / 2; j++)
            dp[i][j][0] = dp[i][j][1] = INF;
    dp[0][0][0] = 0;
    dp[0][1][1] = 0;
    dp[1][1][0] = max(0, a[1] - a[0] + 1);
    dp[1][1][1] = max(0, a[0] - a[1] + 1);
    for(int i = 1; i < n; i++)
        for(int k = 0; k <= (i + 2) / 2; k++) {
            dp[i][k][0] = min(dp[i - 1][k][0], dp[i - 1][k][1] + max(0, a[i] - a[i - 1] + 1));
            if(k && i > 1) dp[i][k][1] = min(dp[i - 2][k - 1][0] + max(0, a[i - 1] - a[i] + 1), dp[i - 2][k - 1][1] + max({0, a[i - 1] - a[i] + 1, a[i - 1] - a[i - 2] + 1}));

        }
    for(int k = 1; k <= (n + 1) / 2; k++) cout << min(dp[n - 1][k][0], dp[n - 1][k][1]) << ' ';
}