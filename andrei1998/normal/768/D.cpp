#include <iostream>
#include <cmath>

#define double long double
using namespace std;

const double EPS = 1e-8;

const int P = 8000;
double dp[P + 5][1005];

int main()
{
    int k;
    cin >> k;

    dp[0][0] = 1;
    for (int i = 1; i <= P; ++ i) {
        dp[i][0] = 1;
        for (int orbs = 1; orbs <= k; ++ orbs)
            dp[i][orbs] = 1.0L * orbs / k * dp[i - 1][orbs - 1] + (1.0L * k - orbs) / k * dp[i - 1][orbs];
    }

    int q = 0;
    cin >> q;

    while (q --) {
        int p;
        cin >> p;

        for (int i = 1; i <= P; ++ i)
            if (dp[i][k] >= (p - EPS) / 2000) {
                cout << i << '\n';
                break;
            }
    }
    return 0;
}