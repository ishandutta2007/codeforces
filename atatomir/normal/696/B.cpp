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

int n, i, x;
vector<int> list[maxN];
bool us[maxN];
int cnt[maxN];
double ans[maxN];

void dfs(int node) {
    us[node] = true;
    cnt[node] = 1;

    for (int to : list[node])
        if (!us[to])
            {dfs(to); cnt[node] += cnt[to];}
}

void dfs2(int node) {
    us[node] = true;

    for (int to : list[node]) {
        if (us[to] == true) continue;

        double aux = cnt[node] - 1 - cnt[to];
        aux /= 2.00;

        ans[to] = ans[node] + 1.00 + aux;

        dfs2(to);
    }
}


int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 2; i <= n; i++) {
        scanf("%d", &x);
        list[x].pb(i);
    }

    ans[1] = 1.00;
    dfs(1);

    memset(us, 0, sizeof(us));
    dfs2(1);

    for (i = 1; i <= n; i++)
        printf("%.8lf ", ans[i]);


    return 0;
}