#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

const int MOD = 998244353;
int dp[5005][15005];
pii arr[5005];
int C[10005][5005], prx[5005], sum[5005];

void add(int &x, int val) {
    x += val;
    if (x >= MOD)
        x -= MOD;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    C[0][0] = 1;
    for (int i = 1; i <= 10000; ++i) {
        C[i][0] = 1;
        for (int j = 1; j <= min(5000, i); ++j) {
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
            if (C[i][j] >= MOD)
                C[i][j] -= MOD;
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int n, ans = 0, tp = 0, sp;
        cin >> n, sp = n / 2;
        for (int i = 1; i <= n; ++i) {
            int x;
            cin >> x;
            if (arr[tp].X == x)
                ++arr[tp].Y;
            else
                arr[++tp] = pii(x, 1);
        }
        n = tp;
        prx[0] = 1, sum[0] = 0;
        for (int i = 1; i <= n; ++i) {
            sum[i] = arr[i].Y + sum[i - 1];
            prx[i] = (ll)prx[i - 1] * C[sum[i]][arr[i].Y] % MOD;
        }
        if (arr[n].Y > 1) {
            cout << "0\n";
            continue;
        }
        fill(dp[n], dp[n] + 3 * sp, 0);
        dp[n][0] = 1;
        for (int i = n - 1; i >= 1; --i) {
            fill(dp[i], dp[i] + 3 * sp, 0);
            for (int j = 0; j <= sp; ++j) {
                dp[i][j] = (ll)dp[i + 1][j + arr[i].Y] * C[j + arr[i].Y][arr[i].Y] % MOD;
                if (j > 0)
                    add(dp[i][j], (ll)dp[i + 1][j + arr[i].Y - 2] * C[j + arr[i].Y - 2][arr[i].Y - 1] % MOD);
            }
            add(ans, (ll)dp[i + 1][sum[i] - 1] * prx[i - 1] % MOD * C[sum[i - 1] + arr[i].Y - 1][arr[i].Y - 1] % MOD);
        }
        cout << ans << "\n";
    }
}