#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cctype>
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
#include <cmath>

using namespace std;

char buf[100];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, i;
    scanf("%d", &n);

    int s = 1;
    int g = 999999999;
    int x = 100, y = 100;
    bool b = 0;
    for(i = 1; i <= n; i++)
    {
        if(i == n)
        {
            printf("%d %d\n", x, y - 2);
            fflush(stdout);

            scanf("%s", buf);
            bool b2 = buf[0] == 'b';

            int x1, y1, x2, y2;
            if(b && b2)
            {
                x1 = x;
                y1 = y - 3;
                x2 = x + 1;
                y2 = y + 1;
            }
            else if(b && !b2)
            {
                x1 = x;
                y1 = y - 1;
                x2 = x + 1;
                y2 = y + 1;
            }
            else if(!b && b2)
            {
                x1 = x;
                y1 = y - 1;
                x2 = x - 1;
                y2 = y + 1;
            }
            else
            {
                x1 = x;
                y1 = y - 3;
                x2 = x - 1;
                y2 = y + 1;
            }

            printf("%d %d %d %d\n", x1, y1, x2, y2);
            fflush(stdout);
            return 0;
        }

        x = (s + g) / 2;
        y = 100;

        printf("%d %d\n", x, y);
        fflush(stdout);

        scanf("%s", buf);
        b = buf[0] == 'b';

        if(b)
        {
            s = x + 1;
        }
        else
        {
            g = x - 1;
        }
    }

    return 0;
}