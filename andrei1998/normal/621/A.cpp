#include <bits/stdc++.h>

#define lint long long int
using namespace std;

const lint inf = 1e17;

int n;
lint dp[2][100005];

inline void update(lint &dp, lint val) {
    if (val > dp)
        dp = val;
}

int main()
{
    ios_base :: sync_with_stdio(false);

    cin >> n;

    dp[1][0] = -inf;

    int val;
    for (int i = 1; i <= n; ++ i) {
        cin >> val;

        dp[0][i] = dp[0][i - 1];
        dp[1][i] = dp[1][i - 1];

        update(dp[val % 2][i], dp[0][i - 1] + val);
        update(dp[(val + 1) % 2][i], dp[1][i - 1] + val);

        //Singur
        update(dp[val % 2][i], val);
    }

    cout << dp[0][n] << '\n';
    return 0;
}