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

int n, m, i, x, y;
vector<int> list[maxN];
int tp[maxN];

vector<int> A, B;

void dfs(int node, int col) {
    tp[node] = col;
    if (col == 1)
        A.pb(node);
    else
        B.pb(node);

    for (auto to : list[node]) {
        if (tp[to] == 0)
            dfs(to, col ^ 3);
        if (tp[to] == tp[node]) {
            printf("-1");
            exit(0);
        }
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &m);
    for (i = 1; i <= m; i++) {
        scanf("%d%d", &x, &y);
        list[x].pb(y);
        list[y].pb(x);
    }

    for (i = 1; i <= n; i++) {
        if (tp[i]) continue;
        dfs(i, 1);
    }

    printf("%d\n", A.size());
    for (auto e : A) printf("%d ", e);
    printf("\n");
    printf("%d\n", B.size());
    for (auto e : B) printf("%d ", e);
    printf("\n");


    return 0;
}