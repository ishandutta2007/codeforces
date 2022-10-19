// Randomize
#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define vi vector<int>
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second

int n, k;
long long dp[11][85];
int a[85][85];
bool check[85];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    srand(time(NULL));
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    long long ans = 1e18;
    while (clock() < CLOCKS_PER_SEC * 0.5) {
        for (int i = 1; i <= n; i++) {
            check[i] = rand() % 2;
            dp[0][i] = 1e18;
        }
        dp[0][1] = 0;
        for (int i = 1; i <= k; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = 1e18;
                for (int l = 1; l <= n; l++) {
                    if (check[j] != check[l]) dp[i][j] = min(dp[i][j], dp[i - 1][l] + a[l][j]);
                }
            }
        }
        ans = min(ans, dp[k][1]);
    }
    cout << ans;
    return 0;
}