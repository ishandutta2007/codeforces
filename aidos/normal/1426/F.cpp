#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = (int)200200;
const int mod = (int)1e9 + 7;
const ll inf = (1ll<<50);
ll n, k;
string s;
ll dp[maxn][5][5];
ll p[maxn];

void solve() {
    cin >> n;
    cin >> s;
    int cnt = 0;
    for(char c: s) {
        if(c == '?') cnt++;
    }
    p[0] = 1;
    for(int i = 1; i <= cnt; i++) p[i] = p[i-1] * 3ll % mod;
    ll ans = 0;
    string t = "#abc";
    dp[0][0][0] = 1;
    for(int i = 1; i <= n; i++) {

        for(int k = 0; k <= 3; k++) {
            for(int j = 0; j <= 3; j++) {
                dp[i][k][j] = dp[i-1][k][j];
            }
        }
        for(int k = 0; k <= 3; k++) {
            for (int j = 1; j <= 3; j++) {
                if (s[i-1] == '?') dp[i][k+1][j] = (dp[i][k+1][j] + dp[i-1][k][j-1]) % mod;
                else if(s[i-1] == t[j]) dp[i][k][j] = (dp[i][k][j] + dp[i-1][k][j-1]) % mod;
            }
        }
    }
    for(int k = 0; k <= 3 && k <= cnt; k++) {
        ans = (ans + dp[n][k][3] * p[cnt-k]) % mod;
    }
    cout << ans << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}