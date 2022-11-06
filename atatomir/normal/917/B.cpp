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

#define maxN 111
#define sigma 26

int n, m, i, j, u, v;
char c;
vector< pair<int, int> > list[maxN];
int dp[sigma][maxN][maxN];

int compute(int step, int x, int y) {
    int act;

    if (dp[step][x][y] != 0)
        return dp[step][x][y] - 1;

    act = 0;
    for (auto to : list[x]) {
        if (to.second < step) continue;
        if (compute(to.second, y, to.first) == 0) {
            act = 1;
            break;
        }
    }

    dp[step][x][y] = act + 1;
    return act;
}

int main()
{
   // freopen("test.in","r",stdin);

    scanf("%d%d", &n, &m);
    for (i = 1; i <= m; i++) {
        scanf("%d %d %c", &u, &v, &c);
        list[u].pb(mp(v, c - 'a'));
        //list[v].pb(mp(u, c - 'a'));
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            int aux = compute(0, i, j);
            if (aux == 1)
                printf("A");
            else
                printf("B");
        }
        printf("\n");
    }


    return 0;
}