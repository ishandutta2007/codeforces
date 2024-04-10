#include <iostream>

using namespace std;

const int NMAX = 200000 + 5;

int v[NMAX];
int dp[NMAX];

int main()
{
    ios_base :: sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 1; i <= n; ++ i)
        cin >> v[i];

    for (int i = 1; i <= n; ++ i)
        v[i] += v[i - 1];

    int maxim = v[n];
    for (int i = n; i; -- i) {
        maxim = max(maxim, v[i] - dp[i + 1]);
        dp[i] = maxim;
    }

    cout << dp[2] << '\n';
    return 0;
}