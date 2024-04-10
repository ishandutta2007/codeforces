#pragma target("sse4")
#pragma optimize("O3")
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
char a[20][20];
int dp[(1 << 14)][14][(1 << 7)];
ll ans[(1 << 14)];
int rev[(1 << 14)];

inline int get(int mask, int x, int y, int pos) {
    return mask + (a[x][y] - '0') * (1 << (pos - 2));
}

inline int get1(int mask1, int mask2, int x, int y, int n) {
    return mask1 + (a[x][y] - '0') * (1 << ((n + 1) / 2 - 1)) + rev[mask2] * (1 << ((n + 1) / 2));
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) cin >> a[i][j];
    }
    for (int i = 0; i < (1 << (n / 2 - 1)); ++i) {
        for (int j = 0; j < n / 2 - 1; ++j) {
            if ((i&(1 << j)) > 0) {
                rev[i] += (1 << (n / 2 - 2 - j));
            }
        }
    }
    for (int mask = 1; mask < (1 << n); ++mask) {
        int cnt = 0;
        for (int j = 0; j < n; ++j) if ((mask&(1 << j)) > 0) cnt++;
        if (cnt > (n + 1) / 2) continue;
        if (cnt == 1) {
            for (int j = 0; j < n; ++j) {
                if ((mask&(1 << j)) > 0) dp[mask][j][0] = 1;
            }
        }
        else {
            for (int j = 0; j < n; ++j) {
                if ((mask&(1 << j)) > 0) {
                    int where = (mask^(1 << j));
                    for (int z = 0; z < n; ++z) {
                        if ((where&(1 << z)) > 0) {
                            for (int lst = 0; lst < (1 << (cnt - 2)); ++lst) {
                                dp[mask][j][get(lst, j, z, cnt)] += dp[where][z][lst];
                            }
                        }
                    }
                }
            }
        }
    }
    int f;
    for (int mask = 0; mask < (1 << n); ++mask) {
        int cnt = 0;
        for (int j = 0; j < n; ++j) if ((mask&(1 << j)) > 0) cnt++;
        if (cnt == (n + 1) / 2) {
            int mask1 = (((1 << n) - 1)^mask);
            for (int lst = 0; lst < n; ++lst) {
                if ((mask&(1 << lst)) == 0) continue;
                for (int msk = 0; msk < (1 << (cnt - 1)); ++msk) {
                    f = dp[mask][lst][msk];
                    if (f == 0) continue;
                    for (int good = 0; good < n; ++good) {
                        if ((mask1&(1 << good)) == 0) continue;
                        for (int go = 0; go < (1 << (n - cnt - 1)); ++go) {
                            ans[get1(msk, go, lst, good, n)] += (ll)(f * dp[mask1][good][go]);
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < (1 << (n - 1)); ++i) cout << ans[i] << " ";
    return 0;
}