#include <iostream>

using namespace std;

const int MAXN = 1005, MOD = 1000 * 1000 * 1000 + 7;
int p[MAXN], dp[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        dp[i] = 2;
        for(int j = p[i]; j < i; j++)
            dp[i] = (dp[i] + dp[j]) % MOD;
        ans = (ans + dp[i]) % MOD;
    }
    cout << ans << '\n';
    return 0;
}