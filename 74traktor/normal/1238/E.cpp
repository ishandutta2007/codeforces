#include <bits/stdc++.h>

using namespace std;

int cnt[25][25];
int dp[(1 << 20)];
int inf = 1e9;

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    for (int i = 0; i < n - 1; ++i) {
        cnt[s[i] - 'a'][s[i + 1] - 'a']++;
    }
    for (int i = 1; i < (1 << 20); ++i) dp[i] = inf;
    for (int mask = 1; mask < (1 << m); ++mask) {
        int w = mask;
        int sum = 0;
        for (int i = 0; i < m; ++i) if ((mask&(1 << i)) > 0) sum++;
        while (w != 0) {
            int v = __builtin_ffs(w);
            v--;
            int add = 0;
            for (int i = 0; i < m; ++i) {
                if (i == v) continue;
                if ((mask&(1 << i)) > 0) add += (cnt[i][v] + cnt[v][i]) * sum;
                else add -= (cnt[i][v] + cnt[v][i]) * sum;
            }
            int mask1 = (mask^(1 << v));
            dp[mask] = min(dp[mask], dp[mask1] + add);
            w = (w^(1 << v));
        }
    }
    cout << dp[(1 << m) - 1] << '\n';
    return 0;
}