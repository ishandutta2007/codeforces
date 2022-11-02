#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
const double pi = acos(-1);
ll n, k;
int dp[2][202][202*64];
void solve() {
    cin >> n >> k;

    int cur = 0;
    int sum = 0;
    for(int i = 0; i < n; i++){
        ll x;
        cin >> x;
        int d5 = 0, d2 = 0;
        while(x % 5 == 0) {
            x/=5;
            d5++;
        }
        while(x % 2 == 0) {
            x/=2;
            d2++;
        }
        sum += d5;
        int nxt = cur^1;
        for(int j = 0; j <= k; j++) {
            for(int t = 0; t <= sum; t++) {
                dp[nxt][j][t] = -inf;
            }
        }
        for(int j = 0; j <= k; j++) {
            for(int t = 0; t <= sum-d5; t++) {
                dp[nxt][j][t] = max(dp[cur][j][t], dp[nxt][j][t]);
                dp[nxt][j+1][t+d5] = max(dp[cur][j][t] + d2, dp[nxt][j+1][t+d5]);
            }
        }
        cur = nxt;
    }
    int ans = 0;
    for(int i = 0; i <= sum; i++) {
        ans = max(min(dp[cur][k][i], i), ans);
    }
    cout << ans << "\n";
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
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