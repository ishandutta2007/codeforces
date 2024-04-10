#include <iostream>

using namespace std;

int v[100005];

int where[100005];
int dp[100005];

int main()
{
    ios_base :: sync_with_stdio(false);

    int n = 0;
    cin >> n;

    for (int i = 1; i <= n; ++ i)
        cin >> v[i];

    int best = 1;

    for (int i = 1; i <= n; ++ i) {
        dp[i] = 1 + dp[where[v[i] - 1]];
        where[v[i]] = i;

        if (dp[i] > best)
            best = dp[i];
    }

    cout << n - best << '\n';
    return 0;
}