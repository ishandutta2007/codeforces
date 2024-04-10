#include <bits/stdc++.h>

using namespace std;
#define x first
#define y second

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int dp[61][13];
int mod = 1e9 + 7;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifdef karpovich
        freopen("input.txt", "r", stdin);
    #endif

    int t;
    cin >> t;
    while (t--) {
        ll m;
        cin >> m;
        for (int j = 0; j <= 6; j += 2) dp[0][j] = 1;
        for (int i = 1; i <= 60; ++i) {
            int ok = 0;
            if ((m&(1ll << i)) > 0) ok = 1;
            int s = 0, l = 0, r = 0;
            for (int j = 0; j <= 12; j += 2) {
                while (r <= 12 && r / 2 - ok <= j) {
                    s += dp[i - 1][r];
                    r += 2;
                    if (s >= mod) s -= mod;
                }
                while (l / 2 - ok + 7 < j) {
                    s -= dp[i - 1][l];
                    l += 2;
                    if (s < 0) s += mod;
                }
                dp[i][j] = s;
            }
        }
        cout << dp[60][0] << '\n';
    }

    return 0;
}