#include <iostream>

using namespace std;

const int MAXN = 105, MAXX = 305;
int a[MAXN * MAXN], dp[MAXN * MAXN], dp1[MAXN * MAXN], maxdp[MAXX], cnt[MAXX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, t;
    cin >> n >> t;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int m = min(n, t) * n;
    for(int i = n; i < m; i++)
        a[i] = a[i % n];
    for(int i = 0; i < n; i++)
        cnt[a[i]]++;
    for(int i = 0; i < m; i++) {
        dp[i] = 1;
        for(int j = 0; j <= a[i]; j++)
            dp[i] = max(dp[i], maxdp[j] + 1);
        maxdp[a[i]] = max(maxdp[a[i]], dp[i]);
    }
    for(int i = 0; i < MAXX; i++)
        maxdp[i] = 0;
    int ans = 0;
    for(int i = m - 1; i >= 0; i--) {
        dp1[i] = 1;
        for(int j = a[i]; j < MAXX; j++)
            dp1[i] = max(dp1[i], maxdp[j] + 1);
        maxdp[a[i]] = max(maxdp[a[i]], dp1[i]);
        ans = max(ans, dp[i] + cnt[a[i]] * (t - min(n, t)) +
                  dp1[i] - 1);
    }
    cout << ans << '\n';
    return 0;
}