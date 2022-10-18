#include<bits/stdc++.h>

using namespace std;

#define int long long
int const maxn = 2e5 + 5;
int a[maxn], dp[maxn];
map < int, int > sum;

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        dp[i] = sum[i - a[i]] + a[i];
        sum[i - a[i]] = dp[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) ans = max(ans, dp[i]);
    cout << ans;
    return 0;
}