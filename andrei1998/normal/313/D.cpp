#include <iostream>
#include <algorithm>

#define lint long long int
#define inf (1ll << 60)
using namespace std;

lint best[305][305];
lint dp[305][305];

int main()
{
    ios_base :: sync_with_stdio(false);
    int n, m, K;
    cin >> n >> m >> K;

    int j;
    for (int i = 0; i <= n + 1; i++)
        for (j = 0; j <= n + 1; j++)
            best[i][j] = inf;
    int l, r;
    lint c;
    while (m--) {
        cin >> l >> r >> c;

        best[l][r] = min(best[l][r], c);
    }

    for (int i = 1; i <= n; i++) {
        //cout << "i = =" << i << endl;
        for (j = n - 1; j >= i; j--) {
            best[i][j] = min(best[i][j], best[i][j + 1]);
        //    cout << "    j = " << j << "     = " << best[i][j] << '\n';
        }
        //cout << endl;
    }

    for (j = 1; j <= K; j++)
        dp[0][j] = inf;

    int k;
    for (int i = 1; i <= n; i++)
        for (j = 1; j <= K; j++) {
            dp[i][j] = dp[i - 1][j];

            for (k = 1; k <= i; k++)
                if (dp[k - 1][max(0, j - (i - k + 1))] + best[k][i] < dp[i][j])
                    dp[i][j] = dp[k - 1][max(0, j - (i - k + 1))] + best[k][i];
        }

    if (dp[n][K] < inf)
        cout << dp[n][K] << '\n';
    else
        cout << "-1\n";
    return 0;
}