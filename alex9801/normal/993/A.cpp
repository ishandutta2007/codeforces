#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>
#include <iterator>

using namespace std;

bool chk[220][220];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int x1, x2, y1, y2, i, j;

    x1 = y1 = 110;
    x2 = y2 = -110;
    for(i = 0; i < 4; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        x1 = min(x1, x);
        x2 = max(x2, x);
        y1 = min(y1, y);
        y2 = max(y2, y);
    }

    for(i = x1; i <= x2; i++)
        for(j = y1; j <= y2; j++)
            chk[i + 100][j + 100] = 1;

    x1 = y1 = 110;
    x2 = y2 = -110;
    for(i = 0; i < 4; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        x1 = min(x1, x);
        x2 = max(x2, x);
        y1 = min(y1, y);
        y2 = max(y2, y);
    }

    int p = (x1 + x2) / 2;
    int q = (y1 + y2) / 2;
    int r = x2 - p;

    for(i = -100; i <= 100; i++)
    {
        for(j = -100; j <= 100; j++)
        {
            if(!chk[i + 100][j + 100])
                continue;

            if(abs(i - p) + abs(j - q) <= r)
            {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");
    return 0;
}