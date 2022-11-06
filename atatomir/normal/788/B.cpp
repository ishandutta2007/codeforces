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

#define maxN 1000011

int n, m, i, x, y, cnt, bad;
vector<int> list[maxN];
ll ans;
bool us[maxN];
bool good;

int norm, cyc;

void dfs(int node) {
    us[node] = true;


    for (auto to : list[node]) {
        if (to == node) cnt += 2, cyc++;
        else            cnt++, norm++;

        if (!us[to])
            dfs(to);
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &m);
    for (i = 1; i <= m; i++) {
        scanf("%d%d", &x, &y);
        list[x].pb(y);
        if (x != y) list[y].pb(x);
    }

    for (i = 1; i <= n; i++) {
        if (us[i]) continue;
        cnt = 0;
        dfs(i);

        if (cnt > 0) bad++;
        if (cnt >= 4) good = true;
    }

    if (bad != 1 || !good) {
        printf("0");
        return 0;
    }

    for (i = 1; i <= n; i++) {
        for (int j = 0; j < list[i].size(); j++) {
            if (list[i][j] == i) {
                list[i][j] = list[i].back();
                list[i].pop_back();
                break;
            }
        }
        if (list[i].size() <= 1) continue;

        ans += 1LL * list[i].size() * (list[i].size() - 1);
    }

    norm /= 2;
    ans += 1LL * cyc * (cyc - 1);
    ans += 2LL * cyc * norm;

    ans /= 2LL;
    printf("%lld", ans);


    return 0;
}