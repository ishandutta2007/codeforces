#include <bits/stdc++.h>
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
using namespace std;
const int maxn = 500, INF = 1e9;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF));
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++) {
        string s; cin >> s;
        vector<int> vec;
        vec.reserve(m);
        for(int j = 0; j < m; j++) if(s[j] == '1') vec.push_back(j);
        if(vec.empty()) { dp[i] = dp[i - 1]; continue; }
        vector<int> opt(sz(vec) + 1, INF);
        opt[0] = 0;
        for(int j = 0; j < sz(vec); j++) for(int jj = j; jj < sz(vec); jj++)
            opt[jj - j + 1] = min(opt[jj - j + 1], vec[jj] - vec[j] + 1);
        for(int x = 0; x <= k; x++) // 
            for(int y = 0; y <= min({k, x, sz(vec)}); y++) //    
                dp[i][x] = min(dp[i][x], dp[i - 1][x - y] + opt[sz(vec) - y]);
    }
    int ans = INF;
    for(int i = 0; i <= k; i++) ans = min(ans, dp[n][i]);
    cout << ans;
}