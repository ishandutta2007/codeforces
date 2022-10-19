#include <bits/stdc++.h>
using namespace std;

const int N = 1010;

int fa[N][N];
int _find(int x, int j) {return fa[x][j] == x ? x : fa[x][j] = _find(fa[x][j], j);}

int n, m, k;
int a[N][N];
int ans;

void go (int x, int y) {
    // printf ("%d %d %d\n", x, y, a[x][y]);
    if (a[x][y] == 2) {
        int fx = _find(x, y);
        if (fx == n + 1) {
            ans = y;
            return ;
        }
        else
            go (fx, y);
    }
    else {
        int nx = x, ny = y;
        if (a[x][y] == 1) {
            ny++;
        }
        else {
            ny--;
        }
        a[x][y] = 2;
        int fx = _find(x, y);

            int fx1 = _find(x + 1, y);
            fa[fx][y] = fx1;

        go (nx, ny);
    }
}

int main()
{
    scanf ("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            fa[i][j] = i;
            scanf ("%d", &a[i][j]);
        }
    for (int j = 1; j <= m; j++) {
        fa[n + 1][j] = n + 1;
        a[n + 1][j] = 2;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 2) {
                int fi = _find(fa[i][j], j);
                int fi1 = _find(fa[i + 1][j], j);
                fa[fi][j] = fi1;
            }
        }
    for (int i = 1; i <= k; i++) {
        int sx = 1, sy;
        scanf ("%d", &sy);
        go (sx, sy);
        printf ("%d%c", ans, i == k ? '\n' : ' ');
    }
    return 0;
}