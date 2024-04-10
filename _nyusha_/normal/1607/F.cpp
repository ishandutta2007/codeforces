#include<bits/stdc++.h>

using namespace std;

int const maxn = 2005;
char a[maxn][maxn];
int dp[maxn][maxn];
pair < short int, short int > p[maxn][maxn];
int n, m;

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i <= n + 1; ++i) {
        for (int j = 0; j <= m + 1; ++j) dp[i][j] = 0, p[i][j] = {0, 0};
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (!dp[i][j]) {
                int now_i = i, now_j = j, flag = 0, cp_i, cp_j;
                while (dp[now_i][now_j] == 0 && 1 <= now_i && now_i <= n && 1 <= now_j && now_j <= m) {
                    dp[now_i][now_j] = -1;
                    cp_i = now_i, cp_j = now_j;
                    if (a[now_i][now_j] == 'L') now_j--;
                    else if (a[now_i][now_j] == 'R') now_j++;
                    else if (a[now_i][now_j] == 'U') now_i--;
                    else now_i++;
                    if (dp[now_i][now_j] == -1) {
                        flag = 1;
                    } else p[now_i][now_j] = {cp_i, cp_j};
                }
                if (flag) {
                    int sz = 1;
                    int v_i = cp_i, v_j = cp_j;
                    while (v_i != now_i || v_j != now_j) {
                        sz++;
                        int x = v_i, y = v_j;
                        v_i = p[x][y].first, v_j = p[x][y].second;
                    }
                    v_i = cp_i, v_j = cp_j;
                    while (v_i != now_i || v_j != now_j) {
                        dp[v_i][v_j] = sz;
                        int x = v_i, y = v_j;
                        v_i = p[x][y].first, v_j = p[x][y].second;
                    }
                    dp[v_i][v_j] = sz;
                    cp_i = v_i, cp_j = v_j;
                } else dp[cp_i][cp_j] = dp[now_i][now_j] + 1;
                while (p[cp_i][cp_j].first != 0) {
                    int x = cp_i, y = cp_j;
                    cp_i = p[x][y].first, cp_j = p[x][y].second;
                    dp[cp_i][cp_j] = dp[x][y] + 1;
                }
            }
        }
    }
    int imax = 0, flag = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) imax = max(imax, dp[i][j]);
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (dp[i][j] == imax && !flag) {
                flag = 1;
                cout << i << " " << j << " " << dp[i][j] << '\n';
            }
        }
    }
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}