#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
const int maxn = (int) 1e6 + 10;
const int mod = (int) 998244353 ;
int n, k;
int a[maxn];
int dp[1010][1010];
int d[1010][1010];
int sum[1010][1010];

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    
    int mx = 100000 / (k - 1);
    for (int i = 0; i < n; i++) {
        dp[i][0] = 1;
    }
    ll ans = 0;
    for (int dif = mx; dif > 0; dif--) {
        int it = -1;
        for (int i = 0; i < n; i++) {
            while (it < i && a[i] - a[it + 1] >= dif) it++;
            if (it != -1) {
                for (int j = 1; j < k; j++) {
                    dp[i][j] = sum[it][j - 1];
                }
            }
            for (int j = 0; j < k; j++) {
                if (i == 0) sum[i][j] = dp[i][j];
                else sum[i][j] = (sum[i - 1][j] + dp[i][j]) % mod;
            }
            ans = (ans + dp[i][k-1]) % mod;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}