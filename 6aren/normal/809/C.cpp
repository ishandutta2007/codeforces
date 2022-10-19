#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

const int MOD = 1000000007;

long long dp[32][2][2][2], cnt[32][2][2][2];
bool check[32][2][2][2];

void go(int pos, int flagX, int flagY, int flagK, int x, int y, int k) {
    int new_pos = pos - 1;
    bool _x = bit(x, new_pos);
    bool _y = bit(y, new_pos);
    bool _k = bit(k, new_pos);
    bool new_flagX, new_flagY, new_flagK;
    for (int digitX = 0; digitX < 2; digitX++) {
        if (flagX && digitX > _x) continue;
        for (int digitY = 0; digitY < 2; digitY++) {
            // cout << new_pos << ' ' << digitX << ' ' << digitY << endl;
            if (flagY && digitY > _y) continue;
            if (flagK && (digitX ^ digitY) > _k) continue;
            new_flagX = new_flagY = new_flagK = 0;
            if (flagX && digitX == _x) new_flagX = 1;
            if (flagY && digitY == _y) new_flagY = 1;
            if (flagK && (digitX ^ digitY) == _k) new_flagK = 1;
            // cout << new_pos << ' ' << new_flagX << ' ' << new_flagY << ' ' << new_flagK << endl;
            check[new_pos][new_flagX][new_flagY][new_flagK] |= check[pos][flagX][flagY][flagK];
            cnt[new_pos][new_flagX][new_flagY][new_flagK] += cnt[pos][flagX][flagY][flagK];
            cnt[new_pos][new_flagX][new_flagY][new_flagK] %= MOD;
            int foo = ((int) (digitX ^ digitY) << new_pos) % MOD;
            dp[new_pos][new_flagX][new_flagY][new_flagK] += dp[pos][flagX][flagY][flagK] + foo * cnt[pos][flagX][flagY][flagK];
            dp[new_pos][new_flagX][new_flagY][new_flagK] %= MOD;
            // cout << cnt[new_pos][new_flagX][new_flagY][new_flagK] << endl;
        }
    }
}

int solve(int x, int y, int k) {
    memset(dp, 0, sizeof(dp));
    memset(cnt, 0, sizeof(cnt));
    memset(check, 0, sizeof(check));
    if (x == 0 || y == 0) return 0;
    x--; y--; k--;
    cnt[31][1][1][1] = 1;
    check[31][1][1][1] = 1;
    for (int i = 31; i > 0; i--) {
        for (int flagX = 0; flagX < 2; flagX++) {
            for (int flagY = 0; flagY < 2; flagY++) {
                for (int flagK = 0; flagK < 2; flagK++) {
                    if (check[i][flagX][flagY][flagK] == 0) continue;
                    // cout << i << ' ' << flagX << ' ' << flagY << ' ' << flagK << endl;
                    go(i, flagX, flagY, flagK, x, y, k);
                }
            }
        }
    }
    long long ans = 0;
    for (int flagX = 0; flagX < 2; flagX++) {
        for (int flagY = 0; flagY < 2; flagY++) {
            for (int flagK = 0; flagK < 2; flagK++) {
                // cout << flagX << ' ' << flagY << ' ' << flagK << ' ' << dp[0][flagX][flagY][flagK] << endl;
                ans += dp[0][flagX][flagY][flagK];
                ans += cnt[0][flagX][flagY][flagK];
                ans %= MOD;
            }
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int x, y, xx, yy, k;
        cin >> x >> y >> xx >> yy >> k;
        long long ans = solve(xx, yy, k) - solve(xx, y - 1, k) - solve(x - 1, yy, k) + solve(x - 1, y - 1, k);
        ans %= MOD;
        if (ans < 0) ans += MOD;
        // cout << solve(xx, yy, k) << ' ' << solve(xx, y - 1, k) << ' ' << solve(x - 1, yy, k) << ' ' << solve(x - 1, y - 1, k) << endl;
        cout << ans << endl;
    }
    // cout << solve(2 ,2, 5) << endl;
    return 0;
}