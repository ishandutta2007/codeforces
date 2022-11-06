#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

#define mp make_pair
#define pb push_back

#define maxN 416

int n, m, i, j, x, y;
bool road[maxN][maxN];
queue<int> Q;
int tt[maxN];

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &m);
    for (i = 1; i <= m; i++) {
        scanf("%d%d", &x, &y);
        road[x][y] = road[y][x] = true;
    }

    if (road[1][n] == true) {
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                road[i][j] ^= 1;
    }

    for (i = 1; i <= n; i++) tt[i] = maxN;

    while (!Q.empty()) Q.pop();
    tt[1] = 1;
    Q.push(1);

    while (!Q.empty()) {
        int node = Q.front(); Q.pop();

        for (i = 1; i <= n; i++) {
            if (road[node][i]) {
                if (tt[i] != maxN) continue;
                tt[i] = tt[node] + 1;
                Q.push(i);
            }
        }
    }

    if (tt[n] == maxN) {
        printf("-1");
        return 0;
    }

    printf("%d", tt[n] - 1);

    return 0;
}