#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 84
#define inf (1 << 25)

int n, k, m, i, j, cnt, x, y, z;
vector< pair<int, int> > list[maxN];
int dp[maxN][maxN][maxN];

int solve(int cnt, int l, int r) {
    if (dp[cnt][l][r] != -1)
        return dp[cnt][l][r];

    if (cnt == 1) {
        dp[cnt][l][r] = 0;
        return 0;
    }

    dp[cnt][l][r] = inf;
    int mini = min(l, r);
    int maxi = max(l, r);
    for (auto to : list[l]) {
        if (to.first <= mini || to.first >= maxi) continue;
        dp[cnt][l][r] = min(dp[cnt][l][r], to.second + solve(cnt - 1, to.first, mini));
        dp[cnt][l][r] = min(dp[cnt][l][r], to.second + solve(cnt - 1, to.first, maxi));
    }

    return dp[cnt][l][r];
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d%d", &n, &k, &m);
    for (i = 1; i <= m; i++) {
        scanf("%d%d%d", &x, &y, &z);
        list[x].pb(mp(y, z));
    }

    for (cnt = 0; cnt <= k + 1; cnt++)
        for (i = 0; i <= n + 1; i++)
            for (j = 0; j <= n + 1; j++)
                dp[cnt][i][j] = -1;

    int ans = inf;
    for (i = 1; i <= n; i++) {
        ans = min(ans, solve(k, i, 0));
        ans = min(ans, solve(k, i, n + 1));
    }

    if (ans >= inf)
        ans = -1;
    cout << ans;

    return 0;
}