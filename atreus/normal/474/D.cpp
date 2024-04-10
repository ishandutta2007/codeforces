#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>

using namespace std;

const int maxn = 1e5 + 100, mod = 1e9 + 7;
long long dp[maxn + 100], sum[maxn + 100];

int main(){
    ios_base::sync_with_stdio(false);
    int t, k;
    cin >> t >> k;
    dp[0] = 1;
    sum[0] = 0;
    for (int i = 1; i < k; i++){
        dp[i] = 1;
        sum[i] = 1 + sum[i - 1];
    }
    for (int i = k; i <= 100010; i++){
        dp[i] = (dp[i - k] % mod) + (dp[i - 1] % mod) % mod;
        sum[i] = (sum[i - 1] + dp[i]);
    }
    for (int i = 1; i <= t; i++){
        int a, b;
        cin >> a >> b;
        long long ans = 0;
        ans = (sum[b] - sum[a - 1]) % mod;
        cout << ans << endl;
    }
}