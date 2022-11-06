#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back

#define maxN 150011

int n, i, m, x, y, R;
vector<int> list[maxN];
bool us[maxN];
bool must[maxN];
int dp[maxN], dp_up[maxN];

int ans, how, def;

void dfs(int node) {
    us[node] = true;

    dp[node] = 1;

    for (int i = 0; i < list[node].size(); i++) {
        int to = list[node][i];

        if (us[to]) {
            list[node][i] = list[node][ list[node].size() -1 ];
            list[node].pop_back();
            i--;
            continue;
        }

        dfs(to);
        dp[node] += dp[to];
        if (dp[to] == 0) {
            list[node][i] = list[node][ list[node].size() -1 ];
            list[node].pop_back();
            i--;
            continue;
        }
    }

    if (!must[node] && dp[node] == 1) dp[node] = 0;
}

void dfs_compute(int node) {
    dp[node] = 0;
    for (auto to : list[node]) {
        dfs_compute(to);
        dp[node] = max(dp[node], dp[to] + 1);
    }
}

bool cmp(int a, int b) {
    return dp[a] > dp[b];
}

void dfs_smen(int node) {
    int aux = def - max(dp[node], dp_up[node]);
    if (how > aux || (how == aux && node < ans)) {
        how = aux;
        ans = node;
    }

    sort(list[node].begin(), list[node].end(), cmp);
    if (list[node].size() == 0) return;
    if (list[node].size() == 1) {
        int to = list[node][0];

        dp_up[to] = dp_up[node] + 1;
        dfs_smen(to);

        return;
    }

    int to = list[node][0];
    int to2 = list[node][1];

    dp_up[to] = max(dp_up[node] + 1, dp[to2] + 2);
    dfs_smen(to);

    to2 = to;
    for (int i = 1; i < list[node].size(); i++) {
        to = list[node][i];

        dp_up[to] = max(dp_up[node] + 1, dp[to2] + 2);
        dfs_smen(to);
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d %d", &n, &m);
    for (i = 1; i < n; i++) {
        scanf("%d%d", &x, &y);
        list[x].pb(y);
        list[y].pb(x);
    }
    for (i = 1; i <= m; i++) {
        scanf("%d", &x);
        must[x] = true;
    }

    if (m == 1) {
        printf("%d %d", x, 0);
        return 0;
    }

    dfs(1);

    R = 1;
    while (list[R].size() == 1 && must[R] == false) R = list[R][0];
    def = 2 * dp[R] - 2;

    memset(dp, 0, sizeof(dp));
    dfs_compute(R);
    ans = R;
    how = def - dp[R];

    dfs_smen(R);

    printf("%d\n%d", ans, how);


    return 0;
}