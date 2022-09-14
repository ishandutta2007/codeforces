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

const long long INF = 1e18;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    int p = n / k;
    vector< vector<long long> > dp;
    dp.resize(k + 1);
    for (int i = 0; i <= k; i++)
        dp[i].resize(k + 1);
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= k; j++) {
            if (i == 0 && j == 0)
                continue;
            int l = p * i + (p + 1) * j;
            if (l > n)
                continue;
            long long x = (i > 0 ? dp[i - 1][j] + a[l - 1] - a[l - p] : INF);
            long long y = (j > 0 ? dp[i][j - 1] + a[l - 1] - a[l - p - 1] : INF);
            dp[i][j] = min(x, y);
        }
    }
    cout << dp[k - n % k][n % k] << endl;
    return 0;
}