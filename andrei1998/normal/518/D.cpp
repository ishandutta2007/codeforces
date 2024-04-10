#include <iostream>
#include <iomanip>

using namespace std;

int n_m;
double p;
double dp[2005][2005];
bool done[2005][2005];

double calc (int n, int t) {
    if (!t)
        return n;
    if (n == n_m)
        return n;

    if (done[n][t])
        return dp[n][t];
    done[n][t] = true;

    dp[n][t] = calc(n + 1, t - 1) * p + calc(n, t - 1) * (1 - p);

    return dp[n][t];
}

int main()
{
    int n, t;

    cin >> n >> p >> t;
    n_m = n;

    cout << fixed << setprecision(6) << calc(0, t) << '\n';
    return 0;
}