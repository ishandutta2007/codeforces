#include <bits/stdc++.h>
using namespace std;
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    vector<vector<int>> dp(26, vector<int>(26, 0));
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        int l = sz(s);
        int u = s[0] - 'a', v = s[l - 1] - 'a';
        for(int y = 0; y < 26; y++)
            if(y == u || dp[y][u] != 0)
            dp[y][v] = max(dp[y][v], dp[y][u] + l);
    }
    int ans = 0;
    for(int i = 0; i < 26; i++) ans = max(ans, dp[i][i]);
    cout << ans;
}