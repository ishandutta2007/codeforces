#include <bits/stdc++.h>

using namespace std;

const int NMAX = 100000 + 5;

int dp[2 * NMAX];

int main() {
    ios_base :: sync_with_stdio(false);
    string str;
    cin >> str;
    const int N = str.size();
    str = str + str;

    int ans = 1;
    for (int i = 0; i < 2 * N; ++ i) {
        dp[i] = 1;
        if (i > 0 && str[i] != str[i - 1])
            dp[i] = 1 + dp[i - 1];
        ans = max(ans, dp[i]);
    }

    if (ans > N)
        ans = N;
    cout << ans << endl;
    return 0;
}