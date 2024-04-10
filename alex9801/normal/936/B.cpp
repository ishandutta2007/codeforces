#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>

using namespace std;

vector<int> arr[100010];
int fro[100010][2];
int deg[100010];

int f(int x, int t)
{
    if(t == 1 && arr[x].size() == 0)
        return x;

    for(int &y : arr[x])
    {
        if(fro[y][1 - t])
            continue;

        fro[y][1 - t] = x;
        int r = f(y, 1 - t);
        if(r)
            return r;
    }

    return 0;
}

bool vit[100010];
bool fin[100010];
bool dfs(int x)
{
    vit[x] = 1;

    for(int &y : arr[x])
    {
        if(vit[y])
        {
            if(!fin[y])
                return 1;
        }
        else
        {
            if(dfs(y))
                return 1;
        }
    }

    fin[x] = 1;

    return 0;
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, m, s, i, j;
    scanf("%d%d", &n, &m);
    for(i = 1; i <= n; i++)
    {
        int c;
        scanf("%d", &c);
        for(j = 0; j < c; j++)
        {
            int x;
            scanf("%d", &x);
            arr[i].push_back(x);
        }
    }
    scanf("%d", &s);

    fro[s][0] = -1;

    int r = f(s, 0);
    if(r)
    {
        vector<int> res;
        int t = 1;
        while(r != -1)
        {
            res.push_back(r);
            r = fro[r][t];
            t = 1 - t;
        }

        reverse(res.begin(), res.end());

        printf("Win\n");
        for(int &x : res)
            printf("%d ", x);
        return 0;
    }

    if(dfs(s))
        printf("Draw\n");
    else
        printf("Lose\n");

    return 0;
}