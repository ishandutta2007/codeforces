#include <iostream>

using namespace std;

const int MAXN = 100 * 1000 + 5;
int c[MAXN];
long long dp[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        c[a]++;
    }
    dp[1] = c[1];
    for(int i = 2; i < MAXN; i++)
        dp[i] = max(dp[i - 1], (long long)c[i] * i + dp[i - 2]);
    cout << dp[MAXN - 1] << '\n';
    return 0;
}