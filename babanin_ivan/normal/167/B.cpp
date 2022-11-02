#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>

using namespace std;

#define pb push_back
#define mp make_pair
#define fir first
#define fi first
#define sec second
#define y1 botva23
typedef long long int64;
typedef long double ld;

const int inf = 2000000000;
const ld eps = 1e-07;

int n, l, k;
ld dp[210][210][410];
int a[210];
ld p[210];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    cin >> n >> l >> k;
    for (int i = 1; i <= n; ++i)
        cin >> p[i];
    for (int i = 1; i <= n; ++i)
        p[i] /= 100.0;

    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    dp[0][0][k + 200] = 1;
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j <= n; ++j)
            for (int k = 0; k <= 400; ++k)
                if (a[i + 1] == -1) {
                    if (k > 0) {
                        dp[i + 1][j + 1][k - 1] += dp[i][j][k] * p[i + 1];
                    }
                    dp[i + 1][j][k] += dp[i][j][k] * (1.0 - p[i + 1]); 
                }
                else {
                    int t = a[i + 1] + k;
                    if (t > 400)
                        t = 400;
                    dp[i + 1][j + 1][t] += dp[i][j][k] * p[i + 1];
                    dp[i + 1][j][k] += dp[i][j][k] * (1.0 - p[i + 1]);
                }
    ld sum = 0;
    for (int j = l; j <= n; ++j)
        for (int i = 200; i <= 400; ++i)
            sum += dp[n][j][i];
    cout.precision(10);
    cout << fixed << sum << endl;
    return 0;
}