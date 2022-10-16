#include <iostream>

using namespace std;

const int NMAX = 505;

int v[NMAX];
int dp[NMAX][NMAX];

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++ i)
        cin >> v[i];

    for (int i = n; i; -- i)
        for (int j = i; j <= n; ++ j) {
            //Split in 2
            dp[i][j] = NMAX;
            for (int k = i + 1; k <= j; ++ k)
                if (dp[i][k - 1] + dp[k][j] < dp[i][j])
                    dp[i][j] = dp[i][k - 1] + dp[k][j];

            //Daca corespund capetele
            if (v[i] == v[j]) {
                if (dp[i + 1][j - 1] + (j - i <= 1) < dp[i][j])
                    dp[i][j] = dp[i + 1][j - 1] + (j - i <= 1);
            }
        }

    cout << dp[1][n] << '\n';
    return 0;
}