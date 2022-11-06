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

int a[1010];
int b[1010];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, m, i;
    scanf("%d%d", &n, &m);
    for(i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for(i = 1; i <= n; i++)
        scanf("%d", &b[i]);

    for(i = 1; i <= n; i++)
    {
        if(a[i] == 1 || b[i] == 1)
        {
            printf("-1\n");
            return 0;
        }
    }

    a[n + 1] = a[1];
    b[n + 1] = b[1];

    double s = 0;
    double g = 1e9;
    for(int bb = 0; bb < 1000; bb++)
    {
        double x = (s + g) / 2;
        double t = x;

        for(i = 1; i <= n; i++)
        {
            t -= (m + t) / a[i];
            if(t < 0)
                break;
            t -= (m + t) / b[i + 1];
            if(t < 0)
                break;
        }

        if(t < 0)
            s = x;
        else
            g = x;
    }

    printf("%.10lf\n", (s + g) / 2);
    return 0;
}