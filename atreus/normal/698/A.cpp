#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int maxn = 1e2 + 1000;
int a[maxn];
int dp[maxn][maxn];
int b[maxn];

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (a[0] == 0){
        dp[0][0] = 1;
        dp[0][1] = 1000;
        dp[0][2] = 1000;
    }
    if (a[0] == 1 || a[0] == 2 || a[0] == 3){
        dp[0][0] = 1000;
        dp[0][3 - a[0]] = 1000;
    }
    for (int i = 1; i < n; i++){
        int k = 1000000000;
        for (int j = 0; j < 3; j++)
            k = min(dp[i - 1][j], k);
        if (a[i] == 0){
            dp[i][0] = k + 1;
            dp[i][1] = k + 1;
            dp[i][2] = k + 1;
        }
        if (a[i] == 1){
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
            dp[i][0] = dp[i - 1][1] + 1;
            dp[i][2] = 1000000000;
        }
        if (a[i] == 2){
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
            dp[i][0] = dp[i - 1][2] + 1;
            dp[i][1] = 1000000000;
        }
        if (a[i] == 3){
            dp[i][0] = 1000000000;
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
        }
    }
    cout << min(min(dp[n - 1][1], dp[n - 1][2]), dp[n - 1][0]) << endl;
}