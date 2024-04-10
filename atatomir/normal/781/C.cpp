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

int n, m, k, i, j, x, y, limit;
vector<int> list[maxN];

bool us[maxN];
vector<int> ord, aux;
vector< vector<int> > sol;

void dfs(int node) {
    ord.pb(node);
    us[node] = true;

    for (auto to : list[node]) {
        if (us[to]) continue;
        dfs(to);
        ord.pb(node);
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d%d", &n, &m, &k);
    for (i = 1; i <= m; i++) {
        scanf("%d%d", &x, &y);
        list[x].pb(y);
        list[y].pb(x);
    }

    dfs(1);

    memset(us, 0, sizeof(us));
    limit = (2 * n + k - 1) / k;

    for (i = 0; i < ord.size(); i++) {
        if (us[ord[i]]) continue;

        aux.clear();
        for (j = i; j < ord.size() && j - i + 1 <= limit; j++) {
            aux.pb(ord[j]);
            us[ord[j]] = true;
        }

        sol.pb(aux);

        i = j - 1;
    }

    while (sol.size() < k)
        sol.pb({1});

    sol.resize(k);
    for (auto e : sol) {
        printf("%d ", e.size());
        for (auto p : e)
            printf("%d ", p);
        printf("\n");
    }



    return 0;
}