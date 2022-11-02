#include <bits/stdc++.h>
using namespace std;

int n, k, m, dp[1001][100][10][2][2], pw[1001]; //  -  -  ?

int add(int &x, int y) {
    x += y;
    if(x >= m) x -= m;
    return x;
}

int main() {
    cin >> n >> k >> m;
    pw[1] = 1;
    for(int i = 2; i <= n; i++) pw[i] = pw[i - 1] * 10 % k;

    dp[1][0][0][0][0] = 1;
    for(int dig = 1; dig < 10; dig++)
        if(dig % k == 0) dp[1][0][dig][1][1] = 1;
        else dp[1][dig % k][dig][0][1] = 1;

    for(int len = 2; len <= n; len++)
        for(int ost = 0; ost < k; ost++) {
            int prev0 = 0, prev1 = 0;
            for(int dig = 0; dig < 10; dig++) {
                add(prev0, dp[len - 1][ost][dig][0][0]);
                add(prev0, dp[len - 1][ost][dig][0][1]);
                add(prev1, dp[len - 1][ost][dig][1][1]);
            }
            for(int dig = 0; dig < 10; dig++) {
                int ostme = pw[len] * dig % k;
                if((ostme + ost) % k == 0) {
                    add(dp[len][0][dig][1][1], prev0);
                    add(dp[len][0][dig][1][1], prev1);
                    if(dig == 0) {
                        add(dp[len][0][dig][0][0], dp[len - 1][0][dig][0][0]);
                        dp[len][0][dig][1][1] = (dp[len][0][dig][1][1] - dp[len - 1][ost][dig][0][0] + m) % m;
                    }
                } else {
                    add(dp[len][(ostme + ost) % k][dig][0][1], prev0);
                    add(dp[len][(ostme + ost) % k][dig][1][1], prev1);
                }
            }
        }

    int ans = 0;
    for(int ost = 0; ost < k; ost++)
        for(int dig = 1; dig < 10; dig++)
            add(ans, dp[n][ost][dig][1][1]);
    cout << ans;
}