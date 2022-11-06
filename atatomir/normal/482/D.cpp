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

#define mod 1000000007
#define maxN 100011

int n, i, p;
vector<int> list[maxN];
ll dp[maxN][2], aux[2], aux2[2];

void dfs(int node) {

    if (list[node].empty()) {
        dp[node][0] = 0;
        dp[node][1] = 1;
        return;
    }

    for (auto to : list[node])
        dfs(to);

    dp[node][0] = dp[ list[node][0] ][0] + 1;
    dp[node][1] = dp[ list[node][0] ][1];

    for (int i = 1; i < list[node].size(); i++) {
        int to = list[node][i];

        aux[0] = dp[node][0] % mod;
        aux[1] = dp[node][1] % mod;

        dp[node][0] = dp[node][1] = 0;

        for (int d1 = 0; d1 < 2; d1++) {
            for (int d2 = 0; d2 < 2; d2++) {
                dp[node][d1 ^ d2] += aux[d1] * (dp[to][d2] + (d2 == 0));
            }
        }
    }

    dp[node][0] = (dp[node][0] * 2) % mod;
    dp[node][1] = (dp[node][1] * 2) % mod;

    // remove only-even sons
    aux[0] = 1;
    for (auto to : list[node])
        aux[0] = (aux[0] * dp[to][0] + aux[0]) % mod;

    dp[node][0] += mod - aux[0];

    // remove only-odd sons (odd number)
    aux[0] = 1;
    aux[1] = 0;
    for (auto to : list[node]) {
        memcpy(aux2, aux, sizeof(aux));

        aux[0] = aux2[0] + aux2[1] * dp[to][1];
        aux[1] = aux2[1] + aux2[0] * dp[to][1];

        aux[0] %= mod;
        aux[1] %= mod;
    }

    dp[node][1] += mod - aux[1];

    dp[node][0] %= mod;
    dp[node][1] %= mod;
    swap(dp[node][0], dp[node][1]);
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 2; i <= n; i++) scanf("%d", &p), list[p].pb(i);

    dfs(1);
    ll ans = dp[1][0] + dp[1][1];

    printf("%lld", ans % mod);

    return 0;
}