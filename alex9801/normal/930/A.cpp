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

int arr[100010];
int dep[100010];
int cnt[100010];

int f(int x)
{
    if(dep[x])
        return dep[x];
    return f(arr[x]) + 1;
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, i;
    scanf("%d", &n);
    for(i = 2; i <= n; i++)
        scanf("%d", &arr[i]);

    dep[1] = 1;
    for(i = 2; i <= n; i++)
        dep[i] = f(i);

    for(i = 1; i <= n; i++)
        cnt[dep[i]]++;

    int r = 0;
    for(i = 1; i <= n; i++)
        if(cnt[i] % 2 == 1)
            r++;

    printf("%d", r);

    return 0;
}