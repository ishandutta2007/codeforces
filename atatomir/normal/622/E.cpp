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

#define maxN 500011

int n, i, x, y, last;
vector<int> list[maxN];
bool us[maxN];
vector<int> aux;
int ans;

void dfs(int node, int lvl) {
    us[node] = true;
    if (list[node].size() == 1 && us[list[node][0]] )
        aux.pb(lvl);

    for (int to : list[node])
        if (!us[to])
            dfs(to, lvl + 1);
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i < n; i++) {
        scanf("%d%d", &x, &y);
        list[x].pb(y);
        list[y].pb(x);
    }

    us[1] = true;
    for (int to : list[1]) {
        aux.clear();

        dfs(to, 1);
        sort(aux.begin(), aux.end());

        last = -1;
        for (auto e : aux)
            last = max(last + 1, e);

        ans = max(ans, last);
    }

    printf("%d", ans);


    return 0;
}