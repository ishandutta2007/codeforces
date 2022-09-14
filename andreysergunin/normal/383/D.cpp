#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <ctime>

using namespace std;

const int MAXN = 10000;
const int P = 1e9 + 7;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<long long> dp[MAXN + 1];
    for (int i = 0; i <= MAXN; i++)
        dp[i].resize(n + 1);
    for (int i = 1; i <= n; i++) {
        dp[0][i] = (2 * dp[a[i - 1]][i - 1]) % P;
        for (int j = 1; j <= MAXN; j++) {
            dp[j][i] = 0;
            if (abs(j - a[i - 1]) <= MAXN)
                dp[j][i] = (dp[j][i] + dp[abs(j - a[i - 1])][i - 1]) % P;
            if (abs(j + a[i - 1]) <= MAXN)
                dp[j][i] = (dp[j][i] + dp[abs(j + a[i - 1])][i - 1]) % P;
            
        }
        dp[a[i - 1]][i] = (dp[a[i - 1]][i] + 1) % P;
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++)
        ans = (ans + dp[0][i]) % P;
    cout << ans << endl;
    return 0;
}