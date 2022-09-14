#include <iostream>
#include <stdio.h>
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
#include <bitset>
#include <functional>
#include <tuple>
#include <complex>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

const int MAXN = 6000;
const int INF = 1e9;
int dp[MAXN][MAXN][3];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            for (int k = 0; k < 4; ++k) {
                dp[i][j][k] = INF;
            }
        }
    }

    dp[0][0][0] = 0;
    dp[0][1][1] = 0;

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j <= i + 1; ++j) {
            dp[i + 1][j][0] = min(dp[i + 1][j][0], dp[i][j][0]);
            dp[i + 1][j + 1][1] = min(dp[i + 1][j + 1][1], dp[i][j][0] + max(0, a[i] - a[i + 1] + 1));

            dp[i + 1][j][2] = min(dp[i + 1][j][2], dp[i][j][1] + max(0, a[i + 1] - a[i] + 1));

            dp[i + 1][j][0] = min(dp[i + 1][j][0], dp[i][j][2]);

            int delta = max(0, a[i] - a[i + 1] + 1) - max(0, a[i] - a[i - 1] + 1);

            dp[i + 1][j + 1][1] = min(dp[i + 1][j + 1][1], dp[i][j][2] + max(0, delta));
        }
    }

    for (int i = 1; i <= (n + 1) / 2; ++i) {
        cout << min({dp[n - 1][i][0], dp[n - 1][i][1], dp[n - 1][i][2]}) << " ";
    }
    cout << endl;



    return 0;
}