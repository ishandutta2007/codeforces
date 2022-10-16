#include <iostream>
#include <algorithm>

using namespace std;

const int NMAX = 205;
const int SMAX = 1005;

int n, s;
int v[NMAX];

const int mod = 1000000007;

void add_val(int &dp, int val) {
    dp += val;
    if (dp >= mod)
        dp -= mod;
}

int dp[NMAX][NMAX][SMAX]; //dp[i][j][k] = Ai rezolvat cu primii i, j sunt deschisi si suma totala e k

int main()
{
    cin >> n >> s;
    for (int i = 1; i <= n; ++ i)
        cin >> v[i];
    sort(v + 1, v + n + 1);

    dp[0][0][0] = 1;
    for (int i = 0; i < n; ++ i)
        for (int j = 0; j <= i; ++ j)
            for (int k = 0; k <= s; ++ k)
                if (k + j * (v[i + 1] - v[i]) <= s) {
                    //Nu facem nimic
                    add_val(dp[i + 1][j][k + j * (v[i + 1] - v[i])], (1ll * dp[i][j][k] * j) % mod);

                    //Deschidem si inchidem
                    add_val(dp[i + 1][j][k + j * (v[i + 1] - v[i])], dp[i][j][k]);

                    //Deschidem
                    add_val(dp[i + 1][j + 1][k + j * (v[i + 1] - v[i])], dp[i][j][k]);

                    //Inchidem
                    if (j)
                        add_val(dp[i + 1][j - 1][k + j * (v[i + 1] - v[i])], (1ll * dp[i][j][k] * j) % mod);
                }

    int ans = 0;
    for (int i = 0; i <= s; ++ i)
        add_val(ans, dp[n][0][i]);

    cout << ans << '\n';
    return 0;
}