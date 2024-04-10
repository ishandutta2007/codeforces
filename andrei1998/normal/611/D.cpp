#include <bits/stdc++.h>

using namespace std;

const int mod = 1000000007;

inline void add_val(int &dp, int val) {
    dp += val;
    if (dp >= mod)
        dp -= mod;
}

char sir[5005];

int comp[5005][5005];
int care[5005][5005];

int dp[5005][5005];
int s_part[5005][5005];

int main()
{
    ios_base :: sync_with_stdio(false);

    int n = 0;
    cin >> n;

    cin.get();
    cin.get(sir + 1, 5005);

    int j;
    for (int i = n; i; -- i)
        for (j = i + 1; j <= n; ++ j)
            if (sir[i] == sir[j]) {
                comp[i][j] = 1 + comp[i + 1][j + 1];
                care[i][j] = care[i + 1][j + 1];
            }
            else {
                comp[i][j] = 0;
                if (sir[i] < sir[j])
                    care[i][j] = -1;
                else
                    care[i][j] = 1;
            }

    if (sir[1] == '0') {
        cout << "0\n";
        return 0;
    }

    //De facut dp[1][i]
    for (j = 1; j <= n; ++ j) {
        dp[1][j] = 1;
        s_part[1][j] = 1;
    }

    int cap;
    int aux;
    for (int i = 2; i <= n; ++ i)
        for (j = i; j <= n; ++ j) {
            cap = 2 * i - j - 1;

            if (sir[i] >= '1')
            {
                if (cap >= 1) {
                    if (care[cap][i] == -1 && comp[cap][i] + 1 <= (j - i + 1))
                        dp[i][j] = dp[cap][i - 1];

                    aux = (s_part[i - 1][i - 1] - s_part[cap][i - 1]);
                    if (aux < 0)
                        aux += mod;

                    add_val(dp[i][j], aux);
                }
                else
                    dp[i][j] = s_part[i - 1][i - 1];
            }

            s_part[i][j] = dp[i][j];
            add_val(s_part[i][j], s_part[i - 1][j]);
        }

    int ans = 0;
    for (int i = 1; i <= n; ++ i)
        add_val(ans, dp[i][n]);

    cout << ans << '\n';
    return 0;
}