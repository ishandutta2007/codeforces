#include <iostream>
#include <map>

using namespace std;

const int MAXN = 505, K = 30 * MAXN, MOD = 1000 * 1000 * 1000 + 7;
int dp[MAXN][K];
map<int, int> p;

void factorize(int n) {
    for(int i = 2; i * i <= n; i++)
        while(!(n % i)) {
            p[i]++;
            n /= i;
        }
    if(n > 1)
        p[n]++;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        factorize(a);
    }
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j < K; j++)
            dp[i - 1][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % MOD;
        for(int j = 0; j < K; j++)
                dp[i][j] = dp[i - 1][j];
    }
    int ans = 1;
    for(map<int, int>::iterator it = p.begin(); it != p.end(); it++)
        ans = ((long long)ans * dp[n][it->second]) % MOD;
    cout << ans << '\n';
    return 0;
}