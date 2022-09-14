#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <map>

using namespace std;

const int MAXN = 510;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    int a[MAXN];
    int dp[MAXN][MAXN];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dp[i][j] = 10000000;
    for (int i = 0; i < n; i++)
        dp[i][i] = 1;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] == a[i + 1])
            dp[i][i + 1] = 1;
        else
            dp[i][i + 1] = 2;
    }
    for (int l = 2; l < n; l++) {
        for (int i = 0; i < n - l; i++) {
            if (a[i] == a[i + l])
                dp[i][i + l] = dp[i + 1][i + l - 1];
            for (int j = 0; j < l; j++)
                dp[i][i + l] = min(dp[i][i + l], dp[i][i + j] + dp[i + j + 1][i + l]);
        }
    }
    cout << dp[0][n - 1] << endl;
    return 0;
}