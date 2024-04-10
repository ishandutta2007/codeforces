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

const int N = (int) 2e2 + 7;
const int M = (int) 5e5 + 7;
const int PLUS = (int) 2e5 + 7;
const int MOD = (int) 1e9 + 7;
int dp[2][M];
int pref[2][M];
map <int, int> cnt;

int main() {
    int a, b, k, t;
    scanf("%d%d%d%d", &a, &b, &k, &t);
    t *= 2;
    dp[0][a - b + PLUS] = 1;
    pref[0][0] = dp[0][0];
    for (int i = 1; i < M; i++) {
        pref[0][i] += pref[0][i - 1] + dp[0][i];
    }
    t++;
    int c = 1;
    for (int i = 1; i < t; i++) {
        for (int j = 0; j < M; j++) {
            dp[c][j] = ((pref[c ^ 1][min(M - 1, j + k)] - (j - k - 1 >= 0 ? pref[c ^ 1][j - k - 1] : 0)) % MOD + MOD) % MOD;
        }
        pref[c][0] = dp[c][0];
        for (int j = 1; j < M; j++) {
            pref[c][j] = (dp[c][j] + pref[c][j - 1]) % MOD;
        }
        c ^= 1;
    }
    int ans = 0;
    for (int i = PLUS + 1; i < M; i++) {
        ans += dp[c ^ 1][i];
        ans %= MOD;
    }
    printf("%d\n", ans);
}