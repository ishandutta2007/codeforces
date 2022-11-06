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

#define maxN 200011
#define maxK 7

int n, k, i, j, x, y;
vector<int> list[maxN];
ll cnt[maxN][maxK];
ll sum[maxN][maxK];

ll aux_cnt[maxK];
ll aux_sum[maxK];
ll ans;

int pre[maxK][maxK];

void dfs(int node, int root) {
    int i, j, pp;
    cnt[node][0] = 1;
    sum[node][0] = 0;

    for (auto to : list[node]) {
        if (to == root)
            continue;

        dfs(to, node);

        memset(aux_cnt, 0, sizeof(aux_cnt));
        memset(aux_sum, 0, sizeof(aux_sum));
        for (i = 0; i + 1 < k; i++) {
            aux_cnt[i + 1] = cnt[to][i];
            aux_sum[i + 1] = sum[to][i];
        }

        aux_cnt[0] = cnt[to][k - 1];
        aux_sum[0] = sum[to][k - 1] + aux_cnt[0];

        for (i = 0; i < k; i++) {
            for (j = 0; j < k; j++) {
                ans += cnt[node][i] * aux_sum[j];
                ans += sum[node][i] * aux_cnt[j];
                ans += cnt[node][i] * aux_cnt[j] * pre[i][j];
            }
        }


        for (i = 0; i < k; i++) {
            sum[node][i] += aux_sum[i];
            cnt[node][i] += aux_cnt[i];
        }
    }
}


int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &k);
    for (i = 1; i < n; i++) {
        scanf("%d%d", &x, &y);
        list[x].pb(y);
        list[y].pb(x);
    }

    for (i = 0; i < k; i++)
        for (j = 0; j < k; j++)
            pre[i][j] = (i + j + k - 1) / k;

    dfs(1, 0);

    printf("%lld", ans);


    return 0;
}