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



int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    if (n > m) {
        cout << "YES" << endl;
        return 0;
    }
    vector< vector<int> > dp;
    dp.resize(n + 1);
    for (int i = 0; i <= n; i++)
        dp[i].resize(m);
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++)
            dp[i][j] = min(dp[i - 1][j] + dp[i - 1][(j - (a[i - 1] % m) + m) % m], 2);
    }
    if (dp[n][0] == 2)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}