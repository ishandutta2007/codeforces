#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
const int xx[4] = {1, 0, -1, 0};
const int yy[4] = {0, 1, 0, -1};
int u[4];

int n, sx, sy;
int x[N], y[N];

int dist(int x1, int y1, int x2, int y2)
{
    return abs(x1 - x2) + abs(y1 - y2);
}

int main()
{
    scanf("%d%d%d", &n, &sx, &sy);
    for (int i = 0; i < n; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        for (int k = 0; k < 4; ++k)
        {
            if (dist(sx, sy, x, y) == 1 + dist(sx + xx[k], sy + yy[k], x, y))
                ++u[k];
        }
    }
    int ans = 0;
    for (int i = 0; i < 4; ++i)
        ans = max(ans, u[i]);
    printf("%d\n", ans);
    for (int i = 0; i < 4; ++i)
    {
        if (u[i] == ans)
        {
            printf("%d %d\n", sx + xx[i], sy + yy[i]);
            return 0;
        }
    }
    return 0;
}