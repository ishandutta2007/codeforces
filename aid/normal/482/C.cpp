#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int MAXN = 55, MAXM = 20, POWM = (1 << MAXM), P = 131;
unsigned int hash[POWM][MAXN], a[MAXN];
int lb[POWM];
double dp[POWM];
string s[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(20);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> s[i];
    int m = s[0].length();
    for(int i = 1; i < (1 << m); i++)
        for(int j = 0; j < m; j++)
            if(i & (1 << j)) {
                lb[i] = j;
                break;
            }
    for(int i = 1; i < (1 << m); i++)
        for(int j = 0; j < n; j++)
            hash[i][j] = hash[i & ~(1 << lb[i])][j] * P + s[j][lb[i]];
    for(int i = 0; i < (1 << m); i++) {
        for(int j = 0; j < n; j++)
            a[j] = hash[((1 << m) - 1) & ~i][j];
        sort(a, a + n);
        int cnt = 0;
        for(int j = 0; j < n; j++)
            if((!j || a[j] != a[j - 1]) && (j + 1 >= n || a[j] != a[j + 1]))
                cnt++;
        if(cnt == n)
            continue;
        for(int j = 0; j < m; j++)
            if(i & (1 << j))
                dp[i] += dp[i & ~(1 << j)];
        dp[i] *= ((double)n / (n - cnt)) / __builtin_popcount(i);
        dp[i] += 1;
        dp[i] *= (double)(n - cnt) / n;
    }
    cout << dp[(1 << m) - 1] << '\n';
    return 0;
}