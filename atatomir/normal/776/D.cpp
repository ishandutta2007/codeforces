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

int n, m, i, k, j, x;
int st[maxN];
vector<int> wh[maxN];
vector< pair<int, int> > list[maxN];

bool us[maxN];
int tp[maxN];

void dfs(int node) {
    us[node] = true;

    for (auto to : list[node]) {
        if (us[to.first]) continue;
        tp[to.first] = 1 ^ tp[node] ^ st[to.second];
        dfs(to.first);
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++) scanf("%d", &st[i]);
    for (i = 1; i <= m; i++) {
        scanf("%d", &k);
        for (j = 1; j <= k; j++) {
            scanf("%d", &x);
            wh[x].pb(i);
        }
    }

    for (i = 1; i <= n; i++) {
        list[ wh[i][0] ].pb(mp( wh[i][1], i ));
        list[ wh[i][1] ].pb(mp( wh[i][0], i ));
    }

    for (i = 1; i <= m; i++)
        if (!us[i])
            dfs(i);

    for (i = 1; i <= n; i++) {
        int n1 = wh[i][0];
        int n2 = wh[i][1];

        if ((st[i] ^ tp[n1] ^ tp[n2]) == 0) {
            printf("NO");
            return 0;
        }
    }

    printf("YES");


    return 0;
}