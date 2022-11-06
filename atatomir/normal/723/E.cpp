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

#define maxN 211

int n, m, i, x, y, t, ti;
vector<int> list[maxN];

bool exist[maxN][maxN];
vector<int> aux;
vector< pair<int, int> > ans;
int gr[maxN];

void dfs(int node) {
    for (int to : list[node]) {
        if (!exist[node][to]) continue;
        exist[node][to] = exist[to][node] = false;

        dfs(to);
    }

    aux.pb(node);
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &t);
    for (ti = 1; ti <= t; ti++) {

        scanf("%d%d", &n, &m);

        for (i = 1; i <= n; i++) list[i].clear();
        memset(exist, 0, sizeof(exist));

        for (i = 1; i <= m; i++) {
            scanf("%d%d", &x, &y);
            list[x].pb(y);
            list[y].pb(x);
            exist[x][y] = exist[y][x] = true;
        }

        list[n + 1].clear();
        for (i = 1; i <= n; i++) {
            if (list[i].size() % 2 == 1) {
                list[i].pb(n + 1);
                list[n + 1].pb(i);

                exist[i][n + 1] = exist[n + 1][i] = true;
            }
        }

        ans.clear();
        memset(gr, 0, sizeof(gr));
        for (i = 1; i <= n + 1; i++) {
            aux.clear();
            dfs(i);

            if (aux.size() == 1) continue;
            for (i = 1; i < aux.size(); i++) {
                int n1 = aux[i - 1];
                int n2 = aux[i];


                if (n1 > n || n2 > n) continue;
                ans.pb(mp(n1, n2));
                gr[n2]++; gr[n1]--;
            }
        }

        int sol = 0;
        for (i = 1; i <= n; i++)
            sol += (gr[i] == 0);

        printf("%d\n", sol);
        for (auto e : ans)
            printf("%d %d\n", e.first, e.second);
    }




    return 0;
}