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

#define maxN 222

int n, m, i, k, sk, j, x;
vector<int> list[maxN];
bool us[maxN];
int ans = -1;

void dfs(int node) {
    us[node] = true;
    for (auto to : list[node])
        if (!us[to])
            dfs(to);
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++) {
        scanf("%d", &k); sk += k;
        for (j = 1; j <= k; j++) {
            scanf("%d", &x);
            list[i].pb(x + n);
            list[x + n].pb(i);
        }
    }

    for (i = 1; i <= n; i++)
        if (!us[i])
            ans++, dfs(i);

    if (sk == 0) ans++;
    printf("%d", ans);


    return 0;
}