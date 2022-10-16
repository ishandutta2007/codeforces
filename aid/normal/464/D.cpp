#include <iostream>

using namespace std;

const int MAXN = 100 * 1000 + 5, MAXLVL = 1000 + 5;
double dp[2][MAXLVL];

int main() {
    ios_base::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(20);
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        for(int j = 0; j < MAXLVL; j++)
            dp[i & 1][j] = ((k - 1) * dp[(i - 1) & 1][j] + (double)1 / (j + 1) *
            (j * (j + 3) / 2 + j * dp[(i - 1) & 1][j] + dp[(i - 1) & 1][j + 1])) / k;
    cout << k * dp[n & 1][1] << '\n';
}