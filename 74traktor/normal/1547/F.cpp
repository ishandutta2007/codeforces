#include<bits/stdc++.h>

using namespace std;

int const maxn = 2e5 + 5, logg = 18;
int a[maxn];
int dp[logg][maxn];

int get(int l, int r) {
    int ans = 0;
    for (int i = logg - 1; i >= 0; --i) {
        if (l + (1 << i) - 1 <= r) {
            ans = __gcd(ans, dp[i][l]);
            l += (1 << i);
        }
    }
    return ans;
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= n; ++i) dp[0][i] = a[i];
        for (int j = 1; j < logg; ++j) {
            for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
                dp[j][i] = __gcd(dp[j - 1][i], dp[j - 1][i + (1 << (j - 1))]);
            }
        }
        int lef = -1, righ = n - 1;
        while (righ - lef > 1) {
            int mid = (righ + lef) / 2;
            int f = -1, flag = 1;
            for (int i = 1; i <= n; ++i) {
                int val = get(i, min(i + mid, n));
                if (i + mid > n) val = __gcd(val, get(1, i + mid - n));
                if (f == -1) f = val;
                else if (f != val) flag = 0;
            }
            if (flag) righ = mid;
            else lef = mid;
        }
        cout << righ << '\n';
    }
    return 0;
}