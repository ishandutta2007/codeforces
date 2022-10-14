#include<bits/stdc++.h>

using namespace std;

#define pb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define ll long long
#define pii pair<int, int>

const int INF = 2e9 + 1;

int cnt_bits(int x) {
    int ans = 0;
    while (x > 0) {
        ans += x % 2;
        x /= 2;
    }
    return ans;
}

bool good(int i, int j, int b) {
    for (int k = 0; k + 1 < b; k++) {
        int res = 0;
        if ((1 << k) & i) res++;
        if ((1 << (k + 1)) & i) res++;
        if ((1 << k) & j) res++;
        if ((1 << (k + 1)) & j) res++;
        if (res % 2 == 0) return 0;
    }
    return 1;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    if (n == 1) {
        cout << 0;
        return 0;
    }
    vector<string> a(n);
    for (auto &c : a) cin >> c;
    if (n >= 4 && m >= 4) {
        cout << -1;
        return 0;
    }
    int x = (1 << n);
    vector<vector<int>> dp(m, vector<int>(x, INF));
    vector<vector<int>> go(x, vector<int>(x));
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            go[i][j] = good(i, j, n);
        }
    }
    int base = 0;
    for (int i = 0; i < n; i++) {
        if (a[i][0] == '1') base |= (1 << i);
    }
    for (int mask = 0; mask < x; mask++) {
        dp[0][mask] = cnt_bits(base ^ mask);
    }
    int ans = INF;
    for (int j = 1; j < m; j++) {
        int base = 0;
        for (int i = 0; i < n; i++) {
            if (a[i][j] == '1') base |= (1 << i);
        }
        for (int mask1 = 0; mask1 < x; mask1++) {
            for (int mask2 = 0; mask2 < x; mask2++) {
                if (go[mask1][mask2]) dp[j][mask2] = min(dp[j][mask2], dp[j - 1][mask1] + cnt_bits(mask2 ^ base));
            }
        }
    }
    for (auto &c : dp.back()) ans = min(ans, c);
    cout << (ans == INF ? -1 : ans);
    return 0;
}