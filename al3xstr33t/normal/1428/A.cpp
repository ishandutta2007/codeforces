#include<bits/stdc++.h>

using namespace std;

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

int tests;
scanf ("%d", &tests);
while (tests --)
{
    int x1, y1, x2, y2;
    scanf ("%d %d %d %d", &x1, &y1, &x2, &y2);
    int dx = x1 - x2, dy = y1 - y2;
    if (dx < 0) dx = -dx;
    if (dy < 0) dy = -dy;
    if (dx == 0 && dy == 0) printf ("0\n");
    else
    if (dx == 0 || dy == 0) printf ("%d\n", dx + dy);
    else printf ("%d\n", dx + dy + 2);
}

return 0;
}