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

const int MAXN = (int) 1e6 + 7;

int dp[MAXN];
int len[MAXN];

int main() {
    int n, a, b;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a, &b);
        len[a] = b;
    }
    int ans = 0;
    for (int i = 0; i < MAXN; i++) {
        if (len[i]) {
            dp[i] = max(dp[i], (i - len[i] - 1 >= 0) * dp[i - len[i] - 1] + 1);
        } else {
            dp[i] = (i > 0) * dp[i - 1];
        }
        ans = max(ans, dp[i]);
    }
    printf("%d\n", n - ans);
}