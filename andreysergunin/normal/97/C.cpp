#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <cassert>
#include <unordered_map>
#include <fstream>
#include <random>
#include <cstring>
#include <complex>
#include <bitset>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
mt19937 rr(random_device{}());


int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

    int n;
    cin >> n;
    vector<double> p(n + 1);
    for (int i = 0; i <= n; ++i)
        cin >> p[i];

    double ans = 0;

    for (int t = 0; t < n; ++t) {
        vector<vector<bool>> r(2 * n + 1, vector<bool>(2 * n + 1));
        vector<vector<double>> dp(2 * n + 1, vector<double>(2 * n + 1));

        r[0][t] = true;

        for (int i = 0; i < 2 * n; ++i) {
            for (int j = 0; j <= 2 * n; ++j) {
                if (!r[i][j])
                    continue;
                for (int k = 0; k <= min(n, j); ++k) {
                    if (j - k + n - k > 2 * n)
                        continue;
                    r[i + 1][j - k + n - k] = true;
                    dp[i + 1][j - k + n - k] = max(dp[i + 1][j - k + n - k], dp[i][j] + p[k]);
                }
            }
            if (r[i + 1][t]) {
                ans = max(ans, dp[i + 1][t] / (i + 1));
            }
        }
    }

    cout.precision(12);
    cout << fixed;
    cout << ans << endl;
    return 0;
}