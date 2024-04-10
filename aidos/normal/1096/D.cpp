#pragma optimize("", on)
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int) 998244353;
const int inf = (1<<30) - 1;
int n;
string h = "hard";
string s;
int a[maxn];

ll dp[maxn][5];
void solve() {
    cin >> n >> s;
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    for(int j = 0; j <= n; j++) {
        for (int i = 0; i <= h.size(); i++) {
            dp[j][i] = -(1ll << 60);
        }
    }
    dp[0][0] = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < h.size(); j++) {
            if(h[j] == s[i]) {
                dp[i + 1][j] = max(dp[i][j], dp[i + 1][j]);
                dp[i + 1][j + 1] = max(dp[i][j] + a[i], dp[i + 1][j + 1]);
            } else {
                dp[i + 1][j] = max(dp[i][j] + a[i], dp[i + 1][j]);
            }
        }
    }
    ll ans = 0;
    for(int i = 0; i < 4; i++) {
        ans = max(ans, dp[n][i]);
    }
    cout << sum - ans << "\n";
}


int main() {
    ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}