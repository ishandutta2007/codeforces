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

#define maxN 100011
#define maxLog 20

int n, i, j, lvl, help[maxN];
pair<int, int> rmq[maxLog][maxN];

ll ans;
ll dp[maxN];

int query(int l, int r) {
    int dim = r - l + 1;
    int act = help[dim];

    return max(rmq[act][l], rmq[act][r - (1 << act) + 1]).second;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i < n; i++) scanf("%d", &rmq[0][i].first), rmq[0][i].second = i;
    rmq[0][n] = mp(n, n);

    for (lvl = 1; (1 << lvl) < n; lvl++);
    help[1] = 0;
    for (i = 2; i <= n; i++) help[i] = help[i / 2] + 1;

    for (i = 1; i <= lvl; i++) {
        int dim = (1 << i);
        int sdim = dim >> 1;

        for (j = 1; j + dim - 1 <= n; j++)
            rmq[i][j] = max(rmq[i - 1][j], rmq[i - 1][j + sdim]);
    }

    dp[n] = ans = 0;
    for (i = n - 1; i > 0; i--) {
        int pos = query(i + 1, rmq[0][i].first);

        dp[i] = dp[pos] + 1;
        dp[i] += (n - i);
        dp[i] -= rmq[0][i].first - pos + 1;

        ans += dp[i];
    }

    printf("%lld", ans);


    return 0;
}