#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back

#define maxN 200011

int n, i, ini, tree, x, y;
vector<int> list[maxN];
int gr[maxN];
bool us[maxN];

int dp[maxN][2];
//! 0 - free to use
//! 1 - cant be used

void dfs(int node) {
    int i;

    us[node] = true;
    for (i = 0; i < list[node].size(); i++) {
        int to = list[node][i];

        if (us[to]) {
            list[node][i] = list[node][ list[node].size() - 1 ];
            list[node].pop_back();
            i--;
            continue;
        }

        dfs(to);
    }

    if (list[node].empty()) {
        dp[node][0] = dp[node][1] = 0;
        return;
    }

    if (list[node].size() == 1) {
        int to = list[node][0];

        dp[node][0] = dp[node][1] = max(dp[to][1], dp[to][0] + 1);
        return;
    }

    //! compute for 0
    vector<int> aux;
    aux.clear();

    dp[node][0] = 0;

    for (auto to : list[node]) {
        dp[node][0] += dp[to][1];
        aux.pb(dp[to][1] - dp[to][0]);
    }
    dp[node][1] = dp[node][0];

    sort(aux.begin(), aux.end());
    if (-aux[0] + 1 > 0)
        dp[node][0] += -aux[0] + 1;

    //! compute for 1
    if (-aux[0] -aux[1] + 2 > 0)
        dp[node][1] += -aux[0] - aux[1] + 2;
    dp[node][1] = max(dp[node][0], dp[node][1]);
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d%d", &n, &tree, &ini);
    for (i = 1; i < n; i++) {
        scanf("%d%d", &x, &y);
        list[x].pb(y);
        list[y].pb(x);

        gr[x]++; gr[y]++;
    }

    if (n == 1) {
        printf("0");
        return 0;
    }

    if (ini < tree) { //! evita arborele
        bool star = false;
        for (i = 1; i <= n; i++)
            star |= (gr[i] == n - 1);

        if (star)
            printf("%I64d", 1LL * (n - 2) * ini + 1LL * tree);
        else
            printf("%I64d", 1LL * (n - 1) * ini);
    } else { //! mergi pe arbore
        dfs(1);

        printf("%I64d", 1LL * dp[1][1] * tree + 1LL * (n - 1 - dp[1][1]) * ini);
    }


    return 0;
}