#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n, qq;
bool c[2][N];

int q;

int main()
{
    scanf("%d%d", &n, &qq);
    while (qq--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        --x;
        if (c[x][y] && c[(x ^ 1)][y])
            --q;
        if (c[x][y] && c[(x ^ 1)][y - 1])
            --q;
        if (c[x][y] && c[(x ^ 1)][y + 1])
            --q;
        c[x][y] ^= true;
        if (c[x][y] && c[(x ^ 1)][y])
            ++q;
        if (c[x][y] && c[(x ^ 1)][y - 1])
            ++q;
        if (c[x][y] && c[(x ^ 1)][y + 1])
            ++q;
        if (q == 0)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}