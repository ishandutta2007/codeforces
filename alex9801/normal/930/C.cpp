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

int tmp[100010];
int arr[100010];
int mem1[100010];
int mem2[100010];

int idx1[525000];
int idx2[525000];
int bp;

int m;

void add(int idx[], int x, int v)
{
    x += bp;
    while(x)
    {
        idx[x] = max(idx[x], v);
        x /= 2;
    }
}

int ran(int idx[], int x, int y)
{
    x += bp;
    y += bp;
    int r = 0;
    while(x < y)
    {
        if(x % 2 == 1)
            r = max(r, idx[x++]);
        if(y % 2 == 0)
            r = max(r, idx[y--]);
        x /= 2;
        y /= 2;
    }
    if(x == y)
        r = max(r, idx[x]);
    return r;
}

void calc(int mem[], int idx[])
{
    int i;
    for(i = 1; i <= m; i++)
    {
        mem[i] = 1 + ran(idx, 0, arr[i]);
        add(idx, arr[i], mem[i]);
    }
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, i;
    scanf("%d%d", &n, &m);

    for(i = 0; i < n; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        tmp[x]++;
        tmp[y + 1]--;
    }

    for(i = 1; i <= m; i++)
        arr[i] = arr[i - 1] + tmp[i];

    for(bp = 1; bp <= m + 1; bp *= 2);

    calc(mem1, idx1);
    reverse(arr + 1, arr + m + 1);
    calc(mem2, idx2);

    int res = 0;
    for(i = 1; i <= m; i++)
        res = max(res, mem1[i] + mem2[m + 1 - i] - 1);
    printf("%d", res);
    return 0;
}