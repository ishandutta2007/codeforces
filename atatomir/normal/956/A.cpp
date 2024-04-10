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

const int maxN = 111;

int n, m, i, j;
char s[maxN][maxN], act[maxN][maxN];

vector<int> list[maxN];
bool us[maxN];
vector<int> l, c;

void dfs(int node) {
    us[node] = true;
    if (node <= n)
        l.pb(node);
    else
        c.pb(node - n);

    for (auto to : list[node])
        if (!us[to])
            dfs(to);
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d\n", &n, &m);
    for (i = 1; i <= n; i++) {
        scanf("%s", s[i] + 1);

        for (j = 1; j <= m; j++) {
            act[i][j] = '.';

            if (s[i][j] == '#') {
                list[i].pb(n + j);
                list[n + j].pb(i);
            }
        }
    }

    for (i = 1; i <= n + m; i++) {
        if (us[i]) continue;
        l.clear(); c.clear();
        dfs(i);

        for (auto e1: l)
            for (auto e2 : c)
                act[e1][e2] = '#';
    }

    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            if (act[i][j] != s[i][j])
                {printf("No"); return 0;}

    printf("Yes");

    return 0;
}