#include <iostream>
#include <string>

using namespace std;

const int MOD = 1000000000 + 7;

inline void add(int &where, int val) {
    where += val;
    if (where >= MOD)
        where -= MOD;
}

const int NMAX = 2000 + 5;

string str;
int v[NMAX];
int dp[NMAX][NMAX];

int main()
{
    int N, K;
    cin >> N >> K;

    cin >> str;
    for (int i = 1; i <= N; ++ i)
        v[i] = str[i - 1] - 'a';

    // i = 0
    dp[0][N + 1] = 1;
    for (int j = N; j; -- j)
        dp[0][j] = (1LL * dp[0][j + 1] * (v[j] + 1LL)) % MOD;

    for (int i = 1; i <= K; ++ i) {
        int sum = 0;
        for (int j = N; j; -- j) {
            sum = (sum + 1LL * v[j] * dp[i][j + 1]) % MOD;
            dp[i][j] = sum;

            int l;
            for (l = j; l <= N; ++ l) {
                int quant = (l - j + 1) * (N - l + 1);
                if (quant <= i)
                    dp[i][j] = (dp[i][j] + (25LL - v[l]) * dp[i - quant][l + 1]) % MOD;
                else
                    break;
            }

            if (l < N) {
                for (int r = N; r > l; -- r) {
                    int quant = (r - j + 1) * (N - r + 1);
                    if (quant <= i)
                        dp[i][j] = (dp[i][j] + (25LL - v[r]) * dp[i - quant][r + 1]) % MOD;
                    else
                        break;
                }
            }
        }
    }

    cout << dp[K][1] << '\n';
    return 0;
}