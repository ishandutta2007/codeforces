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

#define maxN 5011

struct item {
    int cost, disc, dad;
};

int n, i, j;
ll B;
item I[maxN];
vector<int> list[maxN];

bool us[maxN];
int cnt[maxN];
int dp[2][maxN][maxN];
int aux[2][maxN];

int ans[maxN];

void combine(int node, int to) {
    static int i, j;

    for (i = 0; i <= cnt[node]; i++) {
        aux[0][i] = dp[0][node][i];
        aux[1][i] = dp[1][node][i];

        dp[0][node][i] = B + 1;
        dp[1][node][i] = B + 1;
    }

    //! non-discount
    for (i = 0; i <= cnt[node]; i++)
        for (j = 0; j <= cnt[to]; j++)
            dp[0][node][i + j] = min(dp[0][node][i + j], aux[0][i] + dp[0][to][j]);

    //! discount
    for (i = 0; i <= cnt[node]; i++) {
        for (j = 0; j <= cnt[to]; j++) {
            dp[1][node][i + j] = min(dp[1][node][i + j], aux[1][i] + dp[0][to][j]);
            dp[1][node][i + j] = min(dp[1][node][i + j], aux[1][i] + dp[1][to][j]);
        }
    }

}

void dfs(int node) {
    us[node] = true;
    cnt[node] = 1;

    dp[0][node][0] = 0;
    dp[0][node][1] = I[node].cost;
    dp[1][node][1] = I[node].cost - I[node].disc;

    for (auto to : list[node]) {
        dfs(to);
        combine(node, to);
        cnt[node] += cnt[to];
    }

}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &B);

    for (i = 0; i <= n; i++)
        for (j = 0; j <= n; j++)
            dp[0][i][j] = dp[1][i][j] = B + 1;

    for (i = 1; i <= n; i++) {
        scanf("%d%d", &I[i].cost, &I[i].disc);
        if (i == 1) continue;
        scanf("%d", &I[i].dad);
        list[I[i].dad].pb(i);
    }

    dfs(1);

    for (i = 0; i <= n; i++) ans[i] = B + 1;
    for (i = 0; i <= cnt[1]; i++) ans[i] = min(dp[0][1][i], dp[1][1][i]);

    for (i = 1; i <= n; i++) {
        if (us[i]) continue;

        for (j = n - 1; j >= 0; j--)
            ans[j + 1] = min(ans[j + 1], ans[j] + I[i].cost);
    }

    for (i = 0; ans[i + 1] <= B && i + 1 <= n; i++);
    printf("%d", i);


    return 0;
}