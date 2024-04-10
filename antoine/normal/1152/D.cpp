#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int mod = (int) 1e9 + 7;

ll dp[2009][2009];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int N;
    cin >> N;

    N <<= 1;

    dp[0][0] = 1;
    for (int n = 1; n <= N; ++n) {
        for (int d = 0; d <= N; ++d) {
            ll &res = dp[n][d];
            res = dp[n - 1][d + 1] + (d ? dp[n - 1][d - 1] : 0);
            res %= mod;
        }
    }

    ll ans = 0;

    for (int n = N - 1; n >= 0; n -= 2) {
        for (int d = 0; d <= N - n; ++d)
            ans += dp[n][d];
        ans %= mod;
    }

    cout << ans;
    return 0;
}