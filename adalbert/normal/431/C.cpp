#include <bits/stdc++.h>
#define int ll
#define fir first
#define sec second
#define pb push_back
using namespace std;

typedef long long ll;

const int MAX_N = 1e5 + 100;
int answer;

int dp[200][200];
const int md = 1e9 + 7;

main() {
    int n, k, d;
    cin >> n >> k >> d;

    dp[0][0] = 1;

    for (int i = 0; i <= n; i++)
        for (int now = 1; now <= k; now++)
        for (int mx = 0; mx <= k; mx++)
        if (i + now <= n) {
            dp[i + now][max(mx, now)] += dp[i][mx];
            dp[i + now][max(mx, now)] %= md;
        }

    int ans = 0;
    for (int i = d; i <= k; i++) {
        ans += dp[n][i];
        ans %= md;
    }

    cout << ans;
}