#include<bits/stdc++.h>

using namespace std;

int dp[105][105];
pair < int, int > where[105][105];
int h[105];
char answ[105][105];

main() {
    int n;
    cin >> n;
    for (int ans = 1; 2 * ans - 1 <= n; ++ans) {
        for (int j = 0; j <= n; ++j) {
            for (int z = 0; z <= n; ++z) dp[j][z] = 0;
        }
        dp[n - 2 * ans + 1][2 * ans - 1] = 1;
        for (int w = n; w >= 1; --w) {
            int flag = 0;
            pair < int, int > cur;
            for (int lst = n; lst >= 1; --lst) {
                if (flag && lst % 2 == 1 && w >= lst) {
                    dp[w - lst][lst] = 1;
                    where[w - lst][lst] = cur;
                }
                if (dp[w][lst]) flag = 1, cur = {w, lst};
            }
        }
        int best = -1;
        for (int lst = 1; lst <= n; lst += 2) {
            if (dp[0][lst]) best = lst;
        }
        if (best != -1) {
            int w = 0, r = best, ptr = 1;
            while (1) {
                h[ptr++] = (r + 1) / 2;
                if (w + r == n) break;
                int nxtw = where[w][r].first;
                int nxtr = where[w][r].second;
                w = nxtw;
                r = nxtr;
            }
            for (int i = 1; i <= ans; ++i) for (int j = 1; j <= ans; ++j) answ[i][j] = '.';
            int now = 0;
            cout << ans << '\n';
            for (int i = 1; i <= ans; ++i) {
                if (h[ans - i + 1] == 0) continue;
                now++;
                for (int t = 0; t < h[ans - i + 1]; ++t) {
                    answ[ans - now + 1][now + t] = 'o';
                    answ[ans - t - now + 1][now] = 'o';
                }
            }
            for (int i = 1; i <= ans; ++i) {
                for (int j = 1; j <= ans; ++j) cout << answ[i][j];
                cout << '\n';
            }
            exit(0);
        }
    }
    cout << -1 << '\n';
}