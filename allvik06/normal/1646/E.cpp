#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <cmath>
#include <cassert>
#include <array>

using namespace std;
#define int long long
const int MAXL = 20;
const int MAXM = 1e6;
bool now[(MAXM + 1) * MAXL];
bool flex[MAXM + 1];

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int n, m, ans = 1;
    cin >> n >> m;
    vector <int> dp(MAXL);
    for (int i = 1; i < MAXL; ++i) {
        dp[i] = dp[i - 1];
        for (int j = 1; j <= m; ++j) {
            if (!now[i * j]) {
                now[i * j] = true;
                ++dp[i];
            }
        }
    }
    for (int i = 2; i <= n; ++i) {
        if (flex[i]) continue;
        int cha = i, cnt = 0;
        while (cha <= n) {
            flex[cha] = true;
            cha *= i;
            ++cnt;
        }
        ans += dp[cnt];
    }
    cout << ans;
}

/*

 */