#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fc first
#define sc second
#define ll long long
#define forn(i, n) for(int i = 0; i < (int) (n); i++)
#define fort(i, j, n) for (int i = j; i < (int) (n); i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

const int MAXN = (int) 5e2 + 7;

bool p[MAXN][MAXN];
int dp[MAXN][MAXN];

int main() {
    int n;
    scanf("%d", &n);
    vector <int> c(n);
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            dp[i][j] = INT_MAX;
        }
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
        p[i][i] = dp[i][i] = 1;
    }
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;
            p[i][j] = ((len == 2 || p[i + 1][j - 1]) && c[i] == c[j]);
            dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
            dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);
            if (p[i][j]) {
                dp[i][j] = 1;
            }
            for (int t = i + 2; t <= j; t++) {
                if (c[i] == c[t]) {
                    dp[i][j] = min(dp[i][j], dp[i + 1][t - 1] + dp[t + 1][j]);
                }
            }
            for (int t = i; t < j; t++) {
                dp[i][j] = min(dp[i][j], dp[i][t] + dp[t + 1][j]);
            }
        }
    }
    printf("%d\n", dp[0][n - 1]);
}