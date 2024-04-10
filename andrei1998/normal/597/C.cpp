#include <iostream>

#define lsb(x) ((x) & (-(x)))
#define lint long long int
using namespace std;

int n;
lint aib[15][100005];

inline void update (lint aib[], int pos, lint val) {
    for (; pos <= n; pos += lsb(pos))
        aib[pos] += val;
}

inline lint query (lint aib[], int pos) {
    lint ans = 0;
    for (; pos; pos -= lsb(pos))
        ans += aib[pos];

    return ans;
}

lint dp[15][100005];

int main()
{
    ios_base :: sync_with_stdio(false);

    int k;
    cin >> n >> k;

    ++ k;

    lint ans = 0;
    int val;

    for (int i = 1; i <= n; ++ i) {
        cin >> val;

        dp[1][i] = val;
        update(aib[1], val, 1);

        for (int j = 2; j <= k; ++ j) {
            dp[j][i] = query(aib[j - 1], val - 1);
            update(aib[j], val, dp[j][i]);
        }

        ans += dp[k][i];
    }

    cout << ans << '\n';
    return 0;
}