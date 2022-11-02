#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxn = 2e5 + 123;
const int mod = 1e9 + 7;
int n, k;
ll t;
ll a[maxn];
ll b[maxn];
int c[maxn];
int dp[maxn];
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
        while(b[i] % 2 == 0) {
            b[i] /= 2;
            c[i]++;
        }
    }
    int ans=n;
    for(int i = 1; i <= n; i++) {
        dp[i] = i - 1;
        for(int j = 1; j < i; j++) {
            if(b[j] % b[i] == 0 && (c[j] + (i - j) == c[i] || c[i] <= i - j - 1)) {
                dp[i] = min(dp[i], dp[j] + i - j - 1);
            }
        }
        ans = min(ans, dp[i] + n - i);
    }
    cout << ans << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }

    return 0;
}