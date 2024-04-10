#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    scanf("%d", &n);

    int ax, ay, bx, by, cx, cy;
    scanf("%d %d %d %d %d %d", &ax, &ay, &bx, &by, &cx, &cy);

    int x, y;
    if (ax == bx || ax == cx) {
        x = ax;
    } else {
        x = bx;
    }

    if (ay == by || ay == cy) {
        y = ay;
    } else {
        y = by;
    }

    int gx, gy;
    scanf("%d %d", &gx, &gy);

    if ((x == 1 || x == n) && (y == 1 || y == n)) {
        puts((gx == x || gy == y) ? "YES" : "NO");
        return;
    }

    if (gx % 2 == x % 2 || gy % 2 == y % 2) {
        puts("YES");
    } else {
        puts("NO");
    }
}

int main()
{
    int cases = 1;
    scanf("%d", &cases);

    while (cases--) {
        solve();
    }

    return 0;
}