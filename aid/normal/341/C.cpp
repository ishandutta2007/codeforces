#include <iostream>
#include <vector>

using namespace std;

const long long MOD = 1000 * 1000 * 1000 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<char> used(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] != -1)
            used[a[i] - 1] = true;
    }
    int m = 0, k = 0;
    for(int i = 0; i < n; i++)
        if(!used[i]) {
            if(a[i] != -1)
                m++;
            else
                k++;
        }
    vector< vector<long long> > dp(m + k + 1, vector<long long>(k + 1));
    dp[0][0] = 1;
    for(int i = 1; i <= m + k; i++) {
        dp[i][0] = (dp[i - 1][0] * i) % MOD;
        dp[i][1] = (dp[i][0] * i) % MOD;
    }
    for(int i = m + k - 2; i >= m; i--)
        for(int j = 2; j <= m + k - i; j++)
            dp[i][j] = (i * dp[i][j - 1] + (j - 1) * dp[i + 1][j - 2]) % MOD;
    cout << dp[m][k] << '\n';
}