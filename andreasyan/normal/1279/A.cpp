#include <bits/stdc++.h>
using namespace std;

bool stg()
{
    int r, g, b;
    scanf("%d%d%d", &r, &g, &b);
    if (r > g + b + 1)
        return false;
    if (g > r + b + 1)
        return false;
    if (b > r + g + 1)
        return false;
    return true;
}

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        if (stg())
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}