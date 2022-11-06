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

char typ[1000010];
int chi[1000010][2];
int val[1000010];
int rev[1000010];

void f(int x)
{
    if(typ[x] == 'A' || typ[x] == 'O' || typ[x] == 'X')
    {
        int p = chi[x][0];
        int q = chi[x][1];
        f(p);
        f(q);
        if(typ[x] == 'A')
            val[x] = val[p] & val[q];
        if(typ[x] == 'O')
            val[x] = val[p] | val[q];
        if(typ[x] == 'X')
            val[x] = val[p] ^ val[q];
    }
    else if(typ[x] == 'N')
    {
        int p = chi[x][0];
        f(p);
        val[x] = !val[p];
    }
}

void g(int x)
{
    if(typ[x] == 'A' || typ[x] == 'O' || typ[x] == 'X')
    {
        int p = chi[x][0];
        int q = chi[x][1];

        if(typ[x] == 'A')
        {
            if(val[x])
                rev[p] = rev[q] = rev[x];
            else if(val[p])
            {
                rev[p] = val[1];
                rev[q] = rev[x];
            }
            else if(val[q])
            {
                rev[q] = val[1];
                rev[p] = rev[x];
            }
            else
                rev[p] = rev[q] = val[1];
        }
        if(typ[x] == 'O')
        {
            if(!val[x])
                rev[p] = rev[q] = rev[x];
            else if(!val[p])
            {
                rev[p] = val[1];
                rev[q] = rev[x];
            }
            else if(!val[q])
            {
                rev[q] = val[1];
                rev[p] = rev[x];
            }
            else
                rev[p] = rev[q] = val[1];
        }
        if(typ[x] == 'X')
        {
            rev[p] = rev[q] = rev[x];
        }

        g(p);
        g(q);
    }
    else if(typ[x] == 'N')
    {
        int p = chi[x][0];
        rev[p] = rev[x];
        g(p);
    }
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, i;
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
    {
        scanf(" %c%*s", &typ[i]);
        if(typ[i] == 'A' || typ[i] == 'O' || typ[i] == 'X')
            scanf("%d%d", &chi[i][0], &chi[i][1]);
        else if(typ[i] == 'N')
            scanf("%d", &chi[i][0]);
        else
            scanf("%d", &val[i]);
    }

    f(1);

    rev[1] = !val[1];
    g(1);

    for(i = 1; i <= n; i++)
        if(typ[i] == 'I')
            printf("%d", rev[i]);

    return 0;
}