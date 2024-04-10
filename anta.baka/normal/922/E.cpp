#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    int n, w, b, x; cin >> n >> w >> b >> x;
    vector<int> c(n), p(n), cost(n);
    for(int i = 0; i < n; i++) cin >> c[i], p[i] = (i ? p[i - 1] : 0) + c[i];
    for(int i = 0; i < n; i++) cin >> cost[i];
    vector<vector<ll>> dp(n + 1, vector<ll>(p[n - 1] + 1, -1));
    dp[0][0] = w;
    for(int i = 0; i < n; i++)
        for(int j = 0; j <= p[i]; j++) { //   i + 1   j 
            for(int k = 0; k <= min(j, c[i]); k++) { //     k 
                if(dp[i][j - k] == -1) continue;
                ll hi = w + ll(b) * (j - k);
                ll en = min(hi, dp[i][j - k] + x);
                if(ll(cost[i]) * k > en) continue;
                en -= ll(cost[i]) * k;
                dp[i + 1][j] = max(dp[i + 1][j], en);
            }
        }
    int ans = 0;
    for(int j = 0; j <= p[n - 1]; j++) if(dp[n][j] != -1) ans = j;
    cout << ans;
}