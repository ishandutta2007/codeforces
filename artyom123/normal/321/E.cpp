#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

vector <vector<int>> dp;
vector <vector<int>> u;
vector <vector<int>> pr;
int n, k;
void chill() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            pr[i + 1][j + 1] = pr[i + 1][j] + pr[i][j + 1] - pr[i][j] + u[i][j];
        }
    }
}

int cnt(int x, int y) {
    if (x > y) {
        swap(x, y);
    }
    return pr[y + 1][y + 1] - pr[x][y + 1] - pr[y + 1][x] + pr[x][x];
}

void solve(int i, int l, int r, int Lans, int Rans) {
    if (l > r) {
        return;
    }
    int m = (l + r) >> 1;
    int best = 0;
    for (int j = Lans; j <= Rans && j < m; ++j) {
        if (dp[i - 1][j] + cnt(j, m - 1) < dp[i][m]) {
            dp[i][m] = dp[i - 1][j] + cnt(j, m - 1);
            best = j;
        }
    }
    if (l == r) {
        return;
    }
    solve(i, l, m - 1, Lans, best);
    solve(i, m + 1, r, best, Rans);
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    dp.resize(k + 1);
    pr.resize(n + 1);
    u.resize(n);
    for (int i = 0; i < n + 1; i++) {
        pr[i].resize(n + 1);
    }
    for (int i = 0; i < k + 1; i++) {
        dp[i].assign(n + 1, INF);
    }
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        u[i].resize(n);
        for (int j = 0; j < n; j++) {
            cin >> u[i][j];
        }
    }
    chill();
    for (int i = 1; i <= k; i++) {
        solve(i, 1, n, 0, n - 1);
    }
    /*for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            for (int l = 0; l < j; l++) {
                dp[i][j] = min(dp[i][j], dp[i - 1][l] + cnt(l, j - 1));
            }
        }
    }
    */
    cout << dp[k][n] / 2;
    return 0;
}