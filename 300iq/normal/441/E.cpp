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

const int MAXN = 300 + 7;

double dp[MAXN][MAXN];

int cnt(int x) {
    int cnt = 0;
    while (!(x & 1)) x >>= 1, cnt++;
    return cnt;
}

int main() {
    int x, k, p;
    scanf("%d%d%d", &x, &k, &p);
    double P = p / 100.0;
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= k; j++) {
            if (i == 0) dp[i][j] = cnt(x + j);
            if (i != 0) dp[i][j] = dp[i - 1][j + 1] * (1 - P);
            if (i != 0 && !(j & 1)) dp[i][j] += P * (dp[i - 1][j >> 1] + 1);
        }
    }
    printf("%.20lf\n", dp[k][0]);
}