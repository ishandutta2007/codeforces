#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int MxN = 509;

ll dp[MxN + 9][MxN + 9];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;
    for (int diff = 2; diff < n; ++diff) {
        for (int i = 1; i <= n; ++i) {
            const int j = (i - 1 + diff) % n + 1;
            ll &res = dp[i][j] = numeric_limits<ll>::max();
            for (int k = i % n + 1; k != j; k = k%n + 1)
                res = min(res, 1LL * i * j * k + dp[i][k] + dp[k][j]);
        }
    }

    cout << dp[1][n];
    return 0;
}