#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

const int NMAX = 1000000 + 5;

int N, K;
double dp[2][1005]; //dp[N][T] = The expected number of coins after defeating N monsters, starting at level T

void compute_dp() {
    bool h = true;
    for (int n = 1; n <= N; ++ n, h ^= 1) {
        memset(dp[h], 0, sizeof dp[h]);
        for (int t = min(1000, N - n + 1); t; -- t)
            dp[h][t] = (dp[h ^ 1][t + 1] + t * dp[h ^ 1][t] + t * (t + 3.0) / 2.0) / (K * (t + 1.0)) + ((K - 1.0) * dp[h ^ 1][t]) / K;
    }
}

int main()
{
    cin >> N >> K;

    compute_dp();

    cout << fixed << setprecision(10) << K * dp[N & 1][1] << '\n';
    return 0;
}