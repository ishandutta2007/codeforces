#include <iostream>

using namespace std;

const int NMAX = 100000 + 5;

int N;
int v[NMAX];
int dp[NMAX];

int main()
{
    ios_base :: sync_with_stdio(false);

    cin >> N;
    for (int i = 1; i <= N; ++ i)
        cin >> v[i];

    int p90 = 0;
    int p1440 = 0;

    for (int i = 1; i <= N; ++ i) {
        while (p90 + 1 < i && v[p90 + 1] <= v[i] - 90)
            ++ p90;
        while (p1440 + 1 < i && v[p1440 + 1] <= v[i] - 1440)
            ++ p1440;

        dp[i] = 20 + dp[i - 1];
        dp[i] = min(dp[i], 50 + dp[p90]);
        dp[i] = min(dp[i], 120 + dp[p1440]);

        cout << dp[i] - dp[i - 1] << '\n';
    }

    return 0;
}