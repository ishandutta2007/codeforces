#include <iostream>

using namespace std;

const int NMAX = 100 + 5;

int n;
int sz[NMAX];
int v[NMAX][NMAX];

int best[NMAX][NMAX];
int dp[NMAX][NMAX * NMAX];

int main()
{
    int m = 0;
    cin >> n >> m;

    int sum_sz = 0;
    for (int i = 1; i <= n; ++ i) {
        cin >> sz[i];
        for (int j = 1; j <= sz[i]; ++ j)
            cin >> v[i][j];

        for (int j = 1; j <= sz[i]; ++ j)
            v[i][j] += v[i][j - 1];
        for (int j = 1; j <= sz[i]; ++ j)
            for (int k = j - 1; k <= sz[i]; ++ k)
                best[i][sz[i] - (k - j + 1)] = max(best[i][sz[i] - (k - j + 1)], v[i][sz[i]] - (v[i][k] - v[i][j - 1]));

        for (int j = 0; j <= sum_sz; ++ j)
            for (int k = 0; k <= sz[i]; ++ k) {
                int val = dp[i - 1][j] + best[i][k];
                if (val > dp[i][j + k])
                    dp[i][j + k] = val;
            }

        sum_sz += sz[i];
    }

    cout << dp[n][m] << '\n';
    return 0;
}