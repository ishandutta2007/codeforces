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

#define maxN 1024

int n, m, w, i, x, y, ss, dd;
int pay[maxN], bonus[maxN];
vector<int> list[maxN];
bool us[maxN];

vector<int> aux;
ll dp[2][maxN];

void dfs(int node) {
    us[node] = true;
    aux.pb(node);

    for (auto to : list[node])
        if (!us[to])
            dfs(to);
}

void add_elems() {
    int i;
    ll sum_pay, sum_bonus;

    sum_pay = sum_bonus = 0;

    memcpy(dp[dd], dp[ss], sizeof(dp[dd]));
    for (auto e : aux) {
        for (i = pay[e]; i <= w; i++)
            dp[dd][i] = max(dp[dd][i], dp[ss][i - pay[e]] + bonus[e]);
        sum_pay += pay[e];
        sum_bonus += bonus[e];
    }

    for (i = sum_pay; i <= w; i++)
        dp[dd][i] = max(dp[dd][i], dp[ss][i - sum_pay] + sum_bonus);

    swap(ss, dd);
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d%d", &n, &m, &w);
    for (i = 1; i <= n; i++) scanf("%d", &pay[i]);
    for (i = 1; i <= n; i++) scanf("%d", &bonus[i]);
    for (i = 1; i <= m; i++) {
        scanf("%d%d", &x, &y);
        list[x].pb(y);
        list[y].pb(x);
    }

    ss = 0; dd = 1;
    for (i = 1; i <= n; i++) {
        if (us[i]) continue;
        aux.clear();
        dfs(i);
        add_elems();
    }

    printf("%lld", dp[ss][w]);


    return 0;
}