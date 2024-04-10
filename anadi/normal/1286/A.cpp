#include <bits/stdc++.h>

using namespace std;

const int N = 107;
const int MOD = 1'000'000'007;

int n;
int dp[N][N][N][2];

void remin(int &a, int b)
{
    a = min(a, b);
}

int main()
{
    scanf("%d", &n);

    vector <bool> was(n + 1);
    vector <int> in(n + 2);

    for (int i = 1; i <= n; ++i) {
        int &v = in[i];
        scanf("%d", &v);
        if (v) was[v] = true;
    }

    if (n == 1) {
        puts("0");
        exit(0);
    }

    vector <int> type(2);
    for (int i = 1; i <= n; ++i) {
        if (was[i]) continue;
        type[i & 1]++;
    }

    if (type[0] + type[1] == n) {
        puts("1");
        exit(0);
    }

    for (int idx = 0; idx <= n; ++idx) {
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= n; ++j) {
                dp[idx][i][j][0] = dp[idx][i][j][1] = N;
            }
        }
    }

    dp[0][type[0]][type[1]][0] = dp[0][type[0]][type[1]][1] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= n; ++j) {
            for (int k = 0; k <= n; ++k) {
                if (in[i + 1]) {
                    int t = in[i + 1] & 1;
                    remin(dp[i + 1][j][k][t], dp[i][j][k][t]);
                    remin(dp[i + 1][j][k][t], dp[i][j][k][t ^ 1] + 1);
                } else {
                    if (j) {
                        remin(dp[i + 1][j - 1][k][0], dp[i][j][k][0]);
                        remin(dp[i + 1][j - 1][k][0], dp[i][j][k][1] + 1);
                    }

                    if (k) {
                        remin(dp[i + 1][j][k - 1][1], dp[i][j][k][0] + 1);
                        remin(dp[i + 1][j][k - 1][1], dp[i][j][k][1]);
                    }
                }
            }
        }
    }

    printf("%d\n", min(dp[n][0][0][0], dp[n][0][0][1]));
    return 0;
}