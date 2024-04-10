#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb emplace_back

int dp[505][505];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> b(n);
    long long A = 0, B = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        A += a[i];
        B += b[i];
    }
    long long ans = A / k + B / k;
    if (A % k == 0 && B % k == 0) {
        cout << ans;
        return 0;
    }
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            if (dp[i][j] == 1) {
                dp[i + 1][j] = 1;
            }
            if (dp[i][j] == 0) {
                continue;
            }
            for (int cnta = 0; cnta <= k; cnta++) {
                int cntb = k - cnta;
                if (cntb > b[i] || cnta > a[i]) continue;
                int tmp = cnta + j;
                if (tmp > k) tmp -= k;
                dp[i + 1][tmp] = 1;
            }
        }
    }
    long long ans1 = ans;
    if (A % k != 0) {
        if (dp[n][A % k] == 1) {
            long long tmp = ans1 + 1;
            if (B % k < (k - A % k) % k) tmp--;
            ans = max(ans, tmp);
        }
    }
    if (B % k != 0) {
        if (dp[n][(k - B % k) % k] == 1) {
            long long tmp = ans1 + 1;
            if (A % k < (k - B % k) % k) tmp--;
            ans = max(ans, tmp);
        }
    }
    cout << ans;
    return 0;
}