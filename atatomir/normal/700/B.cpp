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

int n, m, i, x, y;
vector<int> list[maxN];
int cnt[maxN];
bool us[maxN];

ll ans;

void dfs(int node) {
    us[node] = true;

    for (int to : list[node]) {
        if (us[to]) continue;

        dfs(to);
        cnt[node] += cnt[to];
        ans += 1LL * min(cnt[to], 2 * m - cnt[to]);
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &m);
    for (i = 1; i <= 2 * m; i++)
        scanf("%d", &x), cnt[x]++;
    for (i = 1; i < n; i++) {
        scanf("%d%d", &x, &y);
        list[x].pb(y);
        list[y].pb(x);
    }

    dfs(1);

    printf("%lld", ans);


    return 0;
}