
using namespace std;

#define visual

#ifdef visual
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <assert.h>
#include <functional>
#include <math.h>
#include <string>
#include <ctime>
#endif
#ifndef visual
#include <bits/stdc++.h>
#endif

typedef long long ll;

ll dp[5001][5001];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    ll n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    ll mx = 0;
    for (ll i = 0; i <= n; i++) {
        for (ll j = 0; j <= m; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
                continue;
            }
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 2;
                mx = max(mx, dp[i][j]);
                continue;
            }
            else {
                dp[i][j] = max(dp[i - 1][j] - 1, dp[i][j - 1] - 1);
                dp[i][j] = max(dp[i][j], 0ll);
            }
        }
    }
    cout << mx << endl;
}