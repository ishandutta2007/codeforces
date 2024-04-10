#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 105;
const int MOD = 1000000007;

int n;
int suff[N];
int dp[N][N * N];
int pref[N][N * N];
int val[N], c[N], b[N], x[N];
int cnt = 0;
// int x[N];

// void backtrack(int k) {
//     for (int i = 0; i <= c[k]; i++) {
//         x[k] = i;
//         if (k == n) {
//             int sum = 0;
//             bool ok = 1;
//             for (int i = 1; i <= n; i++) {
//                 sum += x[i];
//                 if (sum < val[i]) ok = 0;
//             }
//             cnt += ok;
//         } else backtrack(k + 1);
//     }
// }

int lazy[N][N * N];

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i < n; i++) cin >> b[i]; 
    int q, x;
    cin >> q;
    suff[n + 1] = 1;
    for (int i = n; i >= 1; i--) suff[i] = suff[i + 1] * (c[i] + 1) % MOD;
    dp[0][0] = 1;
    for (int j = 0; j < N*N; j++) pref[0][j] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < N * N; j++) {
            int l = max<int>(0, j - c[i]);
            int r = j;
            dp[i][j] = pref[i - 1][r] - (l > 0 ? pref[i - 1][l - 1] : 0);
            dp[i][j] = (dp[i][j] + MOD) % MOD;
        }
        pref[i][0] = dp[i][0];
        for (int j = 1; j < N * N; j++) pref[i][j] = (dp[i][j] + pref[i][j - 1]) % MOD;
    }
    vector<pair<int, int>> qq;
    vector<int> id(n + 1, 0);
    for (int i = 1; i <= q; i++) {
        int x;
        cin >> x;
        qq.push_back({x, i});
    }
    sort(qq.begin(), qq.end());
    vector<int> ress(q + 1);
    int res = 0;
    int prevx = -1e9;
    int prevAns = 0;
    for (auto que : qq) {
        int x = que.first;
        if (x == prevx) {
            ress[que.second] = prevAns;
            continue;
        }
        int cur = x;
        for (int i = 1; i <= n; i++) {
            val[i] = val[i - 1] + cur;
            cur += b[i];
        }
        if (val[n] > 100 * n) {
            prevx = x;
            prevAns = 0;
            ress[que.second] = 0;
            continue;
        }
        if (val[n] < 0) {
            prevx = x;
            prevAns = suff[1];
            ress[que.second] = suff[1];
            continue;
        }
        dp[0][0] = 1;
        for (int j = 0; j < N*N; j++) pref[0][j] = 1;
        int res = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < N * N; j++) {
                int l = max<int>(0, j - c[i]);
                int r = j;
                dp[i][j] = pref[i - 1][r] - (l > 0 ? pref[i - 1][l - 1] : 0);
                dp[i][j] = (dp[i][j] + MOD) % MOD;
            }
            // for (int j = 0; j < 10; j++) cout << dp[i][j] << ' ';
            // cout << endl;
            for (int j = 0; j < min(N * N, val[i]); j++) {
                res = (res + dp[i][j] * suff[i + 1]) % MOD;
                dp[i][j] = 0;
            }
            pref[i][0] = dp[i][0];
            for (int j = 1; j < N * N; j++) pref[i][j] = (dp[i][j] + pref[i][j - 1]) % MOD;
        }
        ress[que.second] = (suff[1] - res + MOD) % MOD;
        prevx = x;
        prevAns = ress[que.second];
    }

    for (int i = 1; i <= q; i++) {
        cout << ress[i] << '\n';
    }

    return 0;
}