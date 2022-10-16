#include <bits/stdc++.h>

using namespace std;

const int NMAX = 2000 + 5;

int N, K;
int P;
int a[NMAX];
int b[NMAX];

int dp[NMAX][NMAX];

int main()
{
    cin >> N >> K >> P;
    for (int i = 1; i <= N; ++ i)
        cin >> a[i];
    for (int i = 1; i <= K; ++ i)
        cin >> b[i];

    sort(a + 1, a + N + 1);
    sort(b + 1, b + K + 1);

    for (int i = 1; i <= N; ++ i)
        for (int j = i; j <= K; ++ j) {
            dp[i][j] = max(dp[i - 1][j - 1], abs(a[i] - b[j]) + abs(b[j] - P));
            if (j > i)
                dp[i][j] = min(dp[i][j], dp[i][j - 1]);
        }

    cout << dp[N][K] << '\n';
    return 0;
}