#include <bits/stdc++.h>
using namespace std;

int x1, y1, x2, y2;
int x3, y3, x4, y4;
int x5, y5, x6, y6;

bool stg(double x, double y)
{
    if (x3 <= x && x <= x4 && y3 <= y && y <= y4)
        return false;
    if (x5 <= x && x <= x6 && y5 <= y && y <= y6)
        return false;
    return true;
}

int main()
{
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    scanf("%d%d%d%d", &x3, &y3, &x4, &y4);
    scanf("%d%d%d%d", &x5, &y5, &x6, &y6);
    for (double x = x1; x <= x2; x += 0.5)
    {
        if (stg(x, y1) || stg(x, y2))
        {
            printf("YES\n");
            return 0;
        }
    }
    for (double y = y1; y <= y2; y += 0.5)
    {
        if (stg(x1, y) || stg(x2, y))
        {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO");
    return 0;
}