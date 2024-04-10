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

int a[20][2];
int b[20][2];

bool chk[10];
int c1[20][10];
int c2[20][10];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, m, i, j, k, l;
    scanf("%d%d", &n, &m);
    for(i = 0; i < n; i++)
    {
        scanf("%d%d", &a[i][0], &a[i][1]);
        if(a[i][0] > a[i][1])
            swap(a[i][0], a[i][1]);
    }
    for(i = 0; i < m; i++)
    {
        scanf("%d%d", &b[i][0], &b[i][1]);
        if(b[i][0] > b[i][1])
            swap(b[i][0], b[i][1]);
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            int x = 0;
            for(k = 0; k < 2; k++)
            {
                for(l = 0; l < 2; l++)
                {
                    if(a[i][k] == b[j][l])
                    {
                        if(x == 0)
                            x = a[i][k];
                        else
                            x = -1;
                    }
                }
            }
            if(x <= 0)
                continue;

            chk[x] = 1;

            c1[i][x] = 1;
            c2[j][x] = 1;
        }
    }

    int x = 0;
    for(i = 1; i <= 9; i++)
    {
        if(chk[i])
        {
            if(x == 0)
                x = i;
            else
                x = -1;
        }
    }
    if(x > 0)
    {
        printf("%d\n", x);
        return 0;
    }

    for(i = 0; i < n; i++)
    {
        int cnt = 0;
        for(j = 1; j <= 9; j++)
            if(c1[i][j])
                cnt++;

        if(cnt >= 2)
        {
            printf("-1\n");
            return 0;
        }
    }

    for(i = 0; i < m; i++)
    {
        int cnt = 0;
        for(j = 1; j <= 9; j++)
            if(c2[i][j])
                cnt++;

        if(cnt >= 2)
        {
            printf("-1\n");
            return 0;
        }
    }

    printf("0\n");
    return 0;
}