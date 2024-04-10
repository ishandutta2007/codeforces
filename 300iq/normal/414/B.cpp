#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fc first
#define sc second
#define ll long long
#define forn(i, n) for (int i = 0; i < (int) (n); i++)
#define fort(i, j, n) for (int i = j; i < (int) (n); i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define bit(x) __builtin_popcount(x)

const int N = (int) 2000 + 7;
const int M = (int) 1e9 + 7;
int dp[N][N] = {{0, 1}};

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    dp[0][1] = 1;
    for (int i = 0; i < k; i++) {
        for (int j = 1; j <= n; j++) {
            for (int t = j; t <= n; t += j) {
                (dp[i + 1][t] += dp[i][j]) %= M;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) (ans += dp[k][i]) %= M;
    printf("%d\n", ans);
}