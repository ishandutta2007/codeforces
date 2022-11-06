#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back

#define maxN 100011
#define ll long long

int n, m, i, x, y;
vector<int> list[maxN];
ll gr[maxN];
ll dp[maxN];
ll ans;


int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &m);
    for (i = 1; i <= m; i++) {
        scanf("%d%d", &x, &y);
        gr[x]++;
        gr[y]++;

        if (x > y) swap(x, y);
        list[y].pb(x);
    }

    for (i = 1; i <= n; i++) {
        dp[i] = 1;

        for (auto from : list[i])
            dp[i] = max(dp[i], dp[from] + 1);

        ans = max(ans, dp[i] * gr[i]);
    }

    printf("%I64d", ans);


    return 0;
}