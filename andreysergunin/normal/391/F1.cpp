#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <map>

using namespace std;

const int MAXN = 3030;

int main() {
    int n, k;
    cin >> n >> k;
    vector<long long> p(n), m(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];
    
    long long dp[MAXN][MAXN];
    
    for (int i = 1; i < n; i++)
        m[i] = -1e18;
    
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int j = 1; j <= k; j++)
        dp[0][j] = -1e18;
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= k; j++) {
            dp[i][j] = max(dp[i - 1][j], m[j] + p[i - 1]);
            if (j > 0)
                m[j] = max(m[j], dp[i - 1][j - 1] - p[i - 1]);
        }
    long long ans = 0;
    for (int j = 1; j <= k; j++)
        ans = max(ans, dp[n][j]);
    cout << ans << endl;
}