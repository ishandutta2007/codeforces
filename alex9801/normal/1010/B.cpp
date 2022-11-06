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

int mem[100];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int m, n, t, i;
    scanf("%d%d", &m, &n);

    for(i = 0; i < n; i++)
    {
        printf("1\n");
        fflush(stdout);

        scanf("%d", &t);
        if(t == 0 || t == -2)
            return 0;

        if(t == 1)
            mem[i] = 1;
        else
            mem[i] = 0;
    }

    int s = 1;
    int g = m;
    for(i = 0;; i++)
    {
        int x = (s + g) / 2;
        printf("%d\n", x);
        fflush(stdout);

        scanf("%d", &t);
        if(t == 0 || t == -2)
            return 0;

        if(mem[i % n] == 0)
            t = -t;

        if(t == 1)
            s = x + 1;
        else
            g = x - 1;
    }
    return 0;
}