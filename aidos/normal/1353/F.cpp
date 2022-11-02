#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
const int maxn = (int) 1e6 + 10;
const int mod = (int) 1e9 + 7;
int n, m;
ll a[111][111];
ll dp[111][111];
ll calc(ll x) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] < x) {
                dp[i][j] = -1;
            } else {
                if(i == 0 && j == 0) {
                    dp[i][j] = a[i][j] - x;
                }
                else if(i == 0) {
                    if(dp[i][j-1] == -1) {
                        dp[i][j] = -1;
                    } else {
                        dp[i][j] = dp[i][j-1] + a[i][j] - x;
                    }
                } else if(j == 0){
                    if(dp[i-1][j] == -1) {
                        dp[i][j] = -1;
                    } else {
                        dp[i][j] = dp[i-1][j] + a[i][j] - x;
                    }
                } else {
                    dp[i][j] = -1;
                    if(dp[i-1][j] != -1) {
                        dp[i][j] = dp[i-1][j] + a[i][j] - x;
                    }
                    if(dp[i][j-1] != -1) {
                        if(dp[i][j] == -1) {
                            dp[i][j] = dp[i][j-1] + a[i][j] - x;
                        } else {
                            dp[i][j] = min(dp[i][j], dp[i][j-1] + a[i][j] - x);
                        }
                    }
                }
            }
        }
    }
    if(dp[n-1][m-1] != -1) return dp[n-1][m-1];
    return 1e19;
}
void solve() {
    cin >> n >> m;
    vector<ll> v;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
            a[i][j] -= i + j;
            v.emplace_back(a[i][j]);
        }
    }
    ll ans = 1e19;
    for(int i = 0; i < v.size(); i++) {
        if(v[i] > a[0][0] || v[i] > a[n-1][m-1]) continue;
        ans = min(ans, calc(v[i]));
    }
    cout << ans << "\n";
}

int main() {
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}