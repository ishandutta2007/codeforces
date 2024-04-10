#include <iostream>

using namespace std;

const int MAXN = 55;
int dp[MAXN][MAXN][2];

int main() {
    ios_base::sync_with_stdio(false);
    int n0, n1, k0, k1;
    cin >> n0 >> n1 >> k0 >> k1;
    dp[0][0][0] = 0;
    dp[0][0][1] = 0;
    for(int i = 1; i <= n1; i++) {
        dp[0][i][0] = 0;
        dp[0][i][1] = 1;
    }
    for(int i = 1; i <= n0; i++) {
        dp[i][0][0] = 1;
        dp[i][0][1] = 0;
        for(int j = 1; j <= n1; j++) {
            for(int k = 1; k <= k0 && k <= i; k++)
                if(!dp[i - k][j][1]) {
                    dp[i][j][0] = 1;
                    break;
                }
            for(int k = 1; k <= k1 && k <= j; k++)
                if(!dp[i][j - k][0]) {
                    dp[i][j][1] = 1;
                    break;
                }
        }
    }
    if(dp[n0][n1][0])
        cout << "First\n";
    else
        cout << "Second\n";
    return 0;
}