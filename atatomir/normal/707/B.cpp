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
#define inf (1 << 30)

struct edge {
    int x, y, l;
};

int n, m, k, i, x;
edge E[maxN];
bool boss[maxN];
int ans = inf;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d%d", &n, &m, &k);
    for (i = 1; i <= m; i++) scanf("%d%d%d", &E[i].x, &E[i].y, &E[i].l);
    for (i = 1; i <= k; i++) {
        scanf("%d", &x);
        boss[x] = true;
    }

    for (i = 1; i <= m; i++) {
        int cnt = 0;

        if (boss[E[i].x]) cnt++;
        if (boss[E[i].y]) cnt++;
        if (cnt == 1)
            ans = min(ans, E[i].l);
    }

    if (ans == inf)
        printf("%d", -1);
    else
        printf("%d", ans);



    return 0;
}