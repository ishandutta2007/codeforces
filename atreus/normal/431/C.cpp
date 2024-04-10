#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int maxn = 1e2 + 1000;
const int mod = 1e9 + 7;
int n, k, d;
long long dp[maxn][maxn];

long long f(int n, int k, int d){
    if (n == d)
        return 1;
    if (n < d && d == 1)
        return 1;
    if (n < d && d != 1)
        return 0;
    if (dp[n][d] != 0)
        return dp[n][d];
    for (int i = 1; i <= min(k, n); i++){
        if (i < d)
            dp[n][d] += f(n - i, k, d);
        else
            dp[n][d] += f(n - i, k, 1);
        dp[n][d] %= mod;
    }
    return dp[n][d];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k >> d;
    cout << f(n, k, d);
}