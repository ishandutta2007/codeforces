#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back

#define maxN 555

int n, m, i, j, x, y, big_tree;
bool adj[maxN][maxN];
vector<int> list[maxN];
char ans[maxN];

int expected;
bool us[maxN];

bool good = true;
vector<int> aux;

vector<int> lf, rh;

void dfs(int node) {
    us[node] = true;
    aux.pb(node);

    for (auto to : list[node]) {
        if (us[to]) continue;
        dfs(to);
    }
}

bool is_good() {
    if (big_tree) return false;

    lf.clear();
    rh.clear();

    rh = list[aux[0]];
    lf = list[ rh[0] ];

    //! muchii intre cele doua parti
    for (auto n1 : lf) {
        for (auto n2 : rh) {
            if (n1 == n2) return false;
            if (adj[n1][n2]) return false;
        }
    }

    for (auto n1 : lf)
        for (auto n2 : lf)
            if (n1 != n2 && adj[n1][n2] == false)
                return false;

    for (auto n1 : rh)
        for (auto n2 : rh)
            if (n1 != n2 && adj[n1][n2] == false)
                return false;

    for (auto node : lf)
        ans[node] = 'a';
    for (auto node : rh)
        ans[node] = 'c';

    if (lf.size() + rh.size() != aux.size())
        return false;

    return true;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &m);
    for (i = 1; i <= m; i++) {
        scanf("%d%d", &x, &y);
        adj[x][y] = adj[y][x] = true;
    }

    m = 0;
    for (i = 1; i <= n; i++)
        for (j = i + 1; j <= n; j++)
            if (adj[i][j] == false)
                list[i].pb(j), list[j].pb(i), m++;

    for (i = 1; i <= n; i++) ans[i] = 'b';

    for (i = 1; i <= n; i++) {
        if (us[i]) continue;

        if (list[i].size() > 0) {
            aux.clear();
            dfs(i);
            if (!is_good()) {
                good = false;
                break;
            }

            big_tree++;
        }
    }

    if (!good) {
        printf("No");
        return 0;
    }

    printf("Yes\n%s\n", ans + 1);

    return 0;
}