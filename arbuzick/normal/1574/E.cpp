#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;

int binpow(int n, int k) {
    if (k == 0) {
        return 1;
    }
    if (k % 2) {
        return binpow(n, k - 1) * 1LL * n % mod;
    }
    int m = binpow(n, k / 2);
    return m * 1LL * m % mod;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<array<int, 2>> cnt_r(n, {0, 0}), cnt_c(m, {0, 0});
    array<int, 2> chess = {0, 0};
    array<int, 3> cnt_r_all = {0, 0, n}, cnt_c_all = {0, 0, m};
    map<pair<int, int>, int> color;
    while (k--) {
        int x, y, tp;
        cin >> x >> y >> tp;
        x--, y--;
        if (color.count({x, y}) == 1) {
            cnt_r_all[(cnt_r[x][0] == 0) + (cnt_r[x][1] == 0)]--;
            cnt_c_all[(cnt_c[y][0] == 0) + (cnt_c[y][1] == 0)]--;
            chess[1 ^ ((x + y) % 2) ^ color[{x, y}]]--;
            cnt_r[x][1 ^ (y % 2) ^ color[{x, y}]]--;
            cnt_c[y][1 ^ (x % 2) ^ color[{x, y}]]--;
            color.erase({x, y});
            cnt_r_all[(cnt_r[x][0] == 0) + (cnt_r[x][1] == 0)]++;
            cnt_c_all[(cnt_c[y][0] == 0) + (cnt_c[y][1] == 0)]++;
        }
        cnt_r_all[(cnt_r[x][0] == 0) + (cnt_r[x][1] == 0)]--;
        cnt_c_all[(cnt_c[y][0] == 0) + (cnt_c[y][1] == 0)]--;
        if (tp != -1) {
            color[{x, y}] = tp;
            chess[1 ^ ((x + y) % 2) ^ color[{x, y}]]++;
            cnt_r[x][1 ^ (y % 2) ^ color[{x, y}]]++;
            cnt_c[y][1 ^ (x % 2) ^ color[{x, y}]]++;
        }
        cnt_r_all[(cnt_r[x][0] == 0) + (cnt_r[x][1] == 0)]++;
        cnt_c_all[(cnt_c[y][0] == 0) + (cnt_c[y][1] == 0)]++;
        int ans = binpow(0, cnt_r_all[0]) * 1LL * binpow(2, cnt_r_all[2]) % mod + binpow(0, cnt_c_all[0]) * 1LL * binpow(2, cnt_c_all[2]) % mod;
        if (ans >= mod) {
            ans -= mod;
        }
        ans = (ans + mod - (chess[0] == 0) - (chess[1] == 0));
        if (ans >= mod) {
            ans -= mod;
        }
        cout << ans << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}