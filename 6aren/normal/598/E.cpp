#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)
#define sz(s) ((int) (s).size())

int dp[35][35][1000];

int solve(int n, int m, int k) {
    if (k == 0 || n * m == k) return (dp[n][m][k] = 0);
    if (n > m) swap(n, m);
    if (n * m < k) return 1e9;
    int &ref = dp[n][m][k];
    if (ref != -1) return ref;
    ref = 1e9;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            ref = min(ref, solve(i, m, j) + solve(n - i, m, k - j) + m * m);
        }        
    }
    for (int i = 1; i < m; i++) {
        for (int j = 0; j <= k; j++) {
            ref = min(ref, solve(n, i, j) + solve(n, m - i, k - j) + n * n);
        }
    }
    return ref;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int t;
    cin >> t;
    memset(dp, -1, sizeof(dp));
    dp[1][1][1] = 0;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        cout << solve(n, m, k) << '\n';
    }
    return 0;
}