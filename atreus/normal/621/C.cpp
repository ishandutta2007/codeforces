#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 100;
long double dp[maxn];

int main(){
    ios_base::sync_with_stdio(false);
    int n, p;
    cin >> n >> p;
    for (int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        int k = (l + p - 1) / p;
        int m = r / p;
        if (m < k)
            continue;
        dp[i] = 1.0 * (m - k + 1) / (r - l + 1);
    }
    long double ans = 0;
    for (int i = 0; i < n; i++){
        long double ehtemal = 1.0 * dp[i] * dp[(i + 1) % n] + (1.0 - dp[i]) * dp[(i + 1) % n] + dp[i] * (1.0 - dp[(i + 1) % n]);
        ans += ehtemal * 2000;
    }
    cout << fixed << ans << endl;
}