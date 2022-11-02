#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err34-c"
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e3 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n, h, l, r;
int dp[maxn][maxn];
void solve() {
    cin >> n >> h >> l >> r;
    for(int i = 0; i < h; i++) {
        dp[0][i] = -inf;
    }
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        for(int j = 0; j < h; j++) dp[i][j] = -inf;
        for(int j = 0; j < h; j++) {
            int mx = dp[i-1][j];
            int s = (j + x) % h;
            dp[i][s] = max(dp[i][s], mx + (s >= l && s <= r));
            s = (j + x - 1) % h;
            dp[i][s] = max(dp[i][s], mx + (s >= l && s <= r));
        }
    }
    int ans = 0;
    for(int i = 0; i < h; i++) ans = max(ans, dp[n][i]);
    cout << ans << "\n";
}

int main() {
    int t = 1;
    //scanf("%d", &t);
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}


#pragma clang diagnostic pop